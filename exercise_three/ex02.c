#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <assert.h> 

#define ADDRESS_SIZE 30

typedef struct {
    char address[ADDRESS_SIZE];
    int rooms;
    double price;
} apart;

//This function counts the number of apartments according to the filter.
int countFilteredApartments(apart* apartments, int size, int rooms, double maxPrice);

//This function gets apart array, its size, filter data: rooms, max price and the size of the future filtered array. It returns new apart array with the filtered data.
apart* createFilter(apart* apartments, int size, int rooms, double maxPrice, int filterSize);

//This function gets apart array, its size, number of rooms, max price. The function creates a new apart array according to the provided data.
void getFilteredApartments(apart* apartments, int size, int rooms, double maxPrice, apart** filter, int* filterSize);

//This function gets pointer to apart array and its size. Inside the function we are getting the data from the user and put the data inside the array.
apart* getApartmentsData(int* size);

//This function prints the data of the apart array
void printApartments(apart* apartments, int size);

void main()
{
    apart* apartments;
    apart* filter;
    int size, rooms, filterSize;
    double maxPrice;

    //Getting data..
    apartments = getApartmentsData(&size);
    printf("Please enter the number of rooms you want: \n");
    scanf("%d", &rooms);
    printf("Please enter the max price you want: \n");
    scanf("%lf", &maxPrice);
    getFilteredApartments(apartments, size, rooms, maxPrice, &filter, &filterSize);

    //Printing..
    printf("The apartments: \n");
    printApartments(apartments, size);
    printf("The filtered apartments: \n");
    printApartments(filter, filterSize);

    free(apartments);
    free(filter);

}

int countFilteredApartments(apart* apartments, int size, int rooms, double maxPrice)
{
    int i, counter = 0;
    for (i = 0; i < size; i++)
    {
        if ((apartments[i].price <= maxPrice) && (apartments[i].rooms == rooms))
        {
            counter++;
        }
    }
    return counter;
}

apart* createFilter(apart* apartments, int size, int rooms, double maxPrice, int filterSize)
{
    apart* filter;
    filter = (apart*)calloc(filterSize, sizeof(apart));
    assert(filter);

    int i, filterI = 0;
    for (i = 0; i < size; i++)
    {
        if ((apartments[i].price <= maxPrice) && (apartments[i].rooms == rooms))
        {
            filter[filterI++] = apartments[i];
        }
    }
    return filter;

}

void getFilteredApartments(apart* apartments, int size, int rooms, double maxPrice, apart** filter, int* filterSize)
{
    *filterSize = countFilteredApartments(apartments, size, rooms, maxPrice);
    *filter = createFilter(apartments, size, rooms, maxPrice, *filterSize);
}

apart* getApartmentsData(int* size)
{
    apart* apartments;
    printf("Enter the size of the array: \n");
    scanf("%d", size);

    apartments = (apart*)calloc(sizeof(apart), *size);
    assert(apartments);

    int i;
    for (i = 0; i < (*size); i++)
    {
        printf("Please enter address: ");
        rewind(stdin);
        gets(apartments[i].address);
        printf("Please enter number of rooms: ");
        scanf("%d", &(apartments[i].rooms));
        printf("Please enter the price : ");
        scanf("%lf", &(apartments[i].price));
        printf("\n\n");
    }

    return apartments;
}

void printApartments(apart* apartments, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("--- Apartment data --- \n");
        printf("Address: %s \n", apartments[i].address);
        printf("Number of rooms: %d \n", apartments[i].rooms);
        printf("Price: %.2lf \n\n", apartments[i].price);
    }
}
