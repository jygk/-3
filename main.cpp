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
    cout << "1. �������� ������ ������\n2. ������-������ ������\n3. ���-������\n\n";
    cout << "������� ����� �������: \n";
    cin >> Vart;
    switch (Vart) {
    case 1: BinarySearchTree(); break;
    case 2: RedBlackTree(); break;
    case 3: AVLTree(); break;
    default: cout << "�� ���������� ��������������� �������. \n";
        break;
    }
}
