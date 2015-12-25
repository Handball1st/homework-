#include <iostream>
#include "tree.h"

using namespace std;

bool check(TreeNode *currentVertex, int value)
{
    return ((currentVertex->value > value && currentVertex->left != nullptr) ||
            (currentVertex->value < value && currentVertex->right != nullptr));
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

void printDescending(TreeNode *currentVertex)
{
    if (currentVertex->right != nullptr)
    {
        printDescending(currentVertex->right);
    }
    cout << currentVertex->value << " ";
    if (currentVertex->left != nullptr)
    {
        printDescending(currentVertex->left);
    }
}

void debugOutput(TreeNode *currentVertex)
{
    cout << "(" << currentVertex->value << " ";
    if (currentVertex->left != nullptr)
    {
        debugOutput(currentVertex->left);
    }
    else
    {
        cout << "null ";
    }
    if (currentVertex->right != nullptr)
    {
        debugOutput(currentVertex->right);
    }
    else
    {
        cout << "null ";
    }
    cout << ")";
}

bool removeFromRoot(TreeNode *&currentVertex)
{
    if (currentVertex->left == nullptr && currentVertex->right == nullptr)
    {
        cout << "nobody exists" << endl;
        currentVertex = new TreeNode{0, nullptr, nullptr};
        return 1;
    }
    if (currentVertex->left == nullptr && currentVertex->right != nullptr)
    {
        cout << "left not exists and right exists" << endl;
        cout << currentVertex->value << endl;
        currentVertex = currentVertex->right;
        cout << currentVertex->value << endl;
        return 1;
    }
    if (currentVertex->left != nullptr && currentVertex->right == nullptr)
    {
        cout << "left exists and right not exists" << endl;
        cout << currentVertex->value << endl;
        currentVertex = currentVertex->left;
        cout << currentVertex->value << endl;
        return 1;
    }
    return 0;
}

bool haveNotSons(TreeNode *currentVertex, TreeNode *preCurrentVertex, int value)
{
    if (currentVertex->left == nullptr && currentVertex->right == nullptr)
    {
        if (preCurrentVertex->left != nullptr)
        {
            if (preCurrentVertex->left->value == value) preCurrentVertex->left = nullptr;
        }
        if (preCurrentVertex->right != nullptr)
        {
            if (preCurrentVertex->right->value == value) preCurrentVertex->right = nullptr;
        }
        delete currentVertex;
        return 1;
    }
    return 0;
}

bool haveOnlyLeftSon(TreeNode *currentVertex, TreeNode *preCurrentVertex, int value)
{
    if (currentVertex->left != nullptr && currentVertex->right == nullptr)
    {
        (preCurrentVertex->left->value == value) ? preCurrentVertex->left = currentVertex->left
                                                 : preCurrentVertex->right = currentVertex->left;
        return 1;
    }
    return 0;
}

bool haveOnlyRightSon(TreeNode *currentVertex, TreeNode *preCurrentVertex, int value)
{
    if (currentVertex->left == nullptr && currentVertex->right != nullptr)
    {
        (preCurrentVertex->left->value == value) ? preCurrentVertex->left = currentVertex->right
                                                 : preCurrentVertex->right = currentVertex->right;
        return 1;
    }
    return 0;
}

bool haveLeftAndRightSons(TreeNode *currentVertex, TreeNode *preCurrentVertex, int value)
{
    TreeNode *newVertex = currentVertex->right;
    TreeNode *preNewVertex = currentVertex;
    while (newVertex->left != nullptr)
    {
        preNewVertex = newVertex;
        newVertex = newVertex->left;
    }
    currentVertex->value = newVertex->value;
    (preNewVertex->right->value == newVertex->value) ? preNewVertex->right = nullptr : preNewVertex->left = nullptr;
    delete newVertex;
    return 1;
}

TreeNode remove(Tree *currentTree, int value)
{
    --currentTree->size;
    TreeNode *currentVertex = currentTree->root;
    TreeNode *preCurrentVertex = new TreeNode{-1, nullptr, nullptr};
    if (currentVertex->value == value)
    {
        TreeNode *result = currentVertex;
        //cout << currentVertex->value << endl;
        if (removeFromRoot(currentVertex))
        {
            cout << currentVertex->value << endl;
        }
        if (!removeFromRoot(currentVertex))
        {
            haveLeftAndRightSons(currentVertex, preCurrentVertex, value);
        }
        return *result;
    }
    while (check(currentVertex, value))
    {
        if (currentVertex->value == value)
        {
            break;
        }
        preCurrentVertex = currentVertex;
        (currentVertex->value > value) ? currentVertex = currentVertex->left : currentVertex = currentVertex->right;
    }
    TreeNode result = *currentVertex;
    bool wasRemoved = haveNotSons(currentVertex, preCurrentVertex, value);
    if (!wasRemoved)
    {
        wasRemoved = haveOnlyLeftSon(currentVertex, preCurrentVertex, value);
    }
    if (!wasRemoved)
    {
        wasRemoved = haveOnlyRightSon(currentVertex, preCurrentVertex, value);
    }
    if (!wasRemoved)
    {
        wasRemoved = haveLeftAndRightSons(currentVertex, preCurrentVertex, value);
    }
    return result;
}

bool isExists(Tree *currentTree, int value)
{
    TreeNode *currentVertex = currentTree->root;
    while (check(currentVertex, value))
    {
        if (value == currentVertex->value)
        {
            return 1;
        }
        (currentVertex->value > value) ? currentVertex = currentVertex->left : currentVertex = currentVertex->right;
    }
    if (value == currentVertex->value)
    {
        return 1;
    }
    return 0;
}
/*
100
1 10
1 15
1 5
1 8
1 3
2 5
2 8
*/
