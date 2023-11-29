	.file	"use_list.cpp"
	.text
#APP
	.globl _ZSt21ios_base_library_initv
#NO_APP
	.globl	main
	.type	main, @function
main:
.LFB1987:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$10, -4(%rbp)
	leaq	-4(%rbp), %rdx
	leaq	-16(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN4ListIiEC1ERKi
	leaq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN4ListIiE9print_allEv
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1987:
	.size	main, .-main
	.section	.text._ZN4ListIiEC2ERKi,"axG",@progbits,_ZN4ListIiEC5ERKi,comdat
	.align 2
	.weak	_ZN4ListIiEC2ERKi
	.type	_ZN4ListIiEC2ERKi, @function
_ZN4ListIiEC2ERKi:
.LFB2244:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA2244
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 13, -24
	.cfi_offset 12, -32
	.cfi_offset 3, -40
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movl	$24, %edi
.LEHB0:
	call	_Znwm
.LEHE0:
	movq	%rax, %rbx
	movl	$1, %r13d
	movq	-48(%rbp), %rax
	movq	%rax, %rcx
	movl	$0, %edx
	movl	$0, %esi
	movq	%rbx, %rdi
.LEHB1:
	call	_ZN4ListIiE5TLinkC1EPS1_S2_RKi
.LEHE1:
	movq	-40(%rbp), %rax
	movq	%rbx, (%rax)
	jmp	.L7
.L6:
	movq	%rax, %r12
	testb	%r13b, %r13b
	je	.L5
	movl	$24, %esi
	movq	%rbx, %rdi
	call	_ZdlPvm
.L5:
	movq	%r12, %rax
	movq	%rax, %rdi
.LEHB2:
	call	_Unwind_Resume
.LEHE2:
.L7:
	addq	$24, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2244:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table._ZN4ListIiEC2ERKi,"aG",@progbits,_ZN4ListIiEC5ERKi,comdat
.LLSDA2244:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE2244-.LLSDACSB2244
.LLSDACSB2244:
	.uleb128 .LEHB0-.LFB2244
	.uleb128 .LEHE0-.LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB1-.LFB2244
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L6-.LFB2244
	.uleb128 0
	.uleb128 .LEHB2-.LFB2244
	.uleb128 .LEHE2-.LEHB2
	.uleb128 0
	.uleb128 0
.LLSDACSE2244:
	.section	.text._ZN4ListIiEC2ERKi,"axG",@progbits,_ZN4ListIiEC5ERKi,comdat
	.size	_ZN4ListIiEC2ERKi, .-_ZN4ListIiEC2ERKi
	.weak	_ZN4ListIiEC1ERKi
	.set	_ZN4ListIiEC1ERKi,_ZN4ListIiEC2ERKi
	.section	.text._ZN4ListIiE9print_allEv,"axG",@progbits,_ZN4ListIiE9print_allEv,comdat
	.align 2
	.weak	_ZN4ListIiE9print_allEv
	.type	_ZN4ListIiE9print_allEv, @function
_ZN4ListIiE9print_allEv:
.LFB2246:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	jmp	.L9
.L10:
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN4ListIiE4LinkINS0_5TLinkEE4selfEv
	movl	16(%rax), %eax
	movl	%eax, %esi
	movl	$_ZSt4cout, %edi
	call	_ZNSolsEi
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %esi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -8(%rbp)
.L9:
	cmpq	$0, -8(%rbp)
	jne	.L10
	nop
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2246:
	.size	_ZN4ListIiE9print_allEv, .-_ZN4ListIiE9print_allEv
	.section	.text._ZN4ListIiE5TLinkC2EPS1_S2_RKi,"axG",@progbits,_ZN4ListIiE5TLinkC5EPS1_S2_RKi,comdat
	.align 2
	.weak	_ZN4ListIiE5TLinkC2EPS1_S2_RKi
	.type	_ZN4ListIiE5TLinkC2EPS1_S2_RKi, @function
_ZN4ListIiE5TLinkC2EPS1_S2_RKi:
.LFB2349:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	%rcx, -32(%rbp)
	movq	-8(%rbp), %rax
	movq	-24(%rbp), %rdx
	movq	-16(%rbp), %rcx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZN4ListIiE4LinkINS0_5TLinkEEC2EPS2_S4_
	movq	-32(%rbp), %rax
	movl	(%rax), %edx
	movq	-8(%rbp), %rax
	movl	%edx, 16(%rax)
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2349:
	.size	_ZN4ListIiE5TLinkC2EPS1_S2_RKi, .-_ZN4ListIiE5TLinkC2EPS1_S2_RKi
	.weak	_ZN4ListIiE5TLinkC1EPS1_S2_RKi
	.set	_ZN4ListIiE5TLinkC1EPS1_S2_RKi,_ZN4ListIiE5TLinkC2EPS1_S2_RKi
	.section	.text._ZN4ListIiE4LinkINS0_5TLinkEE4selfEv,"axG",@progbits,_ZN4ListIiE4LinkINS0_5TLinkEE4selfEv,comdat
	.align 2
	.weak	_ZN4ListIiE4LinkINS0_5TLinkEE4selfEv
	.type	_ZN4ListIiE4LinkINS0_5TLinkEE4selfEv, @function
_ZN4ListIiE4LinkINS0_5TLinkEE4selfEv:
.LFB2351:
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
.LFE2351:
	.size	_ZN4ListIiE4LinkINS0_5TLinkEE4selfEv, .-_ZN4ListIiE4LinkINS0_5TLinkEE4selfEv
	.section	.text._ZN4ListIiE4LinkINS0_5TLinkEEC2EPS2_S4_,"axG",@progbits,_ZN4ListIiE4LinkINS0_5TLinkEEC5EPS2_S4_,comdat
	.align 2
	.weak	_ZN4ListIiE4LinkINS0_5TLinkEEC2EPS2_S4_
	.type	_ZN4ListIiE4LinkINS0_5TLinkEEC2EPS2_S4_, @function
_ZN4ListIiE4LinkINS0_5TLinkEEC2EPS2_S4_:
.LFB2427:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rdx
	movq	%rdx, (%rax)
	movq	-8(%rbp), %rax
	movq	-24(%rbp), %rdx
	movq	%rdx, 8(%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2427:
	.size	_ZN4ListIiE4LinkINS0_5TLinkEEC2EPS2_S4_, .-_ZN4ListIiE4LinkINS0_5TLinkEEC2EPS2_S4_
	.weak	_ZN4ListIiE4LinkINS0_5TLinkEEC1EPS2_S4_
	.set	_ZN4ListIiE4LinkINS0_5TLinkEEC1EPS2_S4_,_ZN4ListIiE4LinkINS0_5TLinkEEC2EPS2_S4_
	.section	.rodata
	.type	_ZNSt8__detail30__integer_to_chars_is_unsignedIjEE, @object
	.size	_ZNSt8__detail30__integer_to_chars_is_unsignedIjEE, 1
_ZNSt8__detail30__integer_to_chars_is_unsignedIjEE:
	.byte	1
	.type	_ZNSt8__detail30__integer_to_chars_is_unsignedImEE, @object
	.size	_ZNSt8__detail30__integer_to_chars_is_unsignedImEE, 1
_ZNSt8__detail30__integer_to_chars_is_unsignedImEE:
	.byte	1
	.type	_ZNSt8__detail30__integer_to_chars_is_unsignedIyEE, @object
	.size	_ZNSt8__detail30__integer_to_chars_is_unsignedIyEE, 1
_ZNSt8__detail30__integer_to_chars_is_unsignedIyEE:
	.byte	1
	.ident	"GCC: (GNU) 13.2.1 20231011 (Red Hat 13.2.1-4)"
	.section	.note.GNU-stack,"",@progbits
