#include <stdio.h>
#include <stdlib.h>
#include <assert.h> 

#define DATA_SIZE 5

typedef struct student_init_data {
    int id;
    int *grades;
    int numOfExams;
} studentData;

typedef struct student_processed_data {
    int id;
    float avg;
} studentAvg;

typedef struct statistics {
    studentAvg *groupOne;
    studentAvg *groupTwo;
    int gOneSize;
    int gTwoSize;
    float avg;
}statistics;

//This function is creating grades array with a given size.
int * Input_Data(int numOfExams);

//This function is getting an array of grades and its size and calculates the average.
float Student_Average(int *grades, int numOfExams);

//This function is getting an array of averages and calculate its average.
float Total_Average(studentAvg *avg, int size);

//This function is counts the amount of students with avg above the avg
int countAboveAvg(studentAvg *students, int size, float avg);

//This function is adding the data to the two groups
void updateGroups(studentData *data, int size, statistics* groups);

//This function is getting statistics by reference,and creates the two groups by using the other functions.
void Classification(studentData *data, int size, statistics* groups);

//Prints the data of the group
void printGroup(studentAvg* students, int size);

//Prints the data of the statistics
void Print_Tab(statistics* groups);

//This function frees all the data
void Free_Memory(studentData *data, int size, statistics *groups);

void main()
{
    studentData data[DATA_SIZE];
    statistics groups;
    int i, j;
    for(i = 0; i<DATA_SIZE; i++)
    {
        printf("Please enter ID and number of exams \n");
        scanf("%d", &(data[i].id));
        scanf("%d", &(data[i].numOfExams));
        data[i].grades = Input_Data(data[i].numOfExams);
    }
    Classification(data, DATA_SIZE, &groups);
    Print_Tab(&groups);
    Free_Memory(data, DATA_SIZE, &groups);

}

int * Input_Data(int numOfExams)
{
    int i;
    int *grades = (int*)malloc(sizeof(int)*numOfExams);
    assert(grades);

    for(i=0; i<numOfExams; i++)
    {
        printf("Please enter a grade: \n");
        scanf("%d", &grades[i]);
    }
    return grades;
}

float Student_Average(int *grades, int numOfExams)
{
    int sum = 0;
    int i;

    for(i=0; i<numOfExams; i++)
    {
        sum+=grades[i];
    }
    return sum/numOfExams;
}

float Total_Average(studentAvg *avg, int size)
{
    float sum = 0;
    int i;

    for(i=0; i<size; i++)
    {
        sum+= avg[i].avg;
    }
    return sum/size;
}

int countAboveAvg(studentAvg *students, int size, float avg)
{
    int i, count = 0;
    
    for(i=0; i<size; i++)
    {
        if(students[i].avg >= avg)
        {
            count++;
        }
    }

    return count;

}

void updateGroups(studentData *data, int size, statistics* groups)
{
    int i, iGroupOne = 0, iGroupTwo = 0;
    float currAvg;
    for(i=0; i<size; i++)
    {
        currAvg = Student_Average(data[i].grades, data[i].numOfExams);
        if(currAvg >= groups->avg)
        {
            groups->groupTwo[iGroupTwo].id = data[i].id;
            groups->groupTwo[iGroupTwo++].avg = currAvg;
            
        }
        else
        {
            groups->groupOne[iGroupOne].id = data[i].id;
            groups->groupOne[iGroupOne++].avg = currAvg; 
        }
    }

}

void Classification(studentData *data, int size, statistics* groups)
{
    int i, belowSize, aboveSize;
    float avg;
    studentAvg *allStudents = (studentAvg*)malloc(sizeof(studentAvg)*size);
    assert(allStudents);

    for(i=0; i<size; i++)
    {
        allStudents[i].id = data[i].id;
        allStudents[i].avg = Student_Average(data[i].grades, data[i].numOfExams);
    }

    avg = Total_Average(allStudents, size);
    aboveSize = countAboveAvg(allStudents, size, avg);
    belowSize = size - aboveSize;
    free(allStudents);

    groups->groupOne = (studentAvg*)malloc(sizeof(studentAvg)*belowSize);
    assert(groups->groupOne);
    groups->groupTwo = (studentAvg*)malloc(sizeof(studentAvg)*aboveSize);
    assert(groups->groupTwo);
    
    groups->gOneSize = belowSize;
    groups->gTwoSize = aboveSize;
    groups->avg = avg;

    updateGroups(data, size, groups);
}

void printGroup(studentAvg* students, int size)
{
    int i;
    for(i=0; i<size; i++)
    {
        printf("Student ID: %d \nStudent average: %f \n\n", students[i].id, students[i].avg);
    }
}

void Print_Tab(statistics* groups)
{
    int i;
    printf("Below the average group data: \n");
    printGroup(groups->groupOne, groups->gOneSize);
    printf("Above the average group data: \n");
    printGroup(groups->groupTwo, groups->gTwoSize);
}

void Free_Memory(studentData *data, int size, statistics *groups)
{
    int i;
    for(i=0; i<size; i++)
    {
        free(data[i].grades);
    }
    free(groups->groupOne);
    free(groups->groupTwo);
}