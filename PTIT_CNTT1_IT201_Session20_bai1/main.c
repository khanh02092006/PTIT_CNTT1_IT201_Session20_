#include <stdio.h>
#include <stdlib.h>
typedef  struct node
{
    int data;
    struct node *left;
    struct node *right;

}node;
node *create_node()
{
    int value;
    printf(" nhap so nguyen cho phan tu");
    scanf("%d",&value);
    node *newnode = (node *)malloc(sizeof(node));
    if(newnode == NULL) return NULL;
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;

}


int main(void)
{
    node* n=create_node()
    printf(" da tao node",n->data);


    return 0;
}