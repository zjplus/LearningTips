DATAS SEGMENT
    ;�˴��������ݶδ���
    A DB ?
    B DB ?
    C DB ?  
    D DB 0
DATAS ENDS

STACKS SEGMENT
    ;�˴������ջ�δ���
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    MOV AX,DATAS
    MOV DS,AX
    ;�˴��������δ���
    MOV DL,0
    MOV CX,3
	MOV BX,0
S:  MOV AL,[BX]
    CMP AL,0
    JZ OVER
    ADD DL,AL
    INC BX
    LOOP S
    MOV DS:[3],DL
OVER:
	MOV DS:[0],0
	MOV DS:[1],0
	MOV DS:[2],0
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START

