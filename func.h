#pragma once
const int N = 10;

int BinarySearchTree();
//void RedBlackTree();
//void AVLTree();
void TreePrint(Node* root, int space, int count);
Node* BinarySearchInsert(Node* root, int value);
Node* BinarySearchDelete(Node* root, int value);
int BinarySearchHight(Node* node);
Node* TreeMinimum(Node* node);
int RedBlackTree();
class RedBlackTree;
