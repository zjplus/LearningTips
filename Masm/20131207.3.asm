DATAS SEGMENT
    ;�˴��������ݶδ��� 
	ARRAY1 DB'ibm             ','$'
	ARRAY2 DB'dec             ','$'
	ARRAY3 DB'dos             ','$'
	ARRAY4 DB'dog             ','$'
DATAS ENDS

STACKS SEGMENT
    ;�˴������ջ�δ���;��Сд��ĸת���ɴ�д��ĸ
    DW 8 DUP(0)
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    MOV AX,DATAS
    MOV DS,AX
    ;�˴��������δ���
    MOV BX,0
    
    MOV CX,4
R:	PUSH CX     ;��CXѹ���ջ
    MOV SI,0
    MOV CX,3
S:
    MOV AL,[BX+SI]
    AND AL,223
    MOV [BX+SI],AL
    INC SI
    LOOP S
    
    ADD BX,17
    POP CX    ;ȡ��CX
    LOOP R
    
    MOV DX,OFFSET ARRAY2
    MOV AH,09H
    INT 21H
    
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START
