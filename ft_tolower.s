section .text
	global _ft_tolower

_ft_tolower:
	cmp rdi, 'A'
	jb return

	cmp rdi, 'Z'
	ja return

	jmp min_it

min_it:
	add rdi, 32

return:
	mov rax, rdi 
	ret

