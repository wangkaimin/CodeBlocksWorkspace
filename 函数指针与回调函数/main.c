#include <stdio.h>
#include <stdlib.h>
#include "para_callback.h"

typedef void (*func)();
void filefunc();
void editfunc();
void say_hello(void *str);

int main()
{
    func f;
    f = &filefunc;
    f();
    f = editfunc;
    (*f)();

    repeat_three_times(say_hello,"kaimin");
    return 0;
}
 void filefunc()
 {
     printf("I'm filefunc.\n");
 }
 void editfunc()
 {
     printf("I'm editfunc.\n");
 }
 void say_hello(void *str)
 {
     printf("hello, %s.\n",(const char *)str);
 }
