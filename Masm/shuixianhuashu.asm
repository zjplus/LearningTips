DATAS SEGMENT
    ;�˴��������ݶδ���
    NUM DW 4 DUP(0)
    SPACE DB 0,'$'
DATAS ENDS

STACKS SEGMENT
    ;�˴������ջ�δ���
    DB 8 DUP(0)
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS  
START:
    MOV AX,DATAS
    MOV DS,AX
    ;�˴��������δ���
    MOV DX,100
    MOV CX,899
AGAIN:
;<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
;��λ��ʮλ����λ���δ����NUM��
	PUSH DX			;����ֵ����ջ�б���
	
	MOV AX,DX
	MOV DX,0
	MOV BX,100
	DIV BX			;����1��DX�У���1��AX��
	MOV DS:[0],AX
	
	MOV AX,DX
	MOV DX,0
	MOV BX,10
	DIV BX			;����2��DX�У���2��AX��
	MOV DS:[2],AX
	MOV DS:[4],DX	
;<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
;����������������
	MOV AX,DS:[0]
	MOV BX,AX
	MUL BX
	MUL BX
	MOV DS:[6],AX			;��λ��������DS:[6]��
	
	MOV AX,DS:[2]
	MOV BX,AX
	MUL BX
	MUL BX
	ADD DS:[6],AX			;ʮλ�����ۼӵ�DS:[6]��
	
	MOV AX,DS:[4]
	MOV BX,AX
	MUL BX
	MUL BX
	ADD DS:[6],AX			;��λ�����ۼӵ�DS:[6]��
;<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
;�Ƚ�ax�е�����COUNT����������������������
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
	
S:	MOV DL,DS:[0]			;�������
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
	
	MOV DX,OFFSET SPACE		;������
	MOV AH,09H
	INT 21H
	JMP R
T:
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START
