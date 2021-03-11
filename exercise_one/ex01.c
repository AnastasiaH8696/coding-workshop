#include <stdio.h>
#include <stdlib.h>
#include <assert.h> 


void printArr(int* arr, int size);

int main() {
    int duplicatesArr[] = { 50, 60, 60, 72, 81, 81, 81, 81, 93, 93 }, * nonDupArr,
        newSize = 1, i = 0, nonDupIndex = 0, len = 10;


    for (i = 1; i < len; i++)
    {
        if (duplicatesArr[i] != duplicatesArr[i - 1])
        {
            newSize++;
        }
    }

    nonDupArr = (int*)malloc(sizeof(int) * newSize);
    assert(nonDupArr);
    nonDupArr[nonDupIndex++] = duplicatesArr[0];

    for (i = 1; i < len; i++)
    {
        if (duplicatesArr[i] != duplicatesArr[i - 1])
        {
            nonDupArr[nonDupIndex++] = duplicatesArr[i];
        }
    }

    printf("The duplicated array: /n");
    printArr(duplicatesArr, len);
    printf("The non-duplicated array: /n");
    printArr(nonDupArr, nonDupIndex);

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