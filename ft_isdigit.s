section .text
	global _ft_isdigit

_ft_isdigit:
	jmp digit_zero

digit_zero:
	cmp rdi, '0'
	jae digit_nine
	jmp	return_error

digit_nine:
	cmp rdi, '9'
	jbe return
	jmp return_error

return_error:
	mov rax, 0
	ret

return:
	mov rax, 1
	ret