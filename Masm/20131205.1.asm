assume cs:codes

;求2的3次方并输出
codes segment
	mov ax,2
	add ax,ax
	add ax,ax
	mov dx,ax
	add dl,30h
	mov ah,02h
	int 21h
	
	mov ax,21
	mov al,10d
	div al
	mov dl,al
	mov dl,30h
	mov ah,02h
	int 21h
	
	
	
	mov ax,4c00h
	int 21h
codes ends

end



