#include <stdio.h>
#include <stdlib.h>
typedef int Data;

struct Node {
    Data val;            // данные в узле
    struct Node * left;  // левый ребенок
    struct Node * right; // правый ребенок
};
//.......................................................
struct Node* tree_add(struct Node* tree, Data x);
void tree_print (struct Node * tree);
void tree_destroy (struct Node * tree);
//.......................................................
int main()
{
    struct Node * tree=NULL;
    int x = 0;
    while(1)
    {
        scanf("%d", &x);
        if (x == 0)
            break;
        tree = tree_add(tree, x);
    }

    tree_print(tree); // напечатает 1 2 3 4 5 6 7 8 9
    tree_destroy(tree);
    return;
}

struct Node* tree_add(struct Node* tree, Data x)
{
    if (!tree) // если дошли до нулевого указателя, можно добавлять элемент
    {
        struct Node* newNode = malloc(sizeof(struct Node));
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->val = x;
        return newNode;
    }

    if (x < tree->val) // даныне меньше, отправляем их налево
    {
        tree->left = tree_add(tree->left, x);
    }

    if (x > tree->val) // даныне больше, отправляем направо 
    {
        tree->right = tree_add(tree->right, x);
    }

    // есди данные равны

    return tree;
}   

void tree_print (struct Node * tree)
{
    if(!tree)
        return;
    tree_print(tree->left);
    printf("%d ", tree->val);
    tree_print(tree->right);
}


void tree_destroy (struct Node * tree)
{
    if (!tree) // если tree == NULL  то очищенно
        return;
    tree_destroy(tree->left);
    tree_destroy(tree->right);
    free(tree);
}