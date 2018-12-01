#include<stdio.h>
#include <stdlib.h>

// counter array of 100 arrays
float COUNTER[100];

// two element swap 
void swap(float* a, float* b)
{
    float temp = *a;
    *a = *b;
    *b = temp;
}


int partition (float a[], int low, int high, int aNum)
{
    float pivot = a[high];    // pivot element
    int i = (low - 1), j;

    for (j = low; j <= high- 1; j++)
    {
        if (a[j] <= pivot)
        {
           COUNTER[aNum]++;
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[high]);
    return (i + 1);
}

void quickSort(float a[], int low, int high, int aNum)
{
    if (low < high)
    {
        
        int pindex = partition(a, low, high, aNum);
        quickSort(a, low, pindex - 1, aNum);
        quickSort(a, pindex + 1, high, aNum);
    }
}

/* Function to print an array */
void printarray(float a[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%f ", a[i]);
    printf("\n");
}

int main(){
    float a[100][16], sum = 0.0, avg;
    int i, j;
    for(i=0; i<100; i++){
       for(j=0;j < 16; j++){
           a[i][j] = 1.0* ((float) rand() / RAND_MAX);// generating random REAL NUMBERS between 0 and 1
       }
    }
    // printing the 100 arrays
    for(i=0; i<100; i++){
       printf("array-%d: ", i+1);
       printarray(a[i], 16);
    }
    for(i=0; i<100; i++){
       quickSort(a[i], 0, 15, i);
       printf("Sorted array-%d: ", i+1);
       printarray(a[i], 16);
    }
    // calculating the average
    for(i=0; i<100; i++){
       sum += COUNTER[i];
    }
    avg = sum/98.0;
    // printing the average
   printf("Average: %f \n", avg);
    return 0;
}
