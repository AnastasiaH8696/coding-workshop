#include <stdio.h>
#include <stdlib.h>
#include <assert.h> 

//This function is prints a given array
void printArr(char* arr, int size);

//This function is getting an array, its size and two counters which will be updated by the following:
//One will count the small letters in array and the other one will count the big letters in array
void updateSmallAndBigLettersSize(char *arr, int size, int *smallCounter, int *bigCounter);

//This function is getting original array, empty small letters array, empty big letters array and their sizes
//And updates the values of the arrays
void updateSmallAndBigLettersValues(char *arr, int size, char **smallLettersArrPtr, char **bigLettersArrPtr);

//This function is getting an array, its size, another array and its size
// and creates two arrays from the original - one with small letters and one with big letters
void createSmallAndBigLettersArrays(char *arr, int size, char **smallLettersArrPtr, int *smallSize, char **bigLettersArrPtr, int *bigSize);

//This program is taking existing array and creating two arrays - odd numbers array and even numbers array
int main() {
    char arr[] = { 'A' , 'a' , 'B' , 'b' , 'C' , 'c', 'D', 'd' , 'E' , 'F' }, *smallLettersArr, *bigLettersArr,
        smallSize = 0, bigSize = 0, len = 10;
    createSmallAndBigLettersArrays(arr, len, &smallLettersArr, &smallSize, &bigLettersArr, &bigSize);

    printf("The original array: \n");
    printArr(arr, len);
    printf("The small letters array: \n");
    printArr(smallLettersArr, smallSize);
    printf("The big lettes array: \n");
    printArr(bigLettersArr, bigSize);

    free(smallLettersArr);
    free(bigLettersArr);
}

void printArr(char* arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%c\t", arr[i]);
    }
    printf("\n");
}

void updateSmallAndBigLettersSize(char *arr, int size, int *smallCounter, int *bigCounter)
{
    int i = 0;
    for (i = 0; i < size; i++)
    {
        if ((arr[i] >= 'a') && (arr[i] <= 'z'))
        {
            (*smallCounter)++;
        }
        else if((arr[i] >= 'A') && (arr[i] <= 'Z'))
        {
            (*bigCounter)++;
        }
    }
}

void updateSmallAndBigLettersValues(char *arr, int size, char **smallLettersArrPtr, char **bigLettersArrPtr)
{
    int i = 0, smallLettersIndex = 0, bigLettersIndex = 0;
    for (i = 0; i < size; i++)
    {
        if ((arr[i] >= 'a') && (arr[i] <= 'z'))
        {
            (*smallLettersArrPtr)[smallLettersIndex++] = arr[i];
        }
        else if((arr[i] >= 'A') && (arr[i] <= 'Z'))
        {
            (*bigLettersArrPtr)[bigLettersIndex++] = arr[i];
        }
    }
}

void createSmallAndBigLettersArrays(char *arr, int size, char **smallLettersArrPtr, int *smallSize, char **bigLettersArrPtr, int *bigSize)
{
    int *evenArr;
    (*smallSize) = (*bigSize) = 0;

    //Getting the size of odd and even arrays
    updateSmallAndBigLettersSize(arr, size, smallSize, bigSize);

    //Allocation
    (*smallLettersArrPtr) = (char*)malloc(sizeof(char) * (*smallSize));
    assert(*smallLettersArrPtr);
    (*bigLettersArrPtr) = (char*)malloc(sizeof(char) * (*bigSize));
    assert(*bigLettersArrPtr);

    updateSmallAndBigLettersValues(arr, size, smallLettersArrPtr, bigLettersArrPtr);

}