DATAS SEGMENT
ARRAY DB 50 DUP(?)
    STR1 DB 'Please input the string: ','$'
    STR2 DB 'The count is: ','$'
    CRLF DB 0DH,0AH,'$' 
DATAS ENDS

STACKS SEGMENT
   
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    MOV AX,DATAS
    MOV DS,AX
;---------------------------;�����ַ���	
MOV DX,OFFSET STR1
MOV AH,09H
INT 21H

LEA DI,ARRAY
MOV DX,0
INPUT:
MOV AH,01H
INT 21H
MOV [DI],AL
INC DI
CMP AL,24H
JNE INPUT	

LEA DI,ARRAY
MOV DX,0
L1:
MOV AL,[DI]
INC DI
CMP AL,24H
JE OUTPUT
INC DX
CMP AL,30H
JBE L1
CMP AL,39H
JA L1
DEC DX
JMP L1
;------------------------------;�����ʾ

PUSH DX
OUTPUT:
MOV DX,OFFSET CRLF
MOV AH,09H
INT 21H
MOV DX,OFFSET STR2
MOV AH,09H
INT 21H

POP DX
MOV BX,DX
CMP DX,10
JNL NEXT
ADD DL,30H
MOV AH,02H
INT 21H	
JMP EXIT
NEXT:
MOV AX,BX
MOV BL,10
DIV BL;����AL�У�������AH��
PUSH AX
MOV DL,AL
ADD DL,30H
MOV AH,02H
INT 21H
POP AX
MOV DL,AH
ADD DL,30H
MOV AH,02H
INT 21H	
EXIT:	
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START
