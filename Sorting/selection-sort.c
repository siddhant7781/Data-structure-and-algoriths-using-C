#include <stdio.h>
#include <conio.h>
void selection(int[], int);
int main()
{
    int array[50];
    int n, i;
    printf("enter the no of data items:"); // asking the no of inputs
    scanf("%d", &n);
    printf("enter %d data items", n); // taking inouts of the array
    for (i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    printf("The data items before sorting:"); // printing taken input
    for (i = 0; i < n; i++)
    {
        printf("%d\t", array[i]);
    }
    selection(array, n);                     // calling selection function
    printf("The data items after sorting:"); // printing sorted output
    for (i = 0; i < n; i++)
    {
        printf("%d\t", array[i]);
    }
    return 0;
}

void selection(int array[], int n)
{
    int i, j, least, index, temp;
    for (i = 0; i < n; i++)
    {
        least = array[i];
        index = i;
        for (j = i + 1; j < n; j++)
        {
            if (array[j] < least)
            {
                least = array[j];
                index = j;
            }
        }
        if (i != index)
        {
            temp = array[i];
            array[i] = array[index];
            array[index] = temp;
        }
    }
}