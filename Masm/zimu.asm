DATAS SEGMENT
    ;�˴��������ݶδ���
    CHAR DB 20 DUP(0),'$'
    CHARS DB 20 DUP(0),'$'
    COUNT DB 20 DUP(0),'$'
    CRLF DB 0AH,0DH,'$'
    SPACE DB 0,'$'
    SHURU DB 'Please input 20 char:$'
DATAS ENDS

STACKS SEGMENT
	DB 8 DUP(0)
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    MOV AX,DATAS
    MOV DS,AX
    
    MOV DX,OFFSET SHURU
	MOV AH,09H
	INT 21H
;<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
;�����ַ�����char��
    MOV BX,0
	MOV CX,20
INPUT:
	MOV AH,01H
	INT 21H
	MOV CHAR[BX],AL
	INC BX
	LOOP INPUT
;<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
;��ѭ������ȡ��CHAR�����ĸ����0�Ƚ�
	MOV BX,0
	MOV DI,0
	MOV COUNT[0],1
	MOV CX,20
WAI:PUSH CX
	MOV AX,0
	CMP CHAR[BX],AL
	JZ	NEXT			;��0������һ��ѭ��
	MOV AL,CHAR[BX]		;��CHAR[BX]����AL��
	MOV SI,1
	MOV CX,20
NEI:					;����0�����Լ����µ���ĸ�Ƚ�
	MOV DL,[BX+SI]
	MOV CHARS[DI],AL
	CMP AL,DL
	JNZ L				;����ȣ�����һ����ĸ�Ƚ�			
						
	MOV CHAR[BX+SI],0	;��ȣ��é������Ҽ���DH��һ
	;INC DH
	INC COUNT[DI]
L:	INC SI
	LOOP NEI
	INC DI	
NEXT:
	INC BX
	POP CX
	LOOP WAI
	
	MOV DX,OFFSET CRLF
	MOV AH,09H
	INT 21H
;<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
;��COUNT���ֵһ����987654321�Ƚ�
;����ȵĵ����COUNT[SI]��CHAR[SI]
	MOV BL,10	
	MOV CX,10
R:	PUSH CX
	MOV SI,0
	MOV CX,10
S:	CMP BL,COUNT[SI]
	JNZ NEXT1
	MOV DL,COUNT[SI]	;�������
	ADD DL,30H
	MOV AH,02H
	INT 21H
	
	MOV DX,OFFSET SPACE
	MOV AH,09H
	INT 21H
	
	MOV DL,CHARS[SI]	;�����ĸ
	MOV AH,02H
	INT 21H
	MOV DX,OFFSET CRLF
	MOV AH,09H
	INT 21H
NEXT1:
	INC SI
	LOOP S
	POP CX
	DEC BL
	LOOP R
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START

