#include <locale>
#include <iostream>
#include <iomanip>
#include "func.h"
#include "Node.h"

using namespace std;
int BinarySearchTree()
{
    int Vart;
    Node* root = nullptr;
    int i = 0;
   /* cout << "������� �������� ��������� ��������\n";
    cin >> node->key;*/
    setlocale(LC_ALL, "Russian");
    cout << "\n";
    while (1)
    {
        cout << "1. �������� �������\n2. ������� �������\n3. �������� ������ ������\n4.�����\n";
        cout << "������� ����� �������: \n";
        cin >> Vart;
        if (Vart == 0)
        {
            cout << "���������� ������ � �������\n";
            break;
        }
        cout << "������� �����: \n";
        cin >> i;
        switch (Vart) {
        case 1: BinarySearchInsert(root, i); 
            TreePrint(root); 
            break;
        case 2: BinarySearchDelete(root, i); 
            TreePrint(root); 
            break;
        case 3: BinarySearchHight(root); 
            TreePrint(root); 
            break;
        default: cout << "�� ���������� ��������������� �������. \n";
            break;
        }
    }
   
     cout << "\n";
     
}
void TreePrint(Node* root, int space = 0, int count = 5) {
    if (root == nullptr) {
        return;
    }
    space += count;

    TreePrint(root->rchild, space);

    std::cout << std::endl;
    for (int i = count; i < space; i++) {
        std::cout << " ";
    }
    std::cout << root->key << "\n";

    TreePrint(root->lchild, space);
}
int BinarySearchHight(Node* node)
{
    if (node == NULL)
        return 0;
    return 1 + max(BinarySearchHight(node->lchild), BinarySearchHight(node->rchild));
}

// ������� �������� � �������� ������ ������
Node* BinarySearchInsert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->key) {
        root->lchild = BinarySearchInsert(root->lchild, value);
    }
    else if (value > root->key) {
        root->rchild = BinarySearchInsert(root->rchild, value);
    }

    return root;
}

// ����� ������������ �������� � �������� ������
Node* TreeMinimum(Node* node) {
    while (node->lchild != nullptr) {
        node = node->lchild;
    }
    return node;
}
// �������� �������� �� ��������� ������ ������
Node* BinarySearchDelete(Node* root, int value) {
    if (root == nullptr) {
        return root;
    }

    if (value < root->key) {
        root->lchild = BinarySearchDelete(root->lchild, value);
    }
    else if (value > root->key) {
        root->rchild = BinarySearchDelete(root->rchild, value);
    }
    else {
        if (root->lchild == nullptr) {
            Node* temp = root->rchild;
            delete root;
            return temp;
        }
        else if (root->rchild== nullptr) {
            Node* temp = root->lchild;
            delete root;
            return temp;
        }
        Node* temp = TreeMinimum(root->rchild);
        root->key= temp->key;
        root->rchild= BinarySearchDelete(root->rchild, temp->key);
    }

    return root;
}
