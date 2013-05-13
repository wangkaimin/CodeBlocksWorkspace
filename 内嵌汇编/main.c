#include <stdio.h>
#include <stdlib.h>

void test1()
{
    /* val1+val2=val3 */
	unsigned int val1 = 1;
	unsigned int val2 = 2;
	unsigned int val3 = 0;
	printf("val1:%d,val2:%d,val3:%d\n",val1,val2,val3);
	asm volatile(
	"movl $0,%%eax\n\t" 	/* clear %eax to 0*/
	"addl %1,%%eax\n\t" 	/* %eax += val1 */
	"addl %2,%%eax\n\t" 	/* %eax += val2 */
	"movl %%eax,%0\n\t" 	/* val2 = %eax*/
	: "=m" (val3) 	        /* output =m mean only write output memory variable*/
	: "c" (val1),"d" (val2)	/* input c or d mean %ecx/%edx*/
	);
	printf("val1:%d+val2:%d=val3:%d\n",val1,val2,val3);
}
void test2()
{
    int input,output,temp;
    input = 1;
    __asm__ __volatile__ ("movl $0, %%eax;\n\t"
                          "movl %%eax,%1;\n\t"
                          "movl %2,%%eax;\n\t"
                          "movl %%eax,%0;\n\t"
                          :"=m"(output),"=m"(temp)
                          :"r"(input)
                          :"eax");
    printf("%d %d\n",temp,output);
}
int main()
{
    test1();
    test2();
    return 0;
}
