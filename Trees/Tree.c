#include "Tree.h"
//...............................................................................
//получение глубины дерева относительно узла
int GetLevelNode(TreeNode* root)
{
    unsigned left = (root->left) ? root->left->level + 1 : 0; 
    unsigned right = (root->right) ? root->right->level + 1 : 0;

    return (left > right) ? left : right;

}
//...............................................................................
// вставка данных в дерево
TreeNode* SimpleInsertNode(TreeNode* root, Data data)
{
    if(!root) // если дошли до нулевого указателя, можно вставлять 
    {
        TreeNode* newNode = malloc(sizeof(TreeNode));

        assert(newNode);

        newNode->data = data;
        newNode->right = NULL;
        newNode->left = NULL;
        newNode->level = 0;

        return newNode;
    }

    if(data < root->data) // если данные меньше чем в root, отправляем влево
    {
        root->left = SimpleInsertNode(root->left, data);
    }

    if(data > root->data) // если данные больше чем в root, отправляем вправо
    {
        root->right = SimpleInsertNode(root->right, data);
    }

    // если данные равны, ничего не вставляем;
    root->level = GetLevelNode(root);
    return root;
}
//...............................................................................
// печать элементов дерева в отсортированном виде
void PrintTree(TreeNode* root)
{
    if(!root)
        return;
    
    PrintTree(root->left);
    printf("%d ", root->data);
    PrintTree(root->right);
}
//...............................................................................
// печать элементов дерева в отсортированном виде с глубиной
void PrintTreeLevel(TreeNode* root)
{
    if(!root)
        return;
    
    PrintTreeLevel(root->left);
    printf("%d->(%d) ", root->data, root->level);
    PrintTreeLevel(root->right);
}
//...............................................................................
//Удаление дерева
TreeNode*  Destroy(TreeNode * root)
{
    if(!root)
        return NULL;
    
    TreeNode* r = NULL;
    TreeNode* l = NULL;

    r = Destroy(root->right);
    l = Destroy(root->left);

    if(!l && !r)
        free(root);

    return NULL;
}

