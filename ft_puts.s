section .data
	msg db	10
	msgnull db 	"(null)"

section .text
	global _ft_puts
	extern _ft_strlen

_ft_puts:
	cmp rdi, 0
	je null
	mov r9, rdi
	call _ft_strlen
	mov r8, rax

	mov	rax, 0x2000004
	mov rdi, 1
	mov rsi, r9
	mov rdx, r8
	syscall
	jmp return_line

null:
	mov	rax, 0x2000004
	mov rdi, 1
	mov rsi, msgnull
	mov rdx, 6
	syscall
	jmp return_line

return_line:
	mov	rax, 0x2000004
	mov rdi, 1
	mov rsi, msg
	mov rdx, 1
	syscall
	ret