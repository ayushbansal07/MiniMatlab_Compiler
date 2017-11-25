DBL0:
	.long	1084856730
	.long	0
	.text
	.globl	fib
	.type	fib, @function
fib:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$80, %rsp
	movq	$1, %rax
	movq	%rax, 24(%rbp)
	movq	24(%rbp), %rax
	cmpq	%rax, 16(%rbp)
	jle		.L0
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
	call	fib
	addq	$0, %rsp
	movq	%rax, 56(%rbp)
	movq	$2, %rax
	movq	%rax, 64(%rbp)
	movq	16(%rbp), %rax
	movq	64(%rbp), %rdx
	subq	%rdx, %rax
	movq	%rax, 72(%rbp)
	movq	72(%rbp), %rdi
	pushq	%rdi
	call	fib
	addq	$0, %rsp
	movq	%rax, 80(%rbp)
	movq	56(%rbp), %rax
	movq	80(%rbp), %rdx
	addq	%rdx, %rax
	movq	%rax, 88(%rbp)
	movq	88(%rbp), %rax
	leave
	ret
	leave
	ret
	.size	fib, .-fib
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$88, %rsp
	leaq	16(%rbp), %rax
	movq	%rax, 24(%rbp)
	movq	24(%rbp), %rdi
	pushq	%rdi
	call	readFlt
	addq	$0, %rsp
	movq	%rax, 32(%rbp)
	movsd	16(%rbp), %xmm0
	xorpd	%xmm1, %xmm1
	subps	%xmm0, %xmm1
	movsd	%xmm1, 48(%rbp)
	movsd	48(%rbp), %xmm0
	movsd	%xmm0, 40(%rbp)
	movsd	DBL0(%rip), %xmm0
	movq	%xmm0, 56(%rbp)
	movsd	40(%rbp), %xmm0
	movsd	56(%rbp), %xmm1
	mulps	%xmm1, %xmm0
	movsd	%xmm0, 64(%rbp)
	movsd	64(%rbp), %xmm0
	movsd	%xmm0, 40(%rbp)
	movsd	40(%rbp), %xmm0
	call	printFlt
	addq	$0, %rsp
	movq	%rax, 72(%rbp)
	movq	$5, %rax
	movq	%rax, 80(%rbp)
	movq	80(%rbp), %rdi
	pushq	%rdi
	call	fib
	addq	$0, %rsp
	movq	%rax, 88(%rbp)
	movq	88(%rbp), %rdi
	pushq	%rdi
	call	printInt
	addq	$0, %rsp
	movq	%rax, 96(%rbp)
	leave
	ret
	.size	main, .-main
