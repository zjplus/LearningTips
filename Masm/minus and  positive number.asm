DATAS  SEGMENT;数据段
     STRING1  DB  'Please input a number:','$'
     STRING2  DB  'The number of negative numbers is:','$'
     STRING3  DB  'The sum of positive numbers is:','$'
     COUNT DB 0;记录负数个数
     SUM DB 0;记录输入正数和
     CRLF DB 0AH,0DH,'$'
DATAS  ENDS

STACKS SEGMENT
STACKS ENDS

CODES  SEGMENT
     ASSUME    CS:CODES, DS:DATAS, SS:STACKS
START:
     MOV  AX,DATAS
     MOV  DS,AX
     
     ;循环十次输入
     MOV CX,10
LOOPS:
     MOV  DX,OFFSET STRING1
     MOV  AH,09H
     INT  21H
     JMP  INPUT
ADDCOUNT:;输入负号转到这里，使COUNT+1，再输入一个数
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
     ;输入字符  
     MOV  AH,01H
     INT  21H
     CMP  AL,2DH;检测输入是否为负号
	 JZ   ADDCOUNT;符号则转到ADDCOUNT
	 
	 SUB  AL,30H
	 ADD  SUM,AL
     MOV  DX,OFFSET CRLF
     MOV  AH,09H
     INT  21H
    LOOP LOOPS
ENDINPUT:    
     ;显示负数个数
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
     
     ;显示正数之和
     MOV  DX,OFFSET STRING3
     MOV  AH,09H
     INT  21H
     CMP  SUM,10
     JS   DIS1;如果SUM小于10，转到DIS1
     
     ;结果为两位数的显示
     MOV  AL,SUM
     MOV  AH,0
     MOV  BL,10
     DIV  BL;sum除以10，余数为个位，在AH，商为十位，在AL
     MOV  BH,AH;余数存到BH
     
     MOV  DL,AL;输出十位数
     ADD  DL,30H
     MOV  AH,02H
     INT  21H
     MOV  DL,BH;输出个位数
     ADD  DL,30H
     MOV  AH,02H
     INT  21H
     
     JMP OVER
DIS1:;结果为一位数的显示      
     MOV  DL,SUM
     ADD  DL,30H
     MOV  AH,02H
     INT  21H
OVER:
     MOV  AH,4CH
     INT  21H
CODES  ENDS
    END   START
