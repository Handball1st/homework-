#include <iostream>
#include "tree.h"

using namespace std;

bool check(TreeNode *currentVertex, int value)
{
    return ((currentVertex->value > value && currentVertex->left == nullptr) ||
            (currentVertex->value < value && currentVertex->right == nullptr));
}

void add(Tree *currentTree, int value)
{
    ++currentTree->size;
    TreeNode *leaf = new TreeNode{value, nullptr, nullptr};
    if (currentTree->size == 1)
    {
        currentTree->root = leaf;
        return;
    }
    TreeNode *currentVertex = currentTree->root;
    while (check(currentVertex, leaf->value))
    {
        (currentVertex->value > leaf->value) ? currentVertex = currentVertex->left : currentVertex = currentVertex->right;
    }
    (currentVertex->value > leaf->value) ? currentVertex->left = leaf : currentVertex->right = leaf;
}

void printAscending(TreeNode *currentVertex)
{
    /*if (currentVertex->left == nullptr && currentVertex->right == nullptr)
    {
        cout << currentVertex->value << " ";
        return;
    }*/
    if (currentVertex->left != nullptr)
    {
        printAscending(currentVertex->left);
    }
    cout << currentVertex->value << " ";
    if (currentVertex->right != nullptr)
    {
        printAscending(currentVertex->right);
    }
}
