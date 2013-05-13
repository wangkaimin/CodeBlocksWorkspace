#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x=1;
    int y;
    // x=x+1;y=x+x;x=x+1;
    y=x++ + ++x;
    printf("x=%d\ty=%d\n",x,y);

    x=1;
    // x=x+1;y=x+x;;x=x+1
    y= ++x + x++;
    printf("x=%d\ty=%d\n",x,y);

    x=1;
    // x=x+1;x=x+1;y=x+x;
    y= ++x + ++x;
    printf("x=%d\ty=%d\n",x,y);

    x=1;
    // y=x+x;x=x+1;x=x+1;
    y= x++ + ++x;
    printf("x=%d\ty=%d\n",x,y);

    x=1;
    y=x++ + (++x)*(++x);
    printf("x=%d\ty=%d\n",x,y);

    x=1;
    y=++x + (x++)*(++x);
    printf("x=%d\ty=%d\n",x,y);
//    总结，可分为三步：
//    1、找出x++的数目m、++x的数目n，先写n个x=x+1
//    2、原式去掉所有++
//    3、写m个x=x+1
    return 0;
}
