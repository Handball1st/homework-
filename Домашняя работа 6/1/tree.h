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

bool check(TreeNode *currentVertex, int value);
void add(Tree *currentTree, int value);
void printAscending(TreeNode *currentVertex);
//TreeNode remove(Tree *currentTree, int value);


