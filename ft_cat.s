section .bss
    buff resb 256

section .text
       global _ft_cat

_ft_cat:
	mov r12, rdi
	mov byte [rel buff], 0

read:
	mov rax, 0x2000003
	mov rdi, r12
	mov rsi, buff 
	mov rdx, 20
	syscall

	jc return

	cmp rax, 0
	je return

	mov rdx, rax
	mov rax, 0x2000004
	mov rdi, 1
	mov rsi, buff
	syscall
	jmp read

return:
	ret