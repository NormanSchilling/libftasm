section .text
	global _ft_toupper

_ft_toupper:
	cmp rdi, 'a'
	jl return

	cmp rdi, 'z'
	jg return

	jmp maj_it

maj_it:
	sub rdi, 32

return:
	mov rax, rdi 
	ret

