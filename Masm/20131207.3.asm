DATAS SEGMENT
    ;此处输入数据段代码 
	ARRAY1 DB'ibm             ','$'
	ARRAY2 DB'dec             ','$'
	ARRAY3 DB'dos             ','$'
	ARRAY4 DB'dog             ','$'
DATAS ENDS

STACKS SEGMENT
    ;此处输入堆栈段代码;把小写字母转换成大写字母
    DW 8 DUP(0)
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    MOV AX,DATAS
    MOV DS,AX
    ;此处输入代码段代码
    MOV BX,0
    
    MOV CX,4
R:	PUSH CX     ;把CX压入堆栈
    MOV SI,0
    MOV CX,3
S:
    MOV AL,[BX+SI]
    AND AL,223
    MOV [BX+SI],AL
    INC SI
    LOOP S
    
    ADD BX,17
    POP CX    ;取出CX
    LOOP R
    
    MOV DX,OFFSET ARRAY2
    MOV AH,09H
    INT 21H
    
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START
