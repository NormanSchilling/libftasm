section .text
	global _ft_isprint

_ft_isprint:
	mov r10, rdi

	cmp r10, 32
	jl return_error

	cmp r10, 126
	jg return_error

	jmp return

return:
	mov rax, 1
	ret

return_error:
	mov rax, 0
	ret
