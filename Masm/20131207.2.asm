DATAS SEGMENT
    ;�˴��������ݶδ���
   A DB 'KAShhHGs'
   B DB 'JHdnnjJL'
   CRLF DB 0AH,0DH,'$'
DATAS ENDS

STACKS SEGMENT
    ;�˴������ջ�δ���
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    MOV AX,DATAS
    MOV DS,AX
    ;�˴��������δ���,����ĸȫ��ת��Ϊ��д
    MOV SI,0
    MOV CX,8
 S1:MOV DL,[SI]
  	AND DL,223
  	MOV [SI],DL
  	MOV AH,02H
  	INT 21H
  	INC SI
  	LOOP S1
  	
  	
  	;CRLF
  	MOV DX,OFFSET CRLF
  	MOV AH,09H
  	INT 21H
  	
  	;����ĸȫ��ת��ΪСд
  	MOV SI,0
  	MOV CX,8
 S2:MOV DL,0
 	MOV DL,[SI+8]
 	OR DL,32
 	MOV [SI],DL
 	INC SI
 	MOV AH,02H
 	INT 21H
 	LOOP S2	
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START






