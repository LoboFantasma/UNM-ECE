#include<stdio.h>

#ifndef max
    #define max(a,b) ((a) > (b) ? (a) : (b))
#endif

int maximum(int arr[], int n)
{
    int i;
    int result = arr[0];
    for (i = 1; i < n; i++)
        result = max(result, arr[i]);

    return result;
}

int kadane(int arr[], int n)
{
    int maxNum = maximum(arr, n);

    if (maxNum < 0)
        return maxNum;
    
    int maxCurr = 0;
    
    int maxEnd = 0;

    int i;
    
    for (i = 0; i < n; i++)
    {
        maxEnd = maxEnd + arr[i];

        maxEnd = max(maxEnd, 0);

        maxCurr = max(maxCurr, maxEnd);
    }

    return maxCurr;
}

// test function
int main()
{
    int arr[] = { 13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7 };
    int arr2[] = { -5,-42,-7,-88,-1,-10,-97,-16,-2,-23,-12,-25,-24,-15,-37,-7};
    int arr3[] = { 5,42,7,88,1,10,97,16,2,23,12,25,24,15,37,7};
    int n = sizeof(arr)/sizeof(arr[0]);
	int max_sum_mix = kadane(arr, n);
	int max_sum_neg = kadane(arr2, n);
    int max_sum_pos = kadane(arr3, n);
    
    printf("\n The Max Sum of the Mixed Sub-Array: %d \n", max_sum_mix);
    printf("\n The Max Sum of the Negative Sub-Array: %d \n", max_sum_neg);
    printf("\n The Max Sum of the Positive Sub-Array: %d \n", max_sum_pos);
    return 0;
}
