	.file	"main.c"
	.section .rdata,"dr"
LC0:
	.ascii "val1:%d,val2:%d,val3:%d\12\0"
LC1:
	.ascii "val1:%d+val2:%d=val3:%d\12\0"
	.text
.globl _test1
	.def	_test1;	.scl	2;	.type	32;	.endef
_test1:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	$1, -12(%ebp)
	movl	$2, -16(%ebp)
	movl	$0, -20(%ebp)
	movl	-20(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	movl	-12(%ebp), %eax
	movl	-16(%ebp), %edx
	movl	%eax, %ecx
/APP
 # 11 "main.c" 1
	movl $0,%eax
	addl %ecx,%eax
	addl %edx,%eax
	movl %eax,-20(%ebp)
	
 # 0 "" 2
/NO_APP
	movl	-20(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC1, (%esp)
	call	_printf
	leave
	ret
	.section .rdata,"dr"
LC2:
	.ascii "%d %d\12\0"
	.text
.globl _test2
	.def	_test2;	.scl	2;	.type	32;	.endef
_test2:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	$1, -12(%ebp)
	movl	-12(%ebp), %edx
/APP
 # 25 "main.c" 1
	movl $0, %eax;
	movl %eax,-20(%ebp);
	movl %edx,%eax;
	movl %eax,-16(%ebp);
	
 # 0 "" 2
/NO_APP
	movl	-16(%ebp), %edx
	movl	-20(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC2, (%esp)
	call	_printf
	leave
	ret
	.def	___main;	.scl	2;	.type	32;	.endef
.globl _main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	call	___main
	call	_test1
	call	_test2
	movl	$0, %eax
	movl	%ebp, %esp
	popl	%ebp
	ret
	.def	_printf;	.scl	2;	.type	32;	.endef
