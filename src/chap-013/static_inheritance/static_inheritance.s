	.file	"static_inheritance.cpp"
	.text
	.section	.text._ZN7DerivedC2Ev,"axG",@progbits,_ZN7DerivedC5Ev,comdat
	.align 2
	.weak	_ZN7DerivedC2Ev
	.type	_ZN7DerivedC2Ev, @function
_ZN7DerivedC2Ev:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN4BaseI7DerivedEC2Ev
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	_ZN7DerivedC2Ev, .-_ZN7DerivedC2Ev
	.weak	_ZN7DerivedC1Ev
	.set	_ZN7DerivedC1Ev,_ZN7DerivedC2Ev
	.text
	.globl	main
	.type	main, @function
main:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	leaq	-1(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN7DerivedC1Ev
	leaq	-1(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN4BaseI7DerivedE4selfEv
	leaq	-1(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN4BaseI7DerivedE3derEv
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.section	.text._ZN4BaseI7DerivedEC2Ev,"axG",@progbits,_ZN4BaseI7DerivedEC5Ev,comdat
	.align 2
	.weak	_ZN4BaseI7DerivedEC2Ev
	.type	_ZN4BaseI7DerivedEC2Ev, @function
_ZN4BaseI7DerivedEC2Ev:
.LFB8:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	_ZN4BaseI7DerivedEC2Ev, .-_ZN4BaseI7DerivedEC2Ev
	.weak	_ZN4BaseI7DerivedEC1Ev
	.set	_ZN4BaseI7DerivedEC1Ev,_ZN4BaseI7DerivedEC2Ev
	.section	.text._ZN4BaseI7DerivedE4selfEv,"axG",@progbits,_ZN4BaseI7DerivedE4selfEv,comdat
	.align 2
	.weak	_ZN4BaseI7DerivedE4selfEv
	.type	_ZN4BaseI7DerivedE4selfEv, @function
_ZN4BaseI7DerivedE4selfEv:
.LFB10:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	_ZN4BaseI7DerivedE4selfEv, .-_ZN4BaseI7DerivedE4selfEv
	.section	.text._ZN4BaseI7DerivedE3derEv,"axG",@progbits,_ZN4BaseI7DerivedE3derEv,comdat
	.align 2
	.weak	_ZN4BaseI7DerivedE3derEv
	.type	_ZN4BaseI7DerivedE3derEv, @function
_ZN4BaseI7DerivedE3derEv:
.LFB11:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN4BaseI7DerivedE4selfEv
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE11:
	.size	_ZN4BaseI7DerivedE3derEv, .-_ZN4BaseI7DerivedE3derEv
	.ident	"GCC: (GNU) 13.2.1 20231011 (Red Hat 13.2.1-4)"
	.section	.note.GNU-stack,"",@progbits
