#include <locale>
#include <iostream>
#include <iomanip>
#include "func.h"
#include "AVLNode.h"
#include <algorithm>
using namespace std;
class AVLTree {
private:
    Node* root;

    int height(Node* node) {
        return (node != nullptr) ? node->height : 0;
    }

    int balanceFactor(Node* node) {
        return (node != nullptr) ? height(node->lchild) - height(node->rchild) : 0;
    }

    Node* rightRotate(Node* y) {
        Node* x = y->lchild;
        Node* T2 = x->rchild;

        x->rchild= y;
        y->lchild= T2;

        y->height = std::max(height(y->lchild), height(y->rchild)) + 1;
        x->height = std::max(height(x->lchild), height(x->rchild)) + 1;

        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->rchild;
        Node* T2 = y->lchild;

        y->lchild= x;
        x->rchild= T2;

        x->height = std::max(height(x->lchild), height(x->rchild)) + 1;
        y->height = std::max(height(y->lchild), height(y->rchild)) + 1;

        return y;
    }

    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->key) {
            node->lchild= insert(node->lchild, value);
        }
        else if (value > node->key) {
            node->rchild= insert(node->rchild, value);
        }
        else {
            // Duplicate values are not allowed in AVL tree
            return node;
        }

        // Update height of current node
        node->height = 1 + std::max(height(node->lchild), height(node->rchild));

        // Get the balance factor
        int balance = balanceFactor(node);

        // Left Heavy
        if (balance > 1) {
            if (value < node->lchild->key) {
                // Left-Left Case
                return rightRotate(node);
            }
            else {
                // Left-Right Case
                node->lchild= leftRotate(node->lchild);
                return rightRotate(node);
            }
        }

        // Right Heavy
        if (balance < -1) {
            if (value > node->rchild->key) {
                // Right-Right Case
                return leftRotate(node);
            }
            else {
                // Right-Left Case
                node->rchild= rightRotate(node->rchild);
                return leftRotate(node);
            }
        }

        return node;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current->lchild != nullptr) {
            current = current->lchild;
        }
        return current;
    }

    Node* deleteNode(Node* root, int value) {
        if (root == nullptr) {
            return root;
        }

        if (value < root->key) {
            root->lchild= deleteNode(root->lchild, value);
        }
        else if (value > root->key) {
            root->rchild= deleteNode(root->rchild, value);
        }
        else {
            if (root->lchild == nullptr || root->rchild== nullptr) {
                Node* temp = root->lchild? root->lchild: root->rchild;

                if (temp == nullptr) {
                    temp = root;
                    root = nullptr;
                }
                else {
                    *root = *temp;
                }

                delete temp;
            }
            else {
                Node* temp = minValueNode(root->rchild);
                root->key = temp->key;
                root->rchild= deleteNode(root->rchild, temp->key);
            }
        }

        if (root == nullptr) {
            return root;
        }

        root->height = 1 + std::max(height(root->lchild), height(root->rchild));

        int balance = balanceFactor(root);

        if (balance > 1) {
            if (balanceFactor(root->lchild) >= 0) {
                return rightRotate(root);
            }
            else {
                root->lchild= leftRotate(root->lchild);
                return rightRotate(root);
            }
        }

        if (balance < -1) {
            if (balanceFactor(root->rchild) <= 0) {
                return leftRotate(root);
            }
            else {
                root->rchild= rightRotate(root->rchild);
                return leftRotate(root);
            }
        }

        return root;
    }

public:
    AVLTree() : root(nullptr) {}

    void insert(int value) {
        root = insert(root, value);
    }

    void remove(int value) {
        root = deleteNode(root, value);
    }
    int SchHight(Node* node)
    {
        if (node == NULL)
            return 0;
        return 1 + max(SchHight(node->lchild), SchHight(node->rchild));
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
};
int AVLree()
{
    int Vart;
    AVLTree avlTree;
    int i = 0;
    /* cout << "Введите значение корневого элемента\n";
     cin >> node->key;*/
    setlocale(LC_ALL, "Russian");
    cout << "\n";
    while (1)
    {
        cout << "1. Вставить элемент\n2. Удалить элемент\n3. Получить высоту дерева\n4.Выйти\n";
        cout << "Введите номер функции: \n";
        cin >> Vart;
        if (Vart == 0)
        {
            cout << "Завершение работы с деревом\n";
            break;
        }
        cout << "Введите число: \n";
        cin >> i;
        switch (Vart) {
        case 1: avlTree.insert(i);
            avlTree.TreePrint(root);
            break;
        case 2: avlTree.remove(i);
            avlTree.TreePrint(root);
            break;
        case 3: avlTree.SchHight(root);
            avlTree.TreePrint(root);
            break;
        default: cout << "Не существует соответствующей функции. \n";
            break;
        }
    }

    cout << "\n";

}