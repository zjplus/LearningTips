DATA SEGMENT
CAR DB    7 ;字符图形表
 DB  52H,10,0,0
 DB  0B1H,10,0,1
 DB  0DBH,10,0,1
 DB  0DBH,10,0,1
 DB  4FH, 7,1,0
 DB  4FH, 7,0,-3
 DB 2,7,-2,1
CHAR_CNT DW  ?
POINTER DW ?
LINE_ON DB  ?
COL_ON  DB ?
DATA ENDS
stack segment stack
db 100 dup (?)
stack ends

CODE SEGMENT 'code'
 ASSUME CS:CODE,DS:DATA
MAIN PROC FAR 
PUSH  DS
SUB AX,AX
PUSH AX
MOV AX,DATA ;初始化DS
 MOV DS,AX
 MOV AH,0 ;设置300×200彩色图形方式
 MOV AL,4 
 INT  10H
 MOV AH,0BH ;设置背景颜色
 MOV BH,0 
 MOV  BL,2
 INT 10H
 MOV AH,0BH ;设置彩色调板
 MOV BH,01 
 MOV  BL,00
 INT 10H
 ;CALL CLEAR_SCREEN ;清屏
    LEA DI,CAR ;DI指向字符图形表
 MOV DH,1 ;从第5行5列位置开始
 MOV DL,1 ;显示汽车
he: CALL MOVE_SHAPE
 jmp he
 RET 
 MAIN ENDP
; 
CLEAR_SCREEN PROC NEAR
 PUSH AX ;寄存器
 PUSH BX
 PUSH CX
 PUSH DX
 MOV AH,6 ;屏幕上卷功能
 MOV AL,0
 MOV CH,0 ;左上角行号
 MOV CL,0 ;左上角列号
 MOV DH,24 ;右下角行号
 MOV DL,79 ;右下角列号
 MOV BH,7 ;卷入行属性
 INT 10H ;调用显示属性
 POP DX ;恢复寄存器
 POP CX
 POP BX
 POP AX
 RET ;返回主程序
CLEAR_SCREEN ENDP
; 
MOVE_SHAPE PROC NEAR
 PUSH AX ;寄存器
 PUSH BX 
 PUSH CX
 PUSH DX 
  PUSH DI
 MOV AH,0FH ;取当前显示方式
 INT 10H
 SUB CH,CH ;清除计数器CX的高字节
 MOV CL,[DI] ;CL放循环次数
 INC DI ;DI指向字符图形表中的第一个字符
 MOV CHAR_CNT,CX ;保存循环次数
 MOV POINTER,DI    
 MOV LINE_ON,DH
 MOV COL_ON,DL
 PLOT_NEXT:
 ADD DH,[DI+2] ;改变行列指针
 ADD DL,[DI+3]
 CMP DL,80 ;出屏否？
 JB MOV_CRSR
 CALL ERASE
 POP  DI 
 POP DX
 POP CX 
 POP BX
 POP AX 
 RET
 MOV_CRSR:
 MOV AH,2 ;移动光标位置
 INT 10H
 MOV AL, [DI]
 MOV BL,[DI+1] ;取字符值及属性
 PUSH CX 
 MOV  CX,1
 MOV AH,09 ;显示字符
 INT 10H 
 POP CX
 ADD DI,4 ;DI指向下一个字符
 LOOP PLOT_NEXT
 CALL DLY_QRTR ;调用延时子程序
 CALL ERASE ;调用擦除子程序
 JMP SHORT PLOT_NEXT
MOVE_SHAPE ENDP
;
ERASE PROC NEAR
 MOV CX,CHAR_CNT
 MOV DI,POINTER
 MOV DH,LINE_ON
 MOV DL,COL_ON
ERASE_NEXT:
 ADD DH,[DI+2] 
 ADD DL,[DI+3]
 MOV AH,2 
 INT 10H
 MOV AL,[DI] 
 MOV BL,0
 PUSH CX 
 MOV CX,1
 MOV AH,9 
 INT 10H
 POP CX 
 ADD DI,4
 LOOP ERASE_NEXT
 MOV CX,CHAR_CNT
 MOV DI,POINTER
; inc LINE_ON
 MOV DH,LINE_ON
 INC COL_ON
 MOV DL,COL_ON
 RET
ERASE ENDP
DLY_QRTR PROC NEAR ;延时子程序
 	PUSH CX
    PUSH DX
 MOV DX,2000
D11: 
 MOV CX,2801
D12:LOOP D12 
 DEC DX
 JNZ D11 
 POP DX
 POP CX 
 RET
DLY_QRTR ENDP
CODE ENDS
 END MAIN

