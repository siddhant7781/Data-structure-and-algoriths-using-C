/*
implement the following tree directly:

                            9
                         /     \
                         8      7
                       /  \    /  \
                      5    4  3    2

*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{ 
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->left = temp->right = NULL;
    return temp;
}
void inorder(struct Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d", root->data);
    inorder(root->right);
    return;
}

void preorder(struct Node *root)
{
    if (root == NULL)
        return;
    printf("%d", root->data);
    preorder(root->left);
    preorder(root->right);
    return;
}

void postorder(struct Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d", root->data);
    return;
}

int main()
{
    struct Node *root = NULL;
    root = createNode(9);
    root->left = createNode(8);
    root->right = createNode(7);
    root->left->left = createNode(5);
    root->left->right = createNode(4);
    root->right->left = createNode(3);
    root->right->right = createNode(2);

    inorder(root);
    printf("\n");

    preorder(root);
    printf("\n");

    postorder(root);
    printf("\n");
}
