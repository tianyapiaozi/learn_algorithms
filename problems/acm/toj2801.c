#include <stdio.h>
#include <string.h>
#include <ctype.h>
typedef struct node
{
    struct node *left, *right;
    char ch;
} node;
node freel[1001];
node *stack[1001];
void inorder(node *root)
{
    if(root->left)
    {
        inorder(root->left);
    }
    printf("%c", root->ch);
    if(root->right)
    {
        inorder(root->right);
    }
}
int main(int argc, char *argv[])
{
    int t, nindex, top = -1;
    char str[1001], *p;
    node *newnode, *root;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%s", str);
        nindex = 0;
        top = -1;
        for(p = str; *p; p++)
        {
            newnode = &freel[nindex++];
            newnode->ch = *p;
            if(islower(*p))
            {
                newnode->left = newnode->right = NULL;
                stack[++top] = newnode;
            }
            else
            {
                newnode->left = stack[top-1];
                newnode->right = stack[top];
                stack[top-1] = newnode;
                top--;
            }
        }
        root = stack[0];
        inorder(root);
        printf("\n");
    }
    return 0;
}
