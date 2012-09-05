	.text
.globl _test
_test:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	$0, -12(%ebp)
	jmp	L2
L3:
	leal	-12(%ebp), %eax
	incl	(%eax)
L2:
	movl	-12(%ebp), %eax
	cmpl	8(%ebp), %eax
	jl	L3
	movl	8(%ebp), %eax
	leave
	ret
	.subsections_via_symbols
