#include <stdio.h>
#include <stdlib.h>
// defining the Node
struct Node
{
    int data;
    struct node *next;
} * head;
void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = head;
    last = head;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p)
{

    do
    {
        printf("%d", p->data);
        p = p->next;
        printf("\t");
    } while (p != head);
}

// counting the nodes
int count(struct Node *p)
{
    int c = 0;
    do
    {
        c++;
        p = p->next;
    } while (p != head);
    return c;
}

// inserting the node at any position

void insert(struct Node *p, int index, int x)
{
    int i;
    struct Node *t;
    if (index < 0 || index > count(p))
        return;
    if (index == 0)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        if (head == NULL)
        {
            head = t;
            head->next = head;
        }
        else
        {

            while (p->next != head)
            {
                p = p->next; // for traversing till last node.
            }
            p->next = t;
            t->next = head;
            head = t;
        }
    }

    else
    {
        for (i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}
// deleting the Node

void delete (struct Node *p, int index)
{
    int i, x;
    struct Node *q;
    if (index < 0 || index > count(p))
        return -1;

    if (index == 0)
    {
        while (p->next != head)
            p = p->next;
        x = head->data;
        if (head == p)
        {
            free(head);
            head = NULL;
        }
        else
        {
            p->next = head->next;
            free(head);
            head = p->next;
        }
    }
    else
    {
        for (i = 0; i < index - 2; i++)
        {
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        x = q->data;
        free(q);
    }
    return x;
}

int main()
{
    int A[] = {1, 3, 5, 7, 9};
    create(A, 5);
   // printf("after inserting:");
   // insert(head, 3, 50);
   // delete (head, 1);
    display(head);
    return 0;
}