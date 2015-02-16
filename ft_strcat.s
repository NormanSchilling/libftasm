section .text
	global _ft_strcat

_ft_strcat:
	xor al, al
	mov r8, rdi

while_s1:
	cmp byte [rdi], 0
	je copy
	inc rdi
	jmp while_s1

copy:
	cmp byte [rsi], 0
	je return
	mov rax, [rsi]
	mov byte [rdi], al
	inc rsi
	inc rdi
	jmp copy

return:
	mov byte [rdi], 0
	mov rax, r8
	ret