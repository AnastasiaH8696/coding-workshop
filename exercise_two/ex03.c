#include <stdio.h>
#include <stdlib.h>
#include <assert.h> 

//This function is prints a given array
void printArr(int* arr, int size);

//This function is printing the original and the new arrays
void printOrigAndNewArrays(int *origArr, int origSize, int *newArr, int newSize);

//This function is getting original array and its size and return a count of non duplicate numbers
int countNonDup(int *arr, int size);

//This function is getting original array and its size and a pointer to a new array and updates its values
void updateNonDupArr(int *arr, int size, int **nonDupArrPtr);

//This function is getting original array, its size and a size of a new array and returns new array without duplicates
int *RemoveDupAndReturnArray(int *arr, int size, int *nonDupSize);

//This function is getting original array, its size and a pointer to a new array without duplicates and returns new array's size
int RemoveDupAndReturnSize(int *arr, int size, int **nonDupArrPtr);

//This function is getting original array, its size and a pointer to a new array without duplicates its size. It updates the new array and its size
void RemoveDup(int *arr, int size, int **nonDupArrPtr, int *nonDupSize);

//This program is taking existing array and creating a new one wihtout duplicates
int main() {
    int duplicatesArr[] = { 50, 60, 60, 72, 81, 81, 81, 81, 93, 93 }, *nonDupArr, newSize = 1, len = 10;

    //Testing int *RemoveDupAndReturnArray function
    printf("Testing int *RemoveDupAndReturnArray function: \n");
    nonDupArr = RemoveDupAndReturnArray(duplicatesArr, len, &newSize);
    printOrigAndNewArrays(duplicatesArr, len, nonDupArr, newSize);
    free(nonDupArr);

    //Testing int RemoveDupAndReturnSize function
    printf("Testing int RemoveDupAndReturnSize function: \n");
    newSize = RemoveDupAndReturnSize(duplicatesArr, len, &nonDupArr);
    printOrigAndNewArrays(duplicatesArr, len, nonDupArr, newSize);
    free(nonDupArr);

    //Testing void RemoveDup function
    printf("Testing void RemoveDup function: \n");
    RemoveDup(duplicatesArr, len, &nonDupArr, &newSize);
    printOrigAndNewArrays(duplicatesArr, len, nonDupArr, newSize);
    free(nonDupArr);
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

void printOrigAndNewArrays(int *origArr, int origSize, int *newArr, int newSize)
{
    printf("The duplicated array: \n");
    printArr(origArr, origSize);
    printf("The non-duplicated array: \n");
    printArr(newArr, newSize);
    printf("\n");
}

int countNonDup(int *arr, int size)
{
    int count = 1, i;
    for (i = 1; i < size; i++)
    {
        if (arr[i] != arr[i - 1])
        {
            count++;
        }
    }
    return count;
}

void updateNonDupArr(int *arr, int size, int **nonDupArrPtr)
{
    int nonDupIndex = 1, i;
    (*nonDupArrPtr)[0] = arr[0];
    for (i = 1; i < size; i++)
    {
        if (arr[i] != arr[i - 1])
        {
            (*nonDupArrPtr)[nonDupIndex++] = arr[i];
        }
    }
}

int *RemoveDupAndReturnArray(int *arr, int size, int *nonDupSize)
{
    int *nonDupArr;
    (*nonDupSize) = countNonDup(arr, size);

    nonDupArr = (int*)malloc(sizeof(int) * (*nonDupSize));
    assert(nonDupArr);

    updateNonDupArr(arr, size, &nonDupArr);

    return nonDupArr;
}

int RemoveDupAndReturnSize(int *arr, int size, int **nonDupArrPtr)
{
    int nonDupSize = countNonDup(arr, size);
    
    (*nonDupArrPtr) = (int*)malloc(sizeof(int) * nonDupSize);
    assert(*nonDupArrPtr);

    updateNonDupArr(arr, size, nonDupArrPtr);

    return nonDupSize;
}

void RemoveDup(int *arr, int size, int **nonDupArrPtr, int *nonDupSize)
{
    (*nonDupSize) = countNonDup(arr, size);

    (*nonDupArrPtr) = (int*)malloc(sizeof(int) * (*nonDupSize));
    assert(*nonDupArrPtr);

    updateNonDupArr(arr, size, nonDupArrPtr);
}