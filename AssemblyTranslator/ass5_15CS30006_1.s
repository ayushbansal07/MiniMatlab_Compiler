	.globl	add
	.type	add, @function
add:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$24, %rsp
	movq	16(%rbp), %rax
	movq	24(%rbp), %rdx
	addq	%rdx, %rax
	movq	%rax, 32(%rbp)
	movq	32(%rbp), %rax
	leave
	ret
	leave
	ret
	.size	add, .-add
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$96, %rsp
	movq	$6, %rax
	movq	%rax, 24(%rbp)
	movq	24(%rbp), %rax
	movq	%rax, 16(%rbp)
	movq	$5, %rax
	movq	%rax, 40(%rbp)
	movq	16(%rbp), %rax
	movq	40(%rbp), %rdx
	addq	%rdx, %rax
	movq	%rax, 48(%rbp)
	movq	48(%rbp), %rax
	movq	16(%rbp), %rdx
	addq	%rdx, %rax
	movq	%rax, 56(%rbp)
	movq	56(%rbp), %rax
	movq	%rax, 32(%rbp)
	movq	32(%rbp), %rdi
	pushq	%rdi
	movq	32(%rbp), %rdi
	pushq	%rdi
	call	add
	addq	$0, %rsp
	movq	%rax, 64(%rbp)
	movq	64(%rbp), %rax
	movq	%rax, 32(%rbp)
	movq	$5, %rax
	movq	%rax, 80(%rbp)
	movq	32(%rbp), %rax
	movq	80(%rbp), %rdx
	imulq	%rdx, %rax
	movq	%rax, 88(%rbp)
	movq	88(%rbp), %rax
	movq	%rax, 72(%rbp)
	movq	72(%rbp), %rdi
	pushq	%rdi
	call	printInt
	addq	$0, %rsp
	movq	%rax, 104(%rbp)
	movq	104(%rbp), %rax
	movq	%rax, 96(%rbp)
	leave
	ret
	.size	main, .-main
