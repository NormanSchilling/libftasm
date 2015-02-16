section .text
	global _ft_islower

_ft_islower:
	cmp rdi, 'z'
	jle check_a

check_a:
	cmp rdi, 'a'
	jge return

	jmp return_error


return:
	mov rax, 1 
	ret

return_error:
	mov rax, 0
	ret
