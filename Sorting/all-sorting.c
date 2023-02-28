#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/*void swap( int *p, int *q){
    int *temp;
    temp=p;
    p=q;
    q=temp;
}*/
// bubble sorting function;
void bubbleSort(int a[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
// insertion sorting function
void insertionSort(int a[], int n)
{
    int i, j, temp;
    for (int i = 1; i < n; i++)
    {
        temp = a[i]; // temporary stores/picks the value to be inserted or checked
        j = i - 1;   // j is the  just previous value in the array where the comparison shoud be started.
        while (j >= 0 && a[j] > temp)
        {                    // loop will continue until the j is greater than picked value
            a[j + 1] = a[j]; // shifts value to the right
            j--;
        }
        a[j + 1] = temp;
    }
    // loop will stop when it comes to right place and there is a vacant space to insert cause previous was shifted.
}
// selection sorting function
void selectionSort(int a[], int n)
{
    int i, j, k, temp; // i,j,k points to the same  at first and temp is for swap .
    for (i = 0; i < n; i++)
    {
        for (j = k = i; j < n; j++) // i j k pointing to the same, j moves for and compare every element with a[k] and updates the value of k to the  with the index of smallest value  by looping.
        {
            if (a[j] < a[k])
            {

                k = j;
            }
        }
        // loop ended and first element that is a[i] is swapped with least value stored in a[k];
        temp = a[i];
        a[i] = a[k];
        a[k] = temp;
    } // again pass moves and i j k points to the next index.
}

int main()
{
    int i;
    int a[] = {6, 4, 7, 9, 12, 45, 34, 66, 28, 41};
    int b[] = {23, 45, 67, 21, 33, 10, 11, 24, 54, 37};
    int c[] = {2, 9, 6, 38, 22, 49, 57, 11, 50, 10};
    int n = 10;
    bubbleSort(a, n);
    printf("After sorting Using Bubble sort, value of array a is :\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    };
    printf("\n");
    printf("\n");

    insertionSort(b, n);
    printf("After sorting Using insertion sort, value of array b is :\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", b[i]);
    };

    printf("\n");
    printf("\n");

    selectionSort(c, n);
    printf("After sorting Using selection sort, value of array c is :\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", c[i]);
    };
    return 0;
}