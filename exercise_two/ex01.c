#include <stdio.h>
#include <stdlib.h>
#include <assert.h> 

//This function is prints a given array
void printArr(int* arr, int size);

//This function is getting an array, its size and two counters which will be updated by the following:
//One will count the odd numbers in array and the other one will count the even numbers in array
void updateOddAndEvenSize(int *arr, int size, int *oddCounter, int *evenCounter);

//This function is getting original array, empty odd numbers array, empty even numbers array and their sizes
//And updates the values of the arrays
void updateOddAndEvenArraysValues(int *arr, int size, int **oddArrayPtr, int **evenArrayPtr);

//This function is getting an array, its size, another array and its size
// and creates two arrays from the original - one with odd numbers and one with even
int *createOddAndEvenArrays(int *arr, int size, int **oddArrayPtr, int *oddSize, int *evenSize);

//This program is taking existing array and creating two arrays - odd numbers array and even numbers array
int main() {
    int arr[] = { 6 , 57 , 14 , 21 , 11 , 3, 22, 42 , 9 , 15 }, *oddArr, *evenArr,
        evenSize = 0, oddSize = 0, len = 10;
    evenArr = createOddAndEvenArrays(arr, len, &oddArr, &oddSize, &evenSize);

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

void updateOddAndEvenSize(int *arr, int size, int *oddCounter, int *evenCounter)
{
    int i = 0;
    for (i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0)
        {
            (*evenCounter)++;
        }
    }
    *oddCounter = size - (*evenCounter);
}

void updateOddAndEvenArraysValues(int *arr, int size, int **oddArrayPtr, int **evenArrayPtr)
{
    int i = 0, evenIndex = 0, oddIndex = 0;
    for (i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0)
        {
            (*evenArrayPtr)[evenIndex++] = arr[i];
        }
        else
        {
            (*oddArrayPtr)[oddIndex++] = arr[i];
        }

    } 
}

int *createOddAndEvenArrays(int *arr, int size, int **oddArrayPtr, int *oddSize, int *evenSize)
{
    int *evenArr;
    (*oddSize) = (*evenSize) = 0;

    //Getting the size of odd and even arrays
    updateOddAndEvenSize(arr, size, oddSize, evenSize);

    //Allocation
    (*oddArrayPtr) = (int*)malloc(sizeof(int) * (*oddSize));
    assert(*oddArrayPtr);
    evenArr = (int*)malloc(sizeof(int) * (*evenSize));
    assert(evenArr);

    updateOddAndEvenArraysValues(arr, size, oddArrayPtr, &evenArr);

    return evenArr;
}