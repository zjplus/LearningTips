DATAS SEGMENT
    ;此处输入数据段代码  
    CAR DB 22,22,22,22,22,22,22,0AH,0DH,'$'
    CAR1 DB 

DATAS ENDS

STACKS SEGMENT
   DB 8 DUP(0) ;此处输入堆栈段代码
STACKS ENDS

CODES SEGMENT
;MAIN PROC FAR
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    MOV AX,DATAS
    MOV DS,AX
    ;此处输入代码段代码
;<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
;显示字符串的位置
	MOV AL,0
	MOV BL,0
	MOV CX,22
LOOPS:
	PUSH AX
	PUSH BX
	MOV DH,AL		;第*行
	MOV DL,BL		;第*列
	
	MOV BH,0		;第*页
	MOV AH,2		;INT 10H的2号功能设置光标位置
	INT 10H
	
	MOV DX,OFFSET CAR
	MOV AH,09H
	INT 21H
	POP BX
	POP AX
	INC AL
	ADD BL,3
	LOOP LOOPS
	
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START


