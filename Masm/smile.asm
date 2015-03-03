assume cs:code 
  code segment 
  start:mov ax,0b800h                ;显存第一页 
        mov ds,ax 

        mov ax,0                ;默认AX为0 
        mov si,1                ;si是行号1-25 
        mov di,1                ;di是列号1-80 

     c1:cmp si,1                ;si到1了说明该增加了，增加的信号是AH=0 
        jne c2 
        mov ah,0 

     c2:cmp si,25                ;si到了25说明该减少了，减少的信号是AH=1 
        jne c3 
        mov ah,1 

     c3:cmp di,1                ;DI到了1该增加了，增加的信号是AL=0 
        jne c4 
        mov al,0 

     c4:cmp di,80                ;Di到了80说明该减少了，减少的信号是AL=1 
        jne sh 
        mov al,1 

     sh:call show_smile                ;在DS：[BX]处显示ASCII为1的笑脸 
        call time                ;延时召唤 
        call clear_smile        ;擦脸：把笑脸用ASCII为32的空格盖掉 

    ca1:cmp ax,0                ;依据AX的值判断SI，DI的增减 
        jne ca2                        ;ax=0000,说明都该增加 
        inc si                        ;ax=0001,说明DI不能增加了 
        inc di                        ;ax=0100,说明SI不能增加了 
        jmp c1                        ;ax=0101,说明SI，DI都不能增加了 

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

   over:mov ax,4c00h                ;谁帮忙加个按键，还没学到 
        int 21h 

show_smile:push ax                ;在DS：[BX]处显示一张脸 
        push bx 
        call bx_set                ;设置BX的值 
        mov al,1 
        mov [bx],al 
        pop bx 
        pop ax 
        ret 

clear_smile:push ax                ;用32（空格）擦脸 
        push bx 
        call bx_set                ;设置BX的值 
        mov al,32 
        mov [bx],al 
        pop bx 
        pop ax 
        ret 

   time:push ax                        ; SBB不会，借用一下 
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
