section .text
	global _ft_strncat

_ft_strncat:
	xor al, al
	mov r8, rdi
	mov r13, 0

while_s1:
	cmp byte [rdi], 0
	je copy
	inc rdi
	jmp while_s1

copy:
	cmp r13, rdx
	je return
	mov rax, [rsi]
	mov byte [rdi], al
	inc rsi
	inc rdi
	inc r13
	jmp copy

return:
	mov byte [rdi], 0
	mov rax, r8
	ret