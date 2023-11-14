#pragma once
enum Color{RED, BLACK};
struct Node {
	Node* parent;
	Color color;
	Node* lchild;
	Node* rchild;
	int key;
	Node(int value) : key(value), color(RED), lchild(nullptr), rchild(nullptr), parent(nullptr) {}
}; 