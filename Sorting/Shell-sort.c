#include<stdio.h>
#include<conio.h>

void shellSort(int a[], int n){
int gap,temp,i;
for(gap=n/2; gap>1;gap/=2){
    temp=a[i];
    
}

}

int main(){

    int a[] = {6, 3, 7, 12, 42, 11, 23, 10, 41, 53};
    int n = 10;
    shellSort(a,10);
    printf("the sorted array is: \n");

    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
}