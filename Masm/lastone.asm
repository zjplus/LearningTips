DATAS SEGMENT
    ;�˴��������ݶδ���
    CAR DB 0
    CAR1 DB '  O     O$'
DATAS ENDS

STACKS SEGMENT
    ;�˴������ջ�δ���
STACKS ENDS

CODES SEGMENT
	
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    MOV AX,DATAS
    MOV DS,AX
    ;�˴��������δ���
;<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
B:		MOV DH,0		;��
		MOV DL,0		;��
		MOV BH,0
		MOV AH,02H
		INT 10H
;��������
MAIN 	PROC FAR
    	CALL SHOW
    	CALL DELAY
    	CALL ERASER
    	CALL MOVE
    	CMP DH,23
    	JZ S
    	JMP MAIN
s:		JMP B	
    	RET
MAIN 	ENDP
;<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
;��ʾ�ӳ���
SHOW 	PROC NEAR
;��ʾ��һ��
		PUSH DX
		MOV	AH,9
		MOV	AL,[SI]		;д���ַ���ASC����
        MOV	BH,0		;ҳ��
        MOV	BL,0DAH		;�ַ�����
        MOV	CX,9		;�ظ�����
        INT	10H
		POP DX
;��ʾ�ڶ���		
		PUSH DX
		ADD DH,1		;��
		MOV BH,0
		MOV AH,02H
		INT 10H
		MOV	AH,9
		MOV	AL,[SI]		;д���ַ���ASC����
        MOV	BH,0		;ҳ��
        MOV	BL,0DAH		;�ַ�����
        MOV	CX,10		;�ظ�����
        INT	10H
		POP DX
;��ʾ������		
		PUSH DX
		ADD DH,2		;��
		MOV BH,0
		MOV AH,02H
		INT 10H
		MOV DX,OFFSET CAR1
		MOV AH,09H
		INT 21H
		POP DX
    	RET
SHOW	ENDP
;<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
;�ӳ��ӳ���
DELAY	PROC NEAR
		PUSH CX
    	PUSH DX
 		MOV DX,500
D1: 	MOV CX,2000
D2:		LOOP D2 
		DEC DX
		JNZ D1 
		POP DX
		POP CX 
		RET
DELAY	ENDP
;<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
;�����ӳ���
ERASER 	PROC NEAR
		PUSH BX
		PUSH CX
		PUSH DX
		MOV AH,6 ;��Ļ�Ͼ���
		MOV AL,0
		MOV CH,0 ;���Ͻ��к�
		MOV CL,0 ;���Ͻ��к�
 		MOV DH,24 ;���½��к�
		MOV DL,79 ;���½��к�
		MOV BH,7 ;����������
		INT 10H ;������ʾ����
		POP DX ;�ָ��Ĵ���
		POP CX
		POP BX
		RET
ERASER	ENDP
;<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
;�ƶ��ӳ���
MOVE 	PROC NEAR
		INC DH
		ADD DL,3
		MOV BH,0
		MOV AH,02H
		INT 10H
		RET
MOVE ENDP

CODES ENDS
    END START


