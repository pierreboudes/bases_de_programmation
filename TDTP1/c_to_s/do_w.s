	.text
.globl _test
_test:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
L2:
	incl	8(%ebp)
	cmpl	$0, 8(%ebp)
	js	L2
	movl	8(%ebp), %eax
	leave
	ret
	.subsections_via_symbols
