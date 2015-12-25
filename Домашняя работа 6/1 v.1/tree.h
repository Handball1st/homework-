#pragma once

struct TreeNode
{
    int value;
    TreeNode *left;
    TreeNode *right;
};

struct Tree
{
    TreeNode *root;
    int size;
};

void add(Tree *currentTree, int value);
void printAscending(TreeNode *currentVertex);
void printDescending(TreeNode *currentVertex);
void debugOutput(TreeNode *currentVertex);
TreeNode remove(Tree *currentTree, int value);
bool isExists(Tree *currentTree, int value);


