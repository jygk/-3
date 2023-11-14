#pragma once
struct Node {
	Node* parent;
	Node* lchild;
	Node* rchild;
	int key;
	Node(int value) : key(value), lchild(nullptr), rchild(nullptr), parent(nullptr) {}
};