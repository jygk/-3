#include <locale>
#include <iostream>
#include <iomanip>
#include "func.h"
#include "Node.h"
using namespace std;

void preorderPrint(Node* root)
{
    if (root == NULL)  
    {
        return;
    }
    cout << root->key << " ";
    preorderPrint(root->lchild);  
    preorderPrint(root->rchild); 
}
void inorderPrint(Node* root)
{
    if (root == NULL)   
    {
        return;
    }
    preorderPrint(root->lchild);   
    cout << root->key << " ";
    preorderPrint(root->rchild);
}
void postorderPrint(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    preorderPrint(root->lchild);  
    preorderPrint(root->rchild);
    cout << root->key << " ";
}