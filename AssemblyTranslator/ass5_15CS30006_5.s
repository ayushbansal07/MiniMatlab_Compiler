	.globl	fact
	.type	fact, @function
fact:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$56, %rsp
	movq	$1, %rax
	movq	%rax, 24(%rbp)
	movq	24(%rbp), %rax
	cmpq	%rax, 16(%rbp)
	je		.L0
	jmp		.L1
	jmp		.L1
.L0:
	movq	$1, %rax
	movq	%rax, 32(%rbp)
	movq	32(%rbp), %rax
	leave
	ret
	jmp		.L1
.L1:
	movq	$1, %rax
	movq	%rax, 40(%rbp)
	movq	16(%rbp), %rax
	movq	40(%rbp), %rdx
	subq	%rdx, %rax
	movq	%rax, 48(%rbp)
	movq	48(%rbp), %rdi
	pushq	%rdi
	call	fact
	addq	$0, %rsp
	movq	%rax, 56(%rbp)
	movq	16(%rbp), %rax
	movq	56(%rbp), %rdx
	imulq	%rdx, %rax
	movq	%rax, 64(%rbp)
	movq	64(%rbp), %rax
	leave
	ret
	leave
	ret
	.size	fact, .-fact
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$48, %rsp
	movq	$5, %rax
	movq	%rax, 24(%rbp)
	movq	24(%rbp), %rax
	movq	%rax, 16(%rbp)
	movq	16(%rbp), %rdi
	pushq	%rdi
	call	fact
	addq	$0, %rsp
	movq	%rax, 40(%rbp)
	movq	40(%rbp), %rax
	movq	%rax, 32(%rbp)
	movq	16(%rbp), %rdi
	pushq	%rdi
	call	printInt
	addq	$0, %rsp
	movq	%rax, 48(%rbp)
	movq	32(%rbp), %rdi
	pushq	%rdi
	call	printInt
	addq	$0, %rsp
	movq	%rax, 56(%rbp)
	leave
	ret
	.size	main, .-main
