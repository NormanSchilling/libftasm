section .text
	global _ft_memset

_ft_memset:
	xor al, al
	mov r9, rdi
	mov rax, rsi
	mov rcx, rdx
	cld
	rep stosb
	jmp return

return:
	mov rax, r9
	ret