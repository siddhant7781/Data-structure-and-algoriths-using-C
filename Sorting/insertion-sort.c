#include <stdio.h>
#include <conio.h>
void insertion(int[], int);
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
    insertion(array, n);                     // calling selection function
    printf("The data items after sorting:"); // printing sorted output
    for (i = 0; i < n; i++)
    {
        printf("%d\t", array[i]);
    }
    return 0;
}

void insertion(int array[], int n)
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        temp = array[i];
        j = i - 1;
        while (temp < array[j] && j >= 0)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = temp;
    }
}