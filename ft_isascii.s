section .text
	global _ft_isascii

_ft_isascii:
	cmp rdi, 0
	jb return_error

	cmp rdi, 127
	ja return_error

	jmp return

return:
	mov rax, 1
	ret

return_error:
	mov rax, 0
	ret