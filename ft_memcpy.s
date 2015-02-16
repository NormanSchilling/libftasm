section .text
	global _ft_memcpy

_ft_memcpy:
	xor al, al
	mov r8, rdi
	mov rcx, rdx
	cld
	rep movsb
	jmp return

return:
	mov rax, r8
	ret
