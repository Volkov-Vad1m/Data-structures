#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
//...............................................................................
//...............................................................................
#define Data int

// Узел бинарного дерева
typedef struct TN{
    
    Data data;     
    struct TN * left; // левый узел, для данных меньше текущего узла
    struct TN * right;// левый узел, для данных меньше текущего узла
    int level;       // Высота дерева (от самого удаленного листа)
}TreeNode;
//...............................................................................
//...............................................................................
int GetLevelNode(TreeNode* root);
TreeNode* SimpleInsertNode(TreeNode* root, Data data);
void PrintTree(TreeNode* root);
void PrintTreeLevel(TreeNode* root);
TreeNode*  Destroy(TreeNode * root);



