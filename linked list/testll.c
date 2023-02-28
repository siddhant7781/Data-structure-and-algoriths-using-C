#include<stdio.h>
#include<stdlib.h>


struct Node{
     struct Node *next;
    int data;
   

} *first=NULL;


int main(){

    first=(struct Node*)malloc(sizeof(struct Node));

    first->data=10;
    first->next=NULL;
     printf("%d\t",first);
     printf("%d", &first->data);
     return 0;
}