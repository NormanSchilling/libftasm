section .text
	global _ft_strdup
	extern _ft_strlen
	extern _malloc

_ft_strdup:
	xor al, al
	mov r13, rdi
	call _ft_strlen
	inc rax
	mov r12, rax
	mov rdi, rax

	call _malloc

	test rax, rax
	je error

	mov rdi, rax
	mov r11, rax

	mov rsi, r13
	mov rcx, r12

	cld
	rep movsb
	jmp return

return:
	mov byte [rdi], 0
	mov rax, r11
	ret

error:
	ret