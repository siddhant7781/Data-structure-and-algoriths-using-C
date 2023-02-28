#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *top = NULL;

void push(int x)
{

    struct Node *p = malloc(sizeof(struct Node));

    if (p == NULL)
    {
        printf("stack is full\n");
    }
    else
    {
        p->data = x;
        p->next = top;
        top = p;
    }
}

int pop()
{
    struct Node *p;
    int x = -1;
    if (top == NULL)
    {
        printf("stack is empty\n");
    }
    else
    {
        p = top;
        top = top->next;
        x = p->data;
        free(p);
    }
}

int peak(struct Node *p, int pos)
{
    int i;
    for (i = 0; i < pos - 1 && p != NULL; i++)
    {

        p = p->next;
    }
    if (p != NULL)
        return p->data;
    else
        return -1;
}

int isEmpty()
{
    return top ? 0 : 1;
}

int isFull()
{
    struct Node *p = malloc(sizeof(struct Node));
    return p ? 0 : 1;
}

void display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    push(4);
    push(5);
    push(6);
    push(7);
    display(top);

    printf("After popping\n\n");
    pop();
    printf("Is the stack is empty? %d\n", isEmpty());
    printf("Is the stack is full? %d\n", isFull());
    printf("Displaying Final result:\n");
    display(top);

    return 0;
}