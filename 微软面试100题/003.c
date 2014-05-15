/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int findMaxSubSum(int arr[], int start, int end)
{
    int max, sum;
    max = arr[start];
    sum = 0;
    for(;start < end; start++)
    {
        sum += arr[start];
        if(max < sum)
            max = sum;
        if(sum < 0)
            sum = 0;
    }
    return max;
}
