DATAS SEGMENT
    ;此处输入数据段代码
    CAR DB 0
    CAR1 DB '  O     O$'
DATAS ENDS

STACKS SEGMENT
    ;此处输入堆栈段代码
STACKS ENDS

CODES SEGMENT
	
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    MOV AX,DATAS
    MOV DS,AX
    ;此处输入代码段代码
;<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
B:		MOV DH,0		;行
		MOV DL,0		;列
		MOV BH,0
		MOV AH,02H
		INT 10H
;主程序体
MAIN 	PROC FAR
    	CALL SHOW
    	CALL DELAY
    	CALL ERASER
    	CALL MOVE
    	CMP DH,23
    	JZ S
    	JMP MAIN
s:		JMP B	
    	RET
MAIN 	ENDP
;<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
;显示子程序
SHOW 	PROC NEAR
;显示第一行
		PUSH DX
		MOV	AH,9
		MOV	AL,[SI]		;写入字符的ASCⅡ码
        MOV	BH,0		;页号
        MOV	BL,0DAH		;字符属性
        MOV	CX,9		;重复次数
        INT	10H
		POP DX
;显示第二行		
		PUSH DX
		ADD DH,1		;行
		MOV BH,0
		MOV AH,02H
		INT 10H
		MOV	AH,9
		MOV	AL,[SI]		;写入字符的ASCⅡ码
        MOV	BH,0		;页号
        MOV	BL,0DAH		;字符属性
        MOV	CX,10		;重复次数
        INT	10H
		POP DX
;显示第三行		
		PUSH DX
		ADD DH,2		;行
		MOV BH,0
		MOV AH,02H
		INT 10H
		MOV DX,OFFSET CAR1
		MOV AH,09H
		INT 21H
		POP DX
    	RET
SHOW	ENDP
;<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
;延迟子程序
DELAY	PROC NEAR
		PUSH CX
    	PUSH DX
 		MOV DX,500
D1: 	MOV CX,2000
D2:		LOOP D2 
		DEC DX
		JNZ D1 
		POP DX
		POP CX 
		RET
DELAY	ENDP
;<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
;擦除子程序
ERASER 	PROC NEAR
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
		RET
ERASER	ENDP
;<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
;移动子程序
MOVE 	PROC NEAR
		INC DH
		ADD DL,3
		MOV BH,0
		MOV AH,02H
		INT 10H
		RET
MOVE ENDP

CODES ENDS
    END START


