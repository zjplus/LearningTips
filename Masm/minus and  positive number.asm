DATAS  SEGMENT;���ݶ�
     STRING1  DB  'Please input a number:','$'
     STRING2  DB  'The number of negative numbers is:','$'
     STRING3  DB  'The sum of positive numbers is:','$'
     COUNT DB 0;��¼��������
     SUM DB 0;��¼����������
     CRLF DB 0AH,0DH,'$'
DATAS  ENDS

STACKS SEGMENT
STACKS ENDS

CODES  SEGMENT
     ASSUME    CS:CODES, DS:DATAS, SS:STACKS
START:
     MOV  AX,DATAS
     MOV  DS,AX
     
     ;ѭ��ʮ������
     MOV CX,10
LOOPS:
     MOV  DX,OFFSET STRING1
     MOV  AH,09H
     INT  21H
     JMP  INPUT
ADDCOUNT:;���븺��ת�����ʹCOUNT+1��������һ����
     INC  COUNT
     MOV  AH,01H
     INT  21H
     MOV  DX,OFFSET CRLF
     MOV  AH,09H
     INT  21H
     DEC  CX
     CMP  CX,0
     JZ   ENDINPUT
     JMP  LOOPS
INPUT: 
     ;�����ַ�  
     MOV  AH,01H
     INT  21H
     CMP  AL,2DH;��������Ƿ�Ϊ����
	 JZ   ADDCOUNT;������ת��ADDCOUNT
	 
	 SUB  AL,30H
	 ADD  SUM,AL
     MOV  DX,OFFSET CRLF
     MOV  AH,09H
     INT  21H
    LOOP LOOPS
ENDINPUT:    
     ;��ʾ��������
     MOV  DX,OFFSET STRING2
     MOV  AH,09H
     INT  21H
     MOV  DL,COUNT
     ADD  DL,30H
     MOV  AH,02H
     INT  21H
     MOV  DX,OFFSET CRLF
     MOV  AH,09H
     INT  21H
     
     ;��ʾ����֮��
     MOV  DX,OFFSET STRING3
     MOV  AH,09H
     INT  21H
     CMP  SUM,10
     JS   DIS1;���SUMС��10��ת��DIS1
     
     ;���Ϊ��λ������ʾ
     MOV  AL,SUM
     MOV  AH,0
     MOV  BL,10
     DIV  BL;sum����10������Ϊ��λ����AH����Ϊʮλ����AL
     MOV  BH,AH;�����浽BH
     
     MOV  DL,AL;���ʮλ��
     ADD  DL,30H
     MOV  AH,02H
     INT  21H
     MOV  DL,BH;�����λ��
     ADD  DL,30H
     MOV  AH,02H
     INT  21H
     
     JMP OVER
DIS1:;���Ϊһλ������ʾ      
     MOV  DL,SUM
     ADD  DL,30H
     MOV  AH,02H
     INT  21H
OVER:
     MOV  AH,4CH
     INT  21H
CODES  ENDS
    END   START
