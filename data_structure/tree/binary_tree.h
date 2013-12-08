#ifndef _BINARY_TREE_
#define _BINARY_TREE_
#include <cstdio>
struct TreeNode
{
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int value)
    {
        this->value = value;
        left = NULL;
        right = NULL;
    }
};
class BinaryTree
{
    public:
        BinaryTree() : root(NULL) { }
        ~BinaryTree()
        {
            DeallocateTree(root);
        }
        static void InOrderHelper(TreeNode *root);
        static void PostOrderHelper(TreeNode *root);
        static void PreOrderHelper(TreeNode *root);
        void InOrder()
        {
            InOrderHelper(root);
            printf("\n");
        }
        void PostOrder()
        {
            PostOrderHelper(root);
            printf("\n");
        }
        void PreOrder()
        {
            PreOrderHelper(root);
            printf("\n");
        }
        void GenerateGraphvizFile(const char *filename);
    protected:
        TreeNode *root;
    private:
        void operator=(const BinaryTree&);
        BinaryTree(const BinaryTree &);
        void DeallocateTree(TreeNode *root);

};
#endif
