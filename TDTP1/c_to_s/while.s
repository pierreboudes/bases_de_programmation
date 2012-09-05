	.text
.globl _test
_test:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	jmp	L2
L3:
	incl	8(%ebp)
L2:
	cmpl	$0, 8(%ebp)
	js	L3
	movl	8(%ebp), %eax
	leave
	ret
	.subsections_via_symbols
