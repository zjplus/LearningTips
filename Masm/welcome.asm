assume cs:code,ds:data

data segment
     db 'welcome to masm!',0
data ends

code segment
start:   
	 mov dh,8
     mov dl,3
     mov cl,2
     mov ax,data
     mov ds,ax
     mov si,0
     call show_str
     mov ax,4c00h
     int 21h
     
show_str:
	 push ax
     push bx
     push es
     push si
     mov ax,0b800h
     mov es,ax
     mov ax,160
     mul dh
     mov bx,ax ;bx=160*dh
     mov ax,2
     mul dl        ;ax=dl*2
     add bx,ax     ;mov bx,(160*dh+dl*2)设置es:bx指向显存首地址
     mov al,cl     ;把颜色cl赋值al
     mov cl,0
show0:
     mov ch,[si]
     jcxz show1    ;(ds:si)=0时，转到show1执行    
     mov es:[bx],ch
     mov es:[bx+1],al
     inc si        ;ds:si指向下一个字符地址
     add bx,2      ;es:bx指向下一个显存地址
     jmp show0
show1:
     pop si
     pop es
     pop bx
     pop ax
     ret
code ends
end start
