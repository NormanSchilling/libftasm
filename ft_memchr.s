section .text
	global _ft_memchr

_ft_memchr:
	mov r12, rdi
	mov r8, 0
loop:
	cmp r8, rdx
	je return_null
	cmp byte [rdi], sil
	je return
	inc rdi
	inc r8
	jmp loop

return:
	mov rax, rdi 
	mov rdi, r12
	ret

return_null:
	mov rax, 0
	ret