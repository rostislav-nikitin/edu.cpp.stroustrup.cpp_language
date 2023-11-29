	.file	"list_template.cpp"
	.text
	.globl	main
	.type	main, @function
main:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$0, -8(%rbp)
	leaq	-8(%rbp), %rdx
	leaq	-16(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN4ListIiEC1ERKi
	leaq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN4ListIiE9print_allEv
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	main, .-main
	.section	.text._ZN4ListIiEC2ERKi,"axG",@progbits,_ZN4ListIiEC5ERKi,comdat
	.align 2
	.weak	_ZN4ListIiEC2ERKi
	.type	_ZN4ListIiEC2ERKi, @function
_ZN4ListIiEC2ERKi:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movl	$24, %edi
	call	_Znwm
	movq	%rax, %rbx
	movq	-32(%rbp), %rax
	movq	%rax, %rcx
	movl	$0, %edx
	movl	$0, %esi
	movq	%rbx, %rdi
	call	_ZN4ListIiE4LinkC1EPS1_S2_RKi
	movq	-24(%rbp), %rax
	movq	%rbx, (%rax)
	nop
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	_ZN4ListIiEC2ERKi, .-_ZN4ListIiEC2ERKi
	.weak	_ZN4ListIiEC1ERKi
	.set	_ZN4ListIiEC1ERKi,_ZN4ListIiEC2ERKi
	.section	.text._ZN4ListIiE9print_allEv,"axG",@progbits,_ZN4ListIiE9print_allEv,comdat
	.align 2
	.weak	_ZN4ListIiE9print_allEv
	.type	_ZN4ListIiE9print_allEv, @function
_ZN4ListIiE9print_allEv:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movl	$0, -4(%rbp)
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -16(%rbp)
	jmp	.L5
.L6:
	movq	-16(%rbp), %rax
	movl	16(%rax), %eax
	movl	%eax, -4(%rbp)
	movq	-16(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -16(%rbp)
.L5:
	cmpq	$0, -16(%rbp)
	jne	.L6
	movl	-4(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	_ZN4ListIiE9print_allEv, .-_ZN4ListIiE9print_allEv
	.section	.text._ZN4ListIiE4LinkC2EPS1_S2_RKi,"axG",@progbits,_ZN4ListIiE4LinkC5EPS1_S2_RKi,comdat
	.align 2
	.weak	_ZN4ListIiE4LinkC2EPS1_S2_RKi
	.type	_ZN4ListIiE4LinkC2EPS1_S2_RKi, @function
_ZN4ListIiE4LinkC2EPS1_S2_RKi:
.LFB9:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	%rcx, -32(%rbp)
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rdx
	movq	%rdx, (%rax)
	movq	-8(%rbp), %rax
	movq	-24(%rbp), %rdx
	movq	%rdx, 8(%rax)
	movq	-32(%rbp), %rax
	movl	(%rax), %edx
	movq	-8(%rbp), %rax
	movl	%edx, 16(%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	_ZN4ListIiE4LinkC2EPS1_S2_RKi, .-_ZN4ListIiE4LinkC2EPS1_S2_RKi
	.weak	_ZN4ListIiE4LinkC1EPS1_S2_RKi
	.set	_ZN4ListIiE4LinkC1EPS1_S2_RKi,_ZN4ListIiE4LinkC2EPS1_S2_RKi
	.ident	"GCC: (GNU) 13.2.1 20231011 (Red Hat 13.2.1-4)"
	.section	.note.GNU-stack,"",@progbits
