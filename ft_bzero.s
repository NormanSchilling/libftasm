section .text
	global _ft_bzero

_ft_bzero:
	mov rdx, 0

loop:
	cmp rsi, rdx
	je return
	mov byte [rdi + rdx], 0
	inc rdx
	jmp loop

return:
	ret
