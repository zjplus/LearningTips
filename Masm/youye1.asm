DATAS SEGMENT
    CHAR DB 20 DUP(0),'$'
    CHAR1 DB 20 DUP(0),'$'
    COUNT DB 20 DUP(0)
    STR0 DB 'Please input the string: ','$' 
    STR1 DB 'The order is: ','$' 
    CRLF DB 0DH,0AH,'$'
DATAS ENDS

STACKS SEGMENT
   
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    MOV AX,DATAS
    MOV DS,AX
    MOV AX,STACKS
    MOV SS,AX
    
    MOV DX,OFFSET STR0
    MOV AH,09H
    INT 21H
;-------------------------;�����ַ���    
    MOV CX,20
    MOV BX,0
INPUT:
	MOV AH,01H
	INT 21H
	MOV CHAR[BX],AL
	INC BX
	LOOP INPUT
;------------------------;���ַ�����ASCII��ֵ�Ӵ�С����	
	MOV CX,20
	DEC CX
LOOP1:
	MOV DI,CX
	MOV BX,0
LOOP2:
	MOV AL,CHAR[BX]
	CMP AL,CHAR[BX+1]
	JGE CONTINUE
	XCHG AL,CHAR[BX+1]
	MOV CHAR[BX],AL
CONTINUE:
	INC BX
	LOOP LOOP2
	MOV CX,DI
	LOOP LOOP1
;-----------------------;����������ַ���	
	MOV DX,OFFSET CRLF
    MOV AH,09H
    INT 21H
    MOV DX,OFFSET CHAR
    MOV AH,09H
    INT 21H
;-----------------------;ͳ�Ƴ��ֵ��ַ������ǳ��ֵĴ���    	
	MOV BX,0
	MOV CX,20
	MOV SI,0
	MOV AL,CHAR[BX]
	MOV CHAR1[SI],AL
	ADD COUNT[SI],1
LOOP3:
	MOV AL,CHAR[BX]
	CMP AL,CHAR[BX+1]
	JNZ L1
	ADD COUNT[SI],1
	INC BX
	DEC CX
	CMP CX,0
	JNZ LOOP3
	JMP L2	
L1:
	MOV AL,CHAR[BX+1]
	MOV CHAR1[SI+1],AL
	ADD COUNT[SI+1],1
	INC SI
	INC BX
	DEC CX
	CMP CX,0
	JNZ LOOP3
L2:
;-------------------------;���char1�����ͳ���Ƿ����
    MOV DX,OFFSET CRLF
    MOV AH,09H
    INT 21H
	MOV DX,OFFSET CHAR1
    MOV AH,09H
    INT 21H
;------------------------;����ÿ���ַ����ֵĴ�������Ƶ�ʴӸߵ�������	
	MOV CX,SI
	DEC CX
LOOP_1:
	MOV DI,CX
	MOV BX,0
LOOP_2:
	MOV AL,COUNT[BX]
	CMP AL,COUNT[BX+1]
	JA CONTINUE_1
	XCHG AL,COUNT[BX+1]
	MOV COUNT[BX],AL
CONTINUE_1:
	INC BX
	LOOP LOOP_2
	MOV CX,DI
	LOOP LOOP_1
;-------------------------;����������ַ��Լ���Ӧ�ĸ��Գ��ֵĴ���	
	MOV DX,OFFSET CRLF
    MOV AH,09H
    INT 21H	
    
	MOV CX,SI
	MOV BX,0
L3:
	MOV DL,CHAR1[BX]
	MOV AH,02H
	INT 21H
	MOV DL,' '
	MOV AH,02H
	INT 21H
	MOV DL,COUNT[BX]
	CMP DL,10
	JBE L4
	MOV BH,10
	MOV AL,DL
	MOV AH,0
	DIV BH
	MOV DH,AL
	MOV DL,AH
	ADD DH,30H
	MOV AH,02H
	INT 21
L4:
	ADD DL,30H
	MOV AH,02H
	INT 21H
	MOV DL,';'
	MOV AH,02H
	INT 21H
	INC BX
	LOOP L3
;-------------------------------;�����������������	
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START


