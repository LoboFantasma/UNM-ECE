// MergeSort

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

const int MAX_SIZE = 8;
void display(int intArray[], int n)
{
    int i;
    printf("Array Content: \n");
    printf("----------------------\n");
    for(i = 0; i < n; ++i)
    {
        printf("%4d", intArray[i]);
    }
    printf("\n");
}
void mergeFunction(int intArray[], int tempArray[], int leftIndex, int midIndex, int rightIndex)
{
    int i, j, k;
    for(i = leftIndex, j = midIndex+1, k = leftIndex; i <= midIndex && j <= rightIndex; ++k)
    {
        if (intArray[i] <= intArray[j])
        {
            tempArray[k] = intArray[i];
            i++;
        }
        else
        {
            tempArray[k] = intArray[j];
            j++;
        }
    }
    while(i <= midIndex)
    {
        tempArray[k] = intArray[i];
        k++; i++;
    }
    while(j <= rightIndex)
    {
        tempArray[k] = intArray[j];
        k++; j++;
    }
    for(i = leftIndex; i <= rightIndex; ++i)
    {
        intArray[i] = tempArray[i];
    }
}
void implementMerge_Sort(int intArray[], int tempArray[], int leftIndex, int rightIndex)
{

    if (leftIndex >= rightIndex)
        return;
    int midIndex = (leftIndex+rightIndex)/2;
    implementMerge_Sort(intArray, tempArray, leftIndex, midIndex);
    implementMerge_Sort(intArray, tempArray, midIndex + 1, rightIndex);
    mergeFunction(intArray, tempArray, leftIndex, midIndex, rightIndex);
    display(intArray, MAX_SIZE);
}
int main()
{

    int intArray[] = {42, 23, 9, 169, 626, 73, 55 , 143};
    int tempArray[MAX_SIZE];
    implementMerge_Sort(intArray, tempArray, 0, MAX_SIZE - 1);
    return 0;
}
