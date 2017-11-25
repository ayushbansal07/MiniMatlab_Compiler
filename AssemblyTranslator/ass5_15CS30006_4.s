DBL0:
	.long	1065353216
	.long	32528
DBL1:
	.long	1073741824
	.long	32528
DBL2:
	.long	1077936128
	.long	32528
DBL3:
	.long	1082130432
	.long	32528
DBL4:
	.long	1084227584
	.long	32528
DBL5:
	.long	1086324736
	.long	32528
	.text
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$368, %rsp
	movq	$2, %rax
	movq	%rax, 16(%rbp)
	movq	$3, %rax
	movq	%rax, 24(%rbp)
	movsd	DBL0(%rip), %xmm0
	movq	%xmm0, 96(%rbp)
	movsd	DBL1(%rip), %xmm0
	movq	%xmm0, 104(%rbp)
	movsd	DBL2(%rip), %xmm0
	movq	%xmm0, 112(%rbp)
	movsd	DBL3(%rip), %xmm0
	movq	%xmm0, 120(%rbp)
	movsd	DBL4(%rip), %xmm0
	movq	%xmm0, 128(%rbp)
	movsd	DBL5(%rip), %xmm0
	movq	%xmm0, 136(%rbp)
	movq	$16, %rax
	movq	%rax, 144(%rbp)
	movq	144(%rbp), %rax
	movsd	96(%rbp), %xmm0
	leaq	32(%rbp), %rcx
	movsd	%xmm0, (%rcx, %rax)
	movq	$24, %rax
	movq	%rax, 152(%rbp)
	movq	152(%rbp), %rax
	movsd	104(%rbp), %xmm0
	leaq	32(%rbp), %rcx
	movsd	%xmm0, (%rcx, %rax)
	movq	$32, %rax
	movq	%rax, 160(%rbp)
	movq	160(%rbp), %rax
	movsd	112(%rbp), %xmm0
	leaq	32(%rbp), %rcx
	movsd	%xmm0, (%rcx, %rax)
	movq	$40, %rax
	movq	%rax, 168(%rbp)
	movq	168(%rbp), %rax
	movsd	120(%rbp), %xmm0
	leaq	32(%rbp), %rcx
	movsd	%xmm0, (%rcx, %rax)
	movq	$48, %rax
	movq	%rax, 176(%rbp)
	movq	176(%rbp), %rax
	movsd	128(%rbp), %xmm0
	leaq	32(%rbp), %rcx
	movsd	%xmm0, (%rcx, %rax)
	movq	$56, %rax
	movq	%rax, 184(%rbp)
	movq	184(%rbp), %rax
	movsd	136(%rbp), %xmm0
	leaq	32(%rbp), %rcx
	movsd	%xmm0, (%rcx, %rax)
	leaq	32(%rbp), %rax
	movq	%rax, 32(%rbp)
	movq	$0, %rax
	movq	%rax, 200(%rbp)
	movq	200(%rbp), %rax
	cvtsi2ss	%rax, %xmm0
	movsd	%xmm0, 208(%rbp)
	movsd	208(%rbp), %xmm0
	movsd	%xmm0, 192(%rbp)
	movq	$0, %rax
	movq	%rax, 232(%rbp)
	movq	232(%rbp), %rax
	movq	%rax, 216(%rbp)
.L0:
	movq	$2, %rax
	movq	%rax, 240(%rbp)
	movq	240(%rbp), %rax
	cmpq	%rax, 216(%rbp)
	jl		.L2
	jmp		.L7
	jmp		.L7
.L1:
	movq	216(%rbp), %rax
	movq	%rax, 248(%rbp)
	movq	216(%rbp), %rax
	movq	$1, %rdx
	addq	%rdx, %rax
	movq	%rax, 216(%rbp)
	jmp		.L0
.L2:
	movq	$0, %rax
	movq	%rax, 256(%rbp)
	movq	256(%rbp), %rax
	movq	%rax, 224(%rbp)
.L3:
	movq	$3, %rax
	movq	%rax, 264(%rbp)
	movq	264(%rbp), %rax
	cmpq	%rax, 224(%rbp)
	jl		.L5
	jmp		.L6
	jmp		.L6
.L4:
	movq	224(%rbp), %rax
	movq	%rax, 272(%rbp)
	movq	224(%rbp), %rax
	movq	$1, %rdx
	addq	%rdx, %rax
	movq	%rax, 224(%rbp)
	jmp		.L3
.L5:
	movq	$16, %rax
	movq	%rax, 288(%rbp)
	movq	$3, %rax
	movq	%rax, 296(%rbp)
	movq	$8, %rax
	movq	%rax, 304(%rbp)
	movq	216(%rbp), %rax
	movq	296(%rbp), %rdx
	imulq	%rdx, %rax
	movq	%rax, 280(%rbp)
	movq	280(%rbp), %rax
	movq	224(%rbp), %rdx
	addq	%rdx, %rax
	movq	%rax, 280(%rbp)
	movq	280(%rbp), %rax
	movq	304(%rbp), %rdx
	imulq	%rdx, %rax
	movq	%rax, 280(%rbp)
	movq	280(%rbp), %rax
	movq	288(%rbp), %rdx
	addq	%rdx, %rax
	movq	%rax, 280(%rbp)
	movq	280(%rbp), %rax
	leaq	32(%rbp), %rcx
	movsd	(%rcx, %rax), %xmm0
	movsd	%xmm0, 312(%rbp)
	movsd	312(%rbp), %xmm0
	call	printFlt
	addq	$0, %rsp
	movq	%rax, 320(%rbp)
	movq	$16, %rax
	movq	%rax, 336(%rbp)
	movq	$3, %rax
	movq	%rax, 344(%rbp)
	movq	$8, %rax
	movq	%rax, 352(%rbp)
	movq	216(%rbp), %rax
	movq	344(%rbp), %rdx
	imulq	%rdx, %rax
	movq	%rax, 328(%rbp)
	movq	328(%rbp), %rax
	movq	224(%rbp), %rdx
	addq	%rdx, %rax
	movq	%rax, 328(%rbp)
	movq	328(%rbp), %rax
	movq	352(%rbp), %rdx
	imulq	%rdx, %rax
	movq	%rax, 328(%rbp)
	movq	328(%rbp), %rax
	movq	336(%rbp), %rdx
	addq	%rdx, %rax
	movq	%rax, 328(%rbp)
	movq	328(%rbp), %rax
	leaq	32(%rbp), %rcx
	movsd	(%rcx, %rax), %xmm0
	movsd	%xmm0, 360(%rbp)
	movsd	192(%rbp), %xmm0
	movsd	360(%rbp), %xmm1
	addps	%xmm1, %xmm0
	movsd	%xmm0, 368(%rbp)
	movsd	368(%rbp), %xmm0
	movsd	%xmm0, 192(%rbp)
	jmp		.L4
.L6:
	jmp		.L1
.L7:
	movsd	192(%rbp), %xmm0
	call	printFlt
	addq	$0, %rsp
	movq	%rax, 376(%rbp)
	leave
	ret
	.size	main, .-main
