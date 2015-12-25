#include <iostream>
#include <cstring>
#include "tree.h"

using namespace std;

bool compare(char firstString[], char secondString[])  // true a <= b
{
    int sizeOfString = (strlen(firstString) < strlen(secondString)) ? strlen(firstString) : strlen(secondString);
    for (int i = 0; i < sizeOfString; ++i)
    {
        if (firstString[i] != secondString[i])
        {
            return (firstString[i] < secondString[i]);
        }
    }
    return (sizeOfString == strlen(firstString));
}

bool check(TreeNode *currentVertex)
{
    return (currentVertex->left != nullptr && currentVertex->right != nullptr);
}

void add(Tree *currentTree, char currentString[])
{
    ++currentTree->size;
    TreeNode *leaf = new TreeNode{currentString, nullptr, nullptr};
    if (currentTree->size == 1)
    {
        currentTree->root = leaf;
        return;
    }
    TreeNode *currentVertex = currentTree->root;
    while (check(currentVertex))
    {
        //if (curr)
    }

    (currentVertex->string > leaf->string) ? currentVertex->left = leaf : currentVertex->right = leaf;
    printAscending(currentTree->root);
    cout << endl;
}

void output(char currentString[])
{
    for (int i = 0; i < strlen(currentString); ++i)
    {
        cout << currentString[i];
    }
    cout << " ";
}

void printAscending(TreeNode *currentVertex)
{
    if (currentVertex->left != nullptr)
    {
        printAscending(currentVertex->left);
    }
    output(currentVertex->string);
    if (currentVertex->right != nullptr)
    {
        printAscending(currentVertex->right);
    }
}

/*bool removeFromRoot(TreeNode *currentVertex, Tree *currentTree)
{
    if (currentVertex->left == nullptr && currentVertex->right == nullptr)
    {
        currentVertex = new TreeNode{0, nullptr, nullptr};
        return 1;
    }
    if (currentVertex->left == nullptr && currentVertex->right != nullptr)
    {
        currentTree->root = currentVertex->right;
        return 1;
    }
    if (currentVertex->left != nullptr && currentVertex->right == nullptr)
    {
        currentVertex = currentVertex->left;
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
        if (!removeFromRoot(currentVertex, currentTree))
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
}*/
