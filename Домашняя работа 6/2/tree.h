#pragma once

struct TreeNode
{
    char* string;
    bool isOperation;
    TreeNode *left;
    TreeNode *right;
};

struct Tree
{
    TreeNode *root;
    int size;
};

void add(Tree *currentTree, char currentString[]);
TreeNode remove(Tree *currentTree, int value);
void printAscending(TreeNode *currentVertex);
/*void printDescending(TreeNode *currentVertex);
void debugOutput(TreeNode *currentVertex);
bool isExists(Tree *currentTree, int value);*/


