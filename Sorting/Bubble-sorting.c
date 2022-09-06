#include <stdio.h>
#include <conio.h>
int main()
{
    int array[50];
    int i, j, n;
    printf("how many elements do you want to sort?");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    // main logic of Bubble sorting
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1 - i; j++)

        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    printf("the sorted array is: ");
    for (i = 0; i < n; i++)
    {
        printf("%d\n", array[i]);
    }
    return 0;
}

/* About Bubble sorting:
It works on algorithm that the firt element is compared with the next element array and if smaller then get swapped.

in line 17: there are two methods to put condition, they are:
n-1 only: as there is no element further for the last one to compare so we put n-1 in the condition.
n-1-i: this indicates that after each iteration i, one last element gets sorted. i.e after 1st iteration , the last element gets sorted,
such that after 2nd iteration two last elements get sorted so we need not to compare them. */