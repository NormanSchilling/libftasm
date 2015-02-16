section .text
	global _ft_isalnum
	extern _ft_isdigit
	extern _ft_isalpha

_ft_isalnum:
	jmp checkalpha
	
checkalpha:
	call _ft_isalpha
	cmp rax, 1
	je return
	jmp	checkdigit

checkdigit:
	call _ft_isdigit
	cmp	rax, 1
	je return
	jmp return_error

return_error:
	mov rax, 0
	ret

return:
	mov rax, 1
	ret