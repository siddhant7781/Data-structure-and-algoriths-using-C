#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    int *s;
};

void create(struct stack *stk)
{
    printf("Enter the size of stack:");
    scanf("%d", &stk->size);
    stk->top = -1; // top is pointing outside of stack right now
    stk->s = (int *)malloc(stk->size * sizeof(int));
}

void display(struct stack stk)
{
    int i;
    for (i = stk.top; i >= 0; i--)
    {
        printf("%d", stk.s[i]);
        printf("\n");
    }
}

void push(struct stack *stk, int x)
{
    if (stk->top == stk->size - 1)
    {
        printf("stack overflow");
    }
    else
    {
        stk->top++;
        stk->s[stk->top] = x;
    }
}

void pop(struct stack *stk)
{
    int x = -1;
    if (stk->top = -1)
    {
        printf("stack underflowed");
    }
    else
    {

        x = stk->s[stk->top--];
    }
}

int peek(struct stack stk,int pos){

    //to do....
    
}

int isEmpty(struct stack stk){
    if(stk.top==-1){
        return 1;
    }
        else return 0;
    
}

int isFull(struct stack stk){
    if(stk.top==stk.size-1){
        return 1;
    }
        else return 0;
    
}

int stackTop(struct stack stk){
    if(!isEmpty(stk)){
        return stk.s[stk.top];
    }
    else return -1;
}


int main()
{
    struct stack st;
    create(&st);

    
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);
    

    display(st);
    return 0;
}
