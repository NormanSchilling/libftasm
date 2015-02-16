section .text
	global _ft_strchr

_ft_strchr:
	mov r12, rdi

loop:
	cmp byte [rdi], 0
	je return_null
	cmp byte [rdi], sil
	je return
	inc rdi
	jmp loop

return:
	mov rax, rdi
	mov rdi, r12
	ret

return_null:
	mov rax, 0
	ret
