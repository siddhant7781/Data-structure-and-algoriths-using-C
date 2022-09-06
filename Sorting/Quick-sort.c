// logic and concept:
/*The pivot is in fixed position.
All the left elements are less.
The right elements are greater than pivot.
Now, divide the array into 2 sub arrays left part and right part.
Take left partition apply quick sort.*/

#include <stdio.h>
#include <conio.h>
int partition(int array[10],int l,int r)
{
int x=l;
int y=r;
int p=array[l],temp;
while(x<y)
{
    while(array[x]<=p)
    x++;
    while(array[y]>p)
    y--;
    if(x<y)
    {
        temp=array[x];
        array[x]=array[y];
        array[y]=temp;
    }

}
array[l]=array[y];
array[y]=p;
return y;
}

void quick(int array[10], int l, int r)
{
int p;
if(l<r)
{
    p=partition(array, l,r);
    quick(array,l,p-1);
    quick(array,p+1,r);
}
}

int main()
{
    int array[50];
    int n, i,l,r;
    printf("enter the no of data items:"); // asking the no of inputs
    scanf("%d", &n);
    printf("enter %d data items", n); // taking inouts of the array
    l=0;
    r=n-1;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    printf("The data items before sorting:"); // printing taken input
    for (i = 0; i < n; i++)
    {
        printf("%d\t", array[i]);
    }
    quick(array,l,r);                     // calling selection function
    printf("The data items after sorting:"); // printing sorted output
    for (i = 0; i < n; i++)
    {
        printf("%d\t", array[i]);
    }
    return 0;
}

