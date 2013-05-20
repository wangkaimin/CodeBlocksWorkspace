#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int str2int(const char *str)
{
    int sum=0, sign = 1;
    char *pos = str;
    assert(pos != NULL);
    if((*pos) == '-')
    {
        sign = -1;
        pos++;
    }
    else if(*pos == '+')
        pos++;
    while((*pos) != '\0')
    {
        assert(*pos >= '0' && *pos <= '9');
        sum = 10*sum+ (*pos)-'0';
        pos++;
    }
    return sum*sign;
}
int main()
{
    char str[] = "254123";
    printf("%s\t%d\n",str,str2int(str));
    return 0;
}
