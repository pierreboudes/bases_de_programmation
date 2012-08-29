	.text
.globl _test
_test:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	cmpl	$0, 8(%ebp)
	js	L2
	movl	$1, -12(%ebp)
	jmp	L4
L2:
	movl	$0, -12(%ebp)
L4:
	movl	-12(%ebp), %eax
	leave
	ret
	.subsections_via_symbols
