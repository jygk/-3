#include <locale>
#include <iostream>
#include <iomanip>
#include "func.h"
#include "RBNode.h"
using namespace std;

class RedBlackTree {
private:
    Node* root;

    void leftRotate(Node* x) {
        Node* y = x->rchild;
        x->rchild = y->lchild;

        if (y->lchild != nullptr) {
            y->lchild->parent = x;
        }

        y->parent = x->parent;

        if (x->parent == nullptr) {
            root = y;
        }
        else if (x == x->parent->lchild) {
            x->parent->lchild= y;
        }
        else {
            x->parent->rchild= y;
        }

        y->lchild = x;
        x->parent = y;
    }

    void rightRotate(Node* y) {
        Node* x = y->lchild;
        y->lchild= x->rchild;

        if (x->rchild != nullptr) {
            x->rchild->parent = y;
        }

        x->parent = y->parent;

        if (y->parent == nullptr) {
            root = x;
        }
        else if (y == y->parent->lchild) {
            y->parent->lchild= x;
        }
        else {
            y->parent->rchild= x;
        }

        x->rchild= y;
        y->parent = x;
    }

    void fixInsert(Node* z) {
        while (z->parent != nullptr && z->parent->color == RED) {
            if (z->parent == z->parent->parent->lchild) {
                Node* y = z->parent->parent->rchild;
                if (y != nullptr && y->color == RED) {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                }
                else {
                    if (z == z->parent->rchild) {
                        z = z->parent;
                        leftRotate(z);
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    rightRotate(z->parent->parent);
                }
            }
            else {
                Node* y = z->parent->parent->lchild;
                if (y != nullptr && y->color == RED) {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                }
                else {
                    if (z == z->parent->lchild) {
                        z = z->parent;
                        rightRotate(z);
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    leftRotate(z->parent->parent);
                }
            }
        }
        root->color = BLACK;
    }
    Node* findNode(int value, Node* current) const {
        if (current == nullptr || current->key == value) {
            return current;
        }

        if (value < current->key) {
            return findNode(value, current->lchild);
        }

        return findNode(value, current->rchild);
    }

public:
    RedBlackTree() : root(nullptr) {}

    void insert(int value) {
        Node* z = new Node(value);
        Node* y = nullptr;
        Node* x = root;

        while (x != nullptr) {
            y = x;
            if (z->key < x->key) {
                x = x->lchild;
            }
            else {
                x = x->rchild;
            }
        }

        z->parent = y;
        if (y == nullptr) {
            root = z;
        }
        else if (z->key < y->key) {
            y->lchild= z;
        }
        else {
            y->rchild= z;
        }

        fixInsert(z);
    }
    int SearchHight(Node* node)
    {
        if (node == NULL)
            return 0;
        return 1 + max(SearchHight(node->lchild), SearchHight(node->rchild));
    }

    // Добавьте метод для удаления узла

    // Добавьте метод для вывода дерева в порядке обхода (например, inorder)
    int RBTree()
    {
        int Vart;
        RedBlackTree tree;
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
            case 1: tree.insert(i);
                tree.TreePrint(root);
                break;
            case 2: tree.findNode(i, root);
                tree.TreePrint(root);
                break;
            case 3: tree.SearchHight(root);
                tree.TreePrint(root);
                break;
            default: cout << "Не существует соответствующей функции. \n";
                break;
            }
        }

        cout << "\n";
        return 0;

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

}