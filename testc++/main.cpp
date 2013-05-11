#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int a = 3;
    int &c = a;
    printf("%d\t0x%08x\n",c,&c);
    printf("%d\t0x%08x\n",a,&a);
    cout << "Hello world!" << endl;
    return 0;
}
