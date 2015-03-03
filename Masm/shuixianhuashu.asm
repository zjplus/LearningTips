DATAS SEGMENT
    ;此处输入数据段代码
    NUM DW 4 DUP(0)
    SPACE DB 0,'$'
DATAS ENDS

STACKS SEGMENT
    ;此处输入堆栈段代码
    DB 8 DUP(0)
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS  
START:
    MOV AX,DATAS
    MOV DS,AX
    ;此处输入代码段代码
    MOV DX,100
    MOV CX,899
AGAIN:
;<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
;百位，十位，个位依次存放在NUM中
	PUSH DX			;把数值放在栈中保存
	
	MOV AX,DX
	MOV DX,0
	MOV BX,100
	DIV BX			;余数1在DX中，商1在AX中
	MOV DS:[0],AX
	
	MOV AX,DX
	MOV DX,0
	MOV BX,10
	DIV BX			;余数2在DX中，商2在AX中
	MOV DS:[2],AX
	MOV DS:[4],DX	
;<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
;求三个数的立方和
	MOV AX,DS:[0]
	MOV BX,AX
	MUL BX
	MUL BX
	MOV DS:[6],AX			;百位立方放入DS:[6]中
	
	MOV AX,DS:[2]
	MOV BX,AX
	MUL BX
	MUL BX
	ADD DS:[6],AX			;十位立方累加到DS:[6]中
	
	MOV AX,DS:[4]
	MOV BX,AX
	MUL BX
	MUL BX
	ADD DS:[6],AX			;个位立方累加到DS:[6]中
;<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
;比较ax中的数和COUNT里的数，并且输出相等情况下
	MOV BX,DS:[6]
	POP AX
	MOV DX,AX
	PUSH DX
	CMP AX,BX
	JZ S
R:	POP DX
	INC DX
	CMP CX,1
	JZ T
	LOOP AGAIN
	
S:	MOV DL,DS:[0]			;输出数字
	ADD DL,30H
	MOV AH,02H
	INT 21H
	MOV DL,DS:[2]
	ADD DL,30H
	MOV AH,02H
	INT 21H
	MOV DL,DS:[4]
	ADD DL,30H
	MOV AH,02H
	INT 21H
	
	MOV DX,OFFSET SPACE		;输出间隔
	MOV AH,09H
	INT 21H
	JMP R
T:
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START
