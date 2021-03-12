#include <stdio.h>
#include <stdlib.h>
#include <assert.h> 

//This function is prints a given array
void printArr(int* arr, int size);

//This program is taking existing array and creating two arrays - odd numbers array and even numbers array
int main() {
    int arr[] = { 6 , 57 , 14 , 21 , 11 , 3, 22, 42 , 9 , 15 }, *oddArr, *evenArr,
        evenSize = 0, oddSize = 0, i = 0, evenIndex = 0, oddIndex = 0, len = 10;


    for (i = 0; i < len; i++)
    {
        if (arr[i] % 2 == 0)
        {
            evenSize++;
        }
    }

    oddSize = len - evenSize;

    oddArr = (int*)malloc(sizeof(int) * oddSize);
    assert(oddArr);
    evenArr = (int*)malloc(sizeof(int) * evenSize);
    assert(evenArr);

    for (i = 0; i < len; i++)
    {
        if (arr[i] % 2 == 0)
        {
            evenArr[evenIndex++] = arr[i];
        }
        else
        {
            oddArr[oddIndex++] = arr[i];
        }
    }

    printf("The original array: \n");
    printArr(arr, len);
    printf("The odd array: \n");
    printArr(oddArr, oddSize);
    printf("The even array: \n");
    printArr(evenArr, evenSize);

    free(oddArr);
    free(evenArr);

}

void printArr(int* arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}