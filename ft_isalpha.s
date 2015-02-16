section .text
	global _ft_isalpha

_ft_isalpha:
	jmp maj_a

maj_a:
	cmp rdi, 'A'
	jae maj_z
	jmp	return_error

maj_z:
	cmp rdi, 'Z'
	jbe return
	jmp min_a

min_a:
	cmp rdi, 'a'
	jae min_z
	jmp	return_error

min_z:
	cmp rdi, 'z'
	jbe return
	jmp return_error

return_error:
	mov rax, 0
	ret

return:
	mov rax, 1
	ret