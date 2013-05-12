#include <iostream>

using namespace std;

int test1()
{
    int j=14;
    int k=1;
    // k+=j+;// 通不过编译
    return k;
}
int test2()
{
    int k;
    // 非法操作
    **((int **) &k) = 16;
    return k;
}
int test3()
{
    int j;
    int k=4;
    // error
    //j=k<<>>11;
    k+=j;
    return k;
}
int test4()
{
    int j,k;
    //j=2<<k="j"j="256;"k="14;"k="j">
    return k;
}
int main()
{
    cout<<"k="<<test3()<<endl;
    return 0;
}

