DATAS SEGMENT
    ;�˴��������ݶδ���  
    CAR DB 22,22,22,22,22,22,22,0AH,0DH,'$'
    CAR1 DB 

DATAS ENDS

STACKS SEGMENT
   DB 8 DUP(0) ;�˴������ջ�δ���
STACKS ENDS

CODES SEGMENT
;MAIN PROC FAR
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    MOV AX,DATAS
    MOV DS,AX
    ;�˴��������δ���
;<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
;��ʾ�ַ�����λ��
	MOV AL,0
	MOV BL,0
	MOV CX,22
LOOPS:
	PUSH AX
	PUSH BX
	MOV DH,AL		;��*��
	MOV DL,BL		;��*��
	
	MOV BH,0		;��*ҳ
	MOV AH,2		;INT 10H��2�Ź������ù��λ��
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


