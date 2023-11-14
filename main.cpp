#include <locale>
#include <iostream>
#include <iomanip>
#include "func.h"
#include "Node.h"

using namespace std;
int main()
{
    int Vart;
    setlocale(LC_ALL, "Russian");
    cout << "\n";
    cout << "1. Двоичное дерево поиска\n2. Красно-чёрное дерево\n3. АВЛ-дерево\n\n";
    cout << "Введите номер функции: \n";
    cin >> Vart;
    switch (Vart) {
    case 1: BinarySearchTree(); break;
    case 2: RedBlackTree(); break;
    case 3: AVLTree(); break;
    default: cout << "Не существует соответствующей функции. \n";
        break;
    }
}
