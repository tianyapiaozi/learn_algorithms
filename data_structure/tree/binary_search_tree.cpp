#include "binary_search_tree.h"
#include <algorithm>
#include <cassert>
void BinarySearchTree::Insert(int value)
{
    TreeNode *node = root;
    TreeNode *parent = NULL;
    while(node != NULL)
    {
        parent = node;
        if(node->value  ==  value)
            return ; // do not insert duplicate value
        else if(node->value < value)
            node = node->right;
        else
            node = node->left;
    }
    node = new TreeNode(value);
    if(!parent)
    {
        root = node;
    }
    else if(parent->value>value)
    {
        parent->left = node;
    }
    else
    {
        parent->right = node;
    }
    return;
}
TreeNode* BinarySearchTree::Delete(int value)
{
    TreeNode *node = root;
    TreeNode *parent = root;
    bool from_left = false;
    while(node != NULL)
    {
        if(node->value  ==  value)
            break;
        else if(node->value < value)
        {
            parent = node;
            node = node->right;
            from_left = false;
        }
        else
        {
            parent = node;
            node = node->left;
            from_left = true;
        }
    }
    if(!node)
    {
        return NULL;
    }
    TreeNode **parent_pointer = parent == node ? &root : (from_left ? &parent->left : &parent->right);
    assert(*parent_pointer == node);
    if(node->left == NULL)
    {
        *parent_pointer = node->right;
    }
    else if(node->right == NULL)
    {
        *parent_pointer = node->left;
    }
    else
    {
        TreeNode* node1 = node->left;
        parent = NULL;
        while(node1->right)
        {
            parent=node1;
            node1 = node1->right;
        }
        std::swap(node1->value, node->value);
        if(!parent)
        {
            node->left = node1->left;
        }
        else
        {
            parent->right = node1->left;
        }
        node1->left = NULL;
        return node1;
    }
    node->left = node->right = NULL;
    return node;
}
int BinarySearchTree::Find(int value)
{
    TreeNode *node = root;
    while(node != NULL)
    {
        if(node->value  ==  value)
            return 1;
        else if(node->value < value)
            node = node->right;
        else
            node = node->left;
    }
    return 0;
}
