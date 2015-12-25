#pragma once

struct TreeNode
{
    char* stroka;
    bool isOperation;
    TreeNode *left;
    TreeNode *right;
};

struct Tree
{
    TreeNode *root;
    int size;
};

void add(int currentIndex, Tree *currentTree, TreeNode *currentVertex, char dictionary[][100], int sizeOfDictionary);
TreeNode remove(Tree *currentTree, int value);
void printAscending(TreeNode *currentVertex);
void haveRecursion(Tree *currentTree, char dictionary[][100], int sizeOfDictionary);
/*void printDescending(TreeNode *currentVertex);
void debugOutput(TreeNode *currentVertex);
bool isExists(Tree *currentTree, int value);*/


