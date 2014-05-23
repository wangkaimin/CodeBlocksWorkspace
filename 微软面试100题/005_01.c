//#include <iostream>

//using namespace std;

/*static void testCPP()
{
    cout<<"testCPP"<<endl;
}
*/
/*
    // 0 1 2 3 4 5
    // 2 9 1 5 4 3
    // 1 9 1 5 4 3
    // 1 2 9 5 4 3
*/
static int findPos(int arr[], int start, int end)
{
    int i=start, j=end;
    int now = arr[i];
    while(i < j)
    {
        for(;i<j;j--)
            if(now>arr[j])
            {
                arr[i] = arr[j];
                break;
            }
        for(;i<j;i++)
            if(now<arr[i])
            {
                arr[j] = arr[i];
                break;
            }
    }
    arr[i] = now;
    return i;
}
void quickSort01(int arr[], int start, int end)
{
    int pos;
    if(start>=end)
        return;
    pos = findPos(arr, start, end);
    quickSort01(arr, start, pos-1);
    quickSort01(arr, pos+1, end);
}
