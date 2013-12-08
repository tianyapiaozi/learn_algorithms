#ifndef _BINARY_SEARCH_TREE_
#define _BINARY_SEARCH_TREE_
#include "binary_tree.h"
class BinarySearchTree : public BinaryTree
{
    public:
        virtual void Insert(int value);
        virtual TreeNode* Delete(int value);
        int Find(int value);
};
#endif
