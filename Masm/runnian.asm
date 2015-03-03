;==============================================
;程序如下：
;==============================================
DATA  SEGMENT          ;数据段.
  MSG1 DB  13, 10, 'Please Input : $'
  VAR1 DB  13, 10, 'THE YEAR IS LEAP!','$'
  VAR2 DB  13, 10, 'THE YEAR IS NOT LEAP!','$'
  MSG3 DB  13, 10, 'Input ERROR.  $'
     x DW ?        ;年份：0~65535
     B DW 4
     G DW 400
     F DW 100
DATA  ENDS
;----------------------------------------------
CODE   SEGMENT         ;代码段.
    ASSUME   CS: CODE, DS: DATA
START:
    MOV  AX, DATA
    MOV  DS, AX
;--------------------------------
    MOV  DX, OFFSET MSG1 ;提示 Please Input :
    MOV  AH, 9
    INT  21H
;--------------------------------
IN_LOOP:
    MOV  x,  0         ;数据清零.
    MOV  CX, 4         ;输入4位
_INX:
    PUSH CX
    MOV  AH, 1         ;输入单个字符.
    INT  21H
;--------------------------------
    CMP  AL, '0'
    JB   _IN_ERR       ;小于'0'，不是数字.
    CMP  AL, 3AH
    JB   SUB_30H       ;'0'~'9'.
;--------------------------------
_IN_ERR:               ;大于'9'，也不是数字.
    MOV  DX, OFFSET MSG3 ;提示 Input ERROR.
    MOV  AH, 9
    INT  21H
    JMP  EXIT          ;转到结束程序.