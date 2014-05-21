//#include <iostream>

//using namespace std;

/*static void testCPP()
{
    cout<<"testCPP"<<endl;
}
*/
static int findPos(int arr[], int start, int end)
{
    int i=start, j=end;
    int now = arr[i];
    while(i != j)
    {
        for(;i<j;j--)
            if(now>arr[j])
                arr[j] = arr[i];
        for(;i<j;i++)
            if(now<arr[i])
                arr[i] = arr[j];
    }
    arr[i] = now;
    return i;
}
void quickSort01(int arr[], int start, int end)
{
    int pos = findPos(arr, start, end);
    quickSort01(arr, start, pos-1);
    quickSort01(arr, pos+1, end);
}
