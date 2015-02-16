section .text
	global _ft_isupper

_ft_isupper:
	cmp rdi, 'A'
	jb return_error

	cmp rdi, 'Z'
	ja return_error

	jmp return

return:
	mov rax, 1 
	ret

return_error:
	mov rax, 0
	ret
