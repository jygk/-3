#pragma once
struct Node {
	Node* parent;
	Node* lchild;
	Node* rchild;
	int height;
	int key;
	Node(int value) : key(value), height(1), lchild(nullptr), rchild(nullptr), parent(nullptr) {}
};