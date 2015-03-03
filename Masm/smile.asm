assume cs:code 
  code segment 
  start:mov ax,0b800h                ;�Դ��һҳ 
        mov ds,ax 

        mov ax,0                ;Ĭ��AXΪ0 
        mov si,1                ;si���к�1-25 
        mov di,1                ;di���к�1-80 

     c1:cmp si,1                ;si��1��˵���������ˣ����ӵ��ź���AH=0 
        jne c2 
        mov ah,0 

     c2:cmp si,25                ;si����25˵���ü����ˣ����ٵ��ź���AH=1 
        jne c3 
        mov ah,1 

     c3:cmp di,1                ;DI����1�������ˣ����ӵ��ź���AL=0 
        jne c4 
        mov al,0 

     c4:cmp di,80                ;Di����80˵���ü����ˣ����ٵ��ź���AL=1 
        jne sh 
        mov al,1 

     sh:call show_smile                ;��DS��[BX]����ʾASCIIΪ1��Ц�� 
        call time                ;��ʱ�ٻ� 
        call clear_smile        ;��������Ц����ASCIIΪ32�Ŀո�ǵ� 

    ca1:cmp ax,0                ;����AX��ֵ�ж�SI��DI������ 
        jne ca2                        ;ax=0000,˵���������� 
        inc si                        ;ax=0001,˵��DI���������� 
        inc di                        ;ax=0100,˵��SI���������� 
        jmp c1                        ;ax=0101,˵��SI��DI������������ 

    ca2:cmp ax,1                ; 
        jne ca3 
        inc si 
        dec di 
        jmp c1  

    ca3:cmp ax,100h                ; 
        jne ca4 
        dec si 
        inc di 
        jmp c1         

    ca4:cmp ax,101h                ; 
        jne c1 
        dec si 
        dec di 
        jmp c1 

   over:mov ax,4c00h                ;˭��æ�Ӹ���������ûѧ�� 
        int 21h 

show_smile:push ax                ;��DS��[BX]����ʾһ���� 
        push bx 
        call bx_set                ;����BX��ֵ 
        mov al,1 
        mov [bx],al 
        pop bx 
        pop ax 
        ret 

clear_smile:push ax                ;��32���ո񣩲��� 
        push bx 
        call bx_set                ;����BX��ֵ 
        mov al,32 
        mov [bx],al 
        pop bx 
        pop ax 
        ret 

   time:push ax                        ; SBB���ᣬ����һ�� 
       push dx  
       mov dx,1000h  
       mov ax,0  
   s3: sub ax,1  
       sbb dx,0  
       cmp ax,0  
       jne s3  
       cmp dx,0  
       jne s3  
       pop dx  
       pop ax  

        ret 

 bx_set:push ax                        ;BX=160*si+2*di-162 
        push dx 
        mov ax,160 
        mul si 
        mov bx,ax 
        mov ax,2 
        mul di 
        add bx,ax 
        sub bx,162 
        pop dx 
        pop ax 
        ret 

code ends 
end start
