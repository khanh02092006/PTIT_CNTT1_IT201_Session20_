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
void postorder(node *root)
{
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}


int main(void)
{
   node *root = create_node();
    root->left=create_node();
    root->right=create_node();
    root->left->left=create_node();
    postorder(root);



    return 0;
}