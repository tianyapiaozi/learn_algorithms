#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include "binary_search_tree.h"
using namespace std;
int main(int argc, char const* argv[])
{
    BinarySearchTree tree;
    for(int i = 0; i < 10; i++)
        tree.Insert(i);
    tree.PreOrder();
    tree.GenerateGraphvizFile("unbalanced.dot");
    cout  << tree.Find(5)  << endl;
    TreeNode *node = tree.Delete(5);
    tree.PreOrder();
    cout  << tree.Find(5)  << endl;
    cout  << node->value  << endl;
    delete node;

    BinarySearchTree tree2;
    srand(time(NULL));
    const int times = 20;
    int numbers[times];
    char insert_name[32];
    for(int i = 0; i < times; i++)
    {
        numbers[i] = rand()%10000;
        tree2.Insert(numbers[i]);
        tree2.PreOrder();
        snprintf(insert_name, sizeof(insert_name), "insert_%d.dot", i);
        tree2.GenerateGraphvizFile(insert_name);
    }
    cout  << "Deleting...\n"  << endl;
    char del_name[32];
    for(int i = 0; i < times; i++)
    {
        TreeNode* node = tree2.Delete(numbers[i]);
        if(node != NULL)
        {
            assert(node->value == numbers[i]);
            delete node;
        }
        snprintf(del_name, sizeof(del_name), "del_%d.dot", i);
        tree2.GenerateGraphvizFile(del_name);
        tree2.PreOrder();
    }
    tree2.PreOrder();
    return 0;
}
