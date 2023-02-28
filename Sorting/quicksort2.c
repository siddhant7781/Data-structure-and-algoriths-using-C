// Online C compiler to run C program online
#include <stdio.h>

int partition(int a[], int l, int h)
{ // l= lowest index of array, h= highest index
    int pivot = a[l];
    int i = l;
    int j = h;
    int temp;

    do

    {

        do
        {
            i++;
        } while (a[i] <= pivot);

        do
        {
            j--;
        } while (a[j] > pivot);
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (i < j);
    temp = a[l];
    a[l] = a[j];
    a[j] = temp;
    return j;
}

void quickSort(int a[], int l, int h)
{
    if (l < h)
    {
        int j = partition(a, l, h);
        quickSort(a, l, j);
        quickSort(a, j + 1, h);
    }
}
int main()
{
    int i;
    int a[] = {12, 3, 5, 65, 23, 12, 34, 76, 22, 100};
    int n = 10;

    quickSort(a, 0, 10);
    printf(" the sortes array is :\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    return 0;
}