;==============================================
;�������£�
;==============================================
DATA  SEGMENT          ;���ݶ�.
  MSG1 DB  13, 10, 'Please Input : $'
  VAR1 DB  13, 10, 'THE YEAR IS LEAP!','$'
  VAR2 DB  13, 10, 'THE YEAR IS NOT LEAP!','$'
  MSG3 DB  13, 10, 'Input ERROR.  $'
     x DW ?        ;��ݣ�0~65535
     B DW 4
     G DW 400
     F DW 100
DATA  ENDS
;----------------------------------------------
CODE   SEGMENT         ;�����.
    ASSUME   CS: CODE, DS: DATA
START:
    MOV  AX, DATA
    MOV  DS, AX
;--------------------------------
    MOV  DX, OFFSET MSG1 ;��ʾ Please Input :
    MOV  AH, 9
    INT  21H
;--------------------------------
IN_LOOP:
    MOV  x,  0         ;��������.
    MOV  CX, 4         ;����4λ
_INX:
    PUSH CX
    MOV  AH, 1         ;���뵥���ַ�.
    INT  21H
;--------------------------------
    CMP  AL, '0'
    JB   _IN_ERR       ;С��'0'����������.
    CMP  AL, 3AH
    JB   SUB_30H       ;'0'~'9'.
;--------------------------------
_IN_ERR:               ;����'9'��Ҳ��������.
    MOV  DX, OFFSET MSG3 ;��ʾ Input ERROR.
    MOV  AH, 9
    INT  21H
    JMP  EXIT          ;ת����������.