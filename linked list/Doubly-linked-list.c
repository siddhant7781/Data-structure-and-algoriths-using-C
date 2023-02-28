#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} *first = NULL;

// creating the linked list;
void create(int A[], int n)
{
    struct Node *t, *last;
    int i;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->prev = NULL;
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

int display(struct Node *p)
{
    while (p)
    {
        printf("%d \t", p->data);
        p = p->next;
    }
}

int count(struct Node *p)
{
    int c = 0;
    while (p)
    {
        c++;
        p = p->next;
    }
    return c;
}

void insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;
    if (index < 0 || index > count(p))
        return;
    if (index == 0)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->prev = p;
        t->next = p->next;
        if (p->next)
        {
            p->next->prev = t;
        }
        p->next = t;
    }
}

void delete (struct Node *p, int index)
{
    struct Node *q;
    int i, x;
    if (index < 1 || index > count(p))
        return -1;
    if (index == 1)
    {
        first = first->next;
        if (first)
        {
            first->prev = NULL;
            x = p->data;
            free(p);
        }
        else
        {
            for (i = 0; i < index - 1; i++)
            {
                p = p->next;
            }
            p->prev->next = p->next;
            if (p->next)
            {
                p->next->prev = p->prev;
            }
            x = p->data;
            free(p);
        }
        return x;
    }
}
int reverse(){
    
}

int main()
{
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    create(A, 9);
    display(first);
    // printf("%d",count(first));
    printf("\n");
    insert(first, 6, 99);
    display(first);
    return 0;
}