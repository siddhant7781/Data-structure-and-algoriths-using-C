#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *lchild;
    struct Node *rchild;
} *root = NULL;

// insert operation
void insert(int key)
{
    struct Node *t = root;
    struct Node *r = NULL, *p;

    if (root == NULL)
    {
        p = (struct Node *)malloc(sizeof(struct Node));
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }
    while (t != NULL)
    {
        r = t;
        if (key < t->data)
            t = t->lchild;
        else if (key < t->data)
            t = t->rchild;
        else
            return;
    }
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = key;
    p->lchild = p->rchild = NULL;
    if (key < r->data)
        r->lchild = p;
    else
        r->rchild = p;
}
// inorder traversal of BST = always gives sorted elements.
void Inorder(struct Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        printf("%d \t", p->data);
        Inorder(p->rchild);
    }
}
// searching operation
struct Node *search(int key)
{
    struct Node *t = root;
    while (t != NULL)
    {
        if (key == t->data)
            return t;
        else if (key < t->data)
            t = t->lchild;
        else if (key < t->data)
            t = t->rchild;
    }
    return NULL;
}

// inserting operation using recursive approach
struct Node *Rinsert(struct Node *p, int key)
{
    struct Node *t = NULL;
    if (p == NULL)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }

    if (key < p->data)
        p->lchild = Rinsert(p->lchild, key);
    if (key > p->data)
        p->rchild = Rinsert(p->rchild, key);
    return p;
}

// function to find out the height of BST .
int Height(struct Node *p)
{
    int x, y;
    if (p == NULL)
        return 0;
    x = Height(p->lchild);
    y = Height(p->rchild);
    return x > y ? x + 1 : y + 1;
}

// function to find Inorder precedor
struct Node *InPre(struct Node *p)
{
    while (p && p->rchild != NULL)
        p = p->rchild;

    return p;
}

// function to find the Inorder succesor
struct Node *InSuc(struct Node *p)
{
    while (p && p->lchild != NULL)

        p = p->lchild;

    return p;
}

struct Node *Delete(struct Node *p, int key)
{
    struct Node *q;
    if (p == NULL)
        return NULL;
    if (p->lchild == NULL && p->rchild == NULL)
    { //// if p is a leaf node
        if (p == root)
            root = NULL;
        free(p);
        return NULL;
    }

    if (key < p->data)
        p->lchild = Delete(p->lchild, key);
    else if (key > p->data)
        p->rchild = Delete(p->rchild, key);
    else
    {
        if (Height(p->lchild) > Height(p->rchild))
        {
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        }
        else
        {
            q = InSuc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }
    return p;
}

int main()
{
    struct Node *temp;
    root = Rinsert(root, 10);
    Rinsert(root, 5);
    Rinsert(root, 30);
    Rinsert(root, 20);
    Rinsert(root, 8);
    Rinsert(root, 15);

    // Delete(root, 30);

    Inorder(root);
    printf("\n");

    temp = search(20);
    if (temp != NULL)
        printf("element %d is found \n", temp->data);
    else
        printf("element is not found.\n");
    return 0;
}