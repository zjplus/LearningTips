DATAS SEGMENT
    ;�˴��������ݶδ���
    GRADE DB 10 DUP(0),'$'
    INPUT DB 'Please input 10 score<0 to 9>:$'
    CRLF DB 0AH,0DH,'$'
    OUTPUT1 DB 'The highest score is student$'
    OUTPUT2 DB 'The lowest score is student$'
    STUDENT1 DB 0,'$'
    STUDENT2 DB 0,'$'
    STUDENT3 DB 0,'$'
    STUDENT4 DB 0,'$'
    STUDENT5 DB 0,'$'
      
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
;<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

	MOV CX,5
LOOPS:
	PUSH CX
;��������ʮ��������GRADE��
	MOV DX,OFFSET INPUT
	MOV AH,09H
	INT 21H
	
	MOV AX,0
	MOV BX,0
	MOV CX,10
S:	MOV AH,01H
	INT 21H
	SUB AL,30H
	MOV [BX],AL
	INC BX
	LOOP S
;<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
;��ʮ����ð����������GRADE��
	MOV CX,10
S1: MOV DI,CX
	MOV CX,9
	MOV BX,0
S2:
	MOV AL,GRADE[BX]
	CMP AL,GRADE[BX+1]
	JGE CONTINUE
	XCHG AL,GRADE[BX+1]
	MOV GRADE[BX],AL
CONTINUE:
	INC BX
	LOOP S2
	MOV CX,DI
	LOOP S1
;<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
;����������ӵ�2���ӵ���7���ĺͷŽ�STUDENT��
	MOV AL,0
	MOV CX,6
HE: MOV SI,2
	ADD AL,GRADE[SI]
	INC SI 
	LOOP HE
	MOV BX,0
	POP CX
;<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
;�Ƚ�cx��ֵ�����η���student*��
	CMP CX,5
	JZ L1
	CMP CX,4
	JZ L2
	CMP CX,3
	JZ L3
	CMP CX,2
	JZ L4
	CMP CX,1
	JZ L5
L1:	MOV STUDENT1[BX],AL
	JMP NEXT
L2:	MOV STUDENT2[BX],AL
	JMP NEXT
L3:	MOV STUDENT3[BX],AL
	JMP NEXT
L4:	MOV STUDENT4[BX],AL
	JMP NEXT
L5:	MOV STUDENT5[BX],AL	
;<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
;���STUDENT*[BX]�������
NEXT:
	MOV AH,0
	MOV BL,10
	DIV BL			;��������AH�У�����AL��
	MOV BH,AH		;����ת��BH��
	
	MOV DX,OFFSET CRLF
	MOV AH,09H
	INT 21H
	
	MOV DL,AL		;���ʮλ
	ADD DL,30H
	MOV AH,02H
	INT 21H
	MOV DL,BH		;�����λ
	ADD DL,30H
	MOV AH,02H
	INT 21H
	
	MOV DX,OFFSET CRLF
	MOV AH,09H
	INT 21H
	
	DEC CX
	CMP CX,0
	JG LOOPS
;<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
;�Ƚ�������ֵ
	LEA BX,STUDENT1
	MOV DL,[BX]
	MOV SI,0
	MOV CX,4
MAX:CMP DL,[BX+SI+2]
	JNL P
	MOV DL,[BX+SI+2]
P:	
	ADD SI,2
	LOOP MAX
	MOV CX,4
	MOV SI,0
P1:	CMP DL,[BX+SI]
	JZ P2
	ADD SI,2
	LOOP P1	
P2:	MOV AH,0
	MOV AX,SI
	MOV BL,2
	DIV BL
	MOV DL,AL
	INC DL
	PUSH DX
	
	MOV DX,OFFSET OUTPUT1
	MOV AH,09H
	INT 21H
	POP DX
	ADD DL,30H
	MOV AH,02H
	INT 21H
	
;<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	MOV DX,OFFSET CRLF
	MOV AH,09H
	INT 21H
;�Ƚ������Сֵ
	LEA BX,STUDENT1
	MOV DL,[BX]
	MOV SI,0
	MOV CX,4
MIN:CMP DL,[BX+SI+2]
	JL Q
	MOV DL,[BX+SI+2]
Q:	
	ADD SI,2
	LOOP MIN
	
	MOV CX,4
	MOV SI,0
Q1:	CMP DL,[BX+SI]
	JZ Q2
	ADD SI,2
	LOOP Q1	
Q2:	MOV AH,0
	MOV AX,SI
	MOV BL,2
	DIV BL
	MOV DL,AL
	INC DL
	PUSH DX
	
	MOV DX,OFFSET OUTPUT2
	MOV AH,09H
	INT 21H
	POP DX
	ADD DL,30H
	MOV AH,02H
	INT 21H
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START
