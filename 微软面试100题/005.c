static void helper(int arr[], int start, int end)
{
    int now = arr[start];
    while(start != end)
    {
        if(arr[end--] < now)
            arr[start++] = now;
        else
            continue;
        if(arr[start] > now)
            arr[end] = now;
        else
            continue;
    }
    arr[start] = now;
    helper(arr, 0, start-1);
    helper(arr, start+1, end);
}

int *quickSort(int arr[], int len)
{
    int start = 0, end = len-1;

    helper(arr, start, end);
    return arr;
}


/* 005 */
void swap(int a[], int i, int p)
{
    a[i] = a[i] + a[p];
    a[p] = a[i] - a[p];
    a[i] = a[i] - a[p];
}

void siftup(int a[], int i, int n)
{
    while (i>0)
    {
        int j=(i&1==0 ? i-1 : i+1);
        int p=(i-1)>>1;
        if (j<n && a[j]<a[i])
            i = j;
        if (a[i] < a[p])
            swap(a, i, p);
        i = p;
    }
}
void siftdown(int a[], int i, int n)
{
    while (2*i+1<n)
    {
        int l=2*i+1;
        if (l+1<n && a[l+1] < a[l])
            l++;
        if (a[l] < a[i])
            swap(a, i, l);
        i=l;
    }
}
