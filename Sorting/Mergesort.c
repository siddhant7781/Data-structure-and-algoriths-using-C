#include <stdio.h>
#include <conio.h>

int merge(int a[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;
    int c[50];
    while (i <= mid && j <= high) // till the end of any array
    {
        if (a[i] < a[j]) // compare the element and put the smallest in new array C and index thier index which block executes
        {
            c[k] = a[i];
            k++;
            i++;
        }
        else
        {
            c[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid) // for copying remaining elements array if another array has ended
    {
        c[k] = a[i];
        k++;
        i++;
    }
    while (j <= high) // for copying remaining elements next array if first array has ended
    {
        c[k] = a[j];
        k++;
        j++;
    }
    for (i = low; i <= high; i++) // for copying the value of array C int array C
    {
        a[i] = c[i];
    }
}

void mergeSort(int a[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(a, low, mid);      // does for left side from mid point
        mergeSort(a, mid + 1, high); // for right side from mid point
        merge(a, low, mid, high);
    }
}

void main()
{
    int a[] = {6, 3, 7, 12, 42, 11, 23, 10, 41, 53};
    int n = 10;
    mergeSort(a, 0, 9);
    printf("the sorted array is: \n");

    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
}
