DBL0:
	.long	1086031135
	.long	0
	.text
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$64, %rsp
	leaq	16(%rbp), %rax
	movq	%rax, 24(%rbp)
	movq	24(%rbp), %rdi
	pushq	%rdi
	call	readInt
	addq	$0, %rsp
	movq	%rax, 32(%rbp)
	movsd	DBL0(%rip), %xmm0
	movq	%xmm0, 48(%rbp)
	movq	16(%rbp), %rax
	cvtsi2ss	%rax, %xmm0
	movsd	%xmm0, 56(%rbp)
	movsd	48(%rbp), %xmm0
	movsd	56(%rbp), %xmm1
	addps	%xmm1, %xmm0
	movsd	%xmm0, 64(%rbp)
	movsd	64(%rbp), %xmm0
	movsd	%xmm0, 40(%rbp)
	movsd	40(%rbp), %xmm0
	call	printFlt
	addq	$0, %rsp
	movq	%rax, 72(%rbp)
	leave
	ret
	.size	main, .-main
