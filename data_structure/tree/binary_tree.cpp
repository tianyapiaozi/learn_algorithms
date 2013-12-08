#include "binary_tree.h"
#include <cstdio>
void BinaryTree::InOrderHelper(TreeNode *root)
{
    if(!root)
    {
        return;
    }
    printf("%d ", root->value);
    if(root->left)
    {
        InOrderHelper(root->left);
    }
    if(root->right)
    {
        InOrderHelper(root->right);
    }
}
void BinaryTree::PostOrderHelper(TreeNode *root)
{
    if(!root)
    {
        return;
    }
    if(root->left)
    {
        PostOrderHelper(root->left);
    }
    if(root->right)
    {
        PostOrderHelper(root->right);
    }
    printf("%d ", root->value);
}
void BinaryTree::PreOrderHelper(TreeNode *root)
{
    if(!root)
    {
        return;
    }
    if(root->left)
    {
        PreOrderHelper(root->left);
    }
    printf("%d ", root->value);
    if(root->right)
    {
        PreOrderHelper(root->right);
    }
}

void BinaryTree::DeallocateTree(TreeNode *root)
{
    if(!root)
    {
        return;
    }
    DeallocateTree(root->left);
    DeallocateTree(root->right);
    delete root;
}

void bst_print_dot_null(int value, int nullcount, FILE* stream)
{
    fprintf(stream, "    null%d [shape=point];\n", nullcount);
    fprintf(stream, "    %d -> null%d;\n", value, nullcount);
}

void bst_print_dot_aux(TreeNode* node, FILE* stream)
{
    static int nullcount = 0;

    if (node->left)
    {
        fprintf(stream, "    %d -> %d;\n", node->value, node->left->value);
        bst_print_dot_aux(node->left, stream);
    }
    else
        bst_print_dot_null(node->value, nullcount++, stream);

    if (node->right)
    {
        fprintf(stream, "    %d -> %d;\n", node->value, node->right->value);
        bst_print_dot_aux(node->right, stream);
    }
    else
        bst_print_dot_null(node->value, nullcount++, stream);
}

void bst_print_dot(TreeNode* tree, FILE* stream)
{
    fprintf(stream, "digraph BST {\n");
    fprintf(stream, "    node [fontname=\"Arial\"];\n");

    if (!tree)
        fprintf(stream, "\n");
    else if (!tree->right && !tree->left)
        fprintf(stream, "    %d;\n", tree->value);
    else
        bst_print_dot_aux(tree, stream);

    fprintf(stream, "}\n");
}

void BinaryTree::GenerateGraphvizFile(const char *filename)
{
    if(!filename)
    {
        return;
    }
    FILE *out = fopen(filename, "w");
    if(out == NULL)
    {
        fprintf(stderr, "open file %s failed", filename);
        return ;
    }
    bst_print_dot(root, out);
    fclose(out);
}
