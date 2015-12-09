#include "ast.h"
#include <string>
#include <iostream>
using namespace std;

struct node{
	string *value;
	struct node *left;
	struct node *right;
};

ast::ast() {root = 0;}
ast::ast(node *root){this->root = root;}
ast::~ast() {}

void ast::destroy_tree(node *leaf){
	if(leaf != 0){
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		if (leaf->value != 0){
			delete leaf->value;
			//cout << "Deleted leaf value!" << endl;
		}
		delete leaf;
		//cout << "Deleted whole leaf!" << endl;	
	}
	root = 0;
}

void ast::destroy_tree(){
	destroy_tree(root);
}

void ast::addright(node *head, node *leaf){
	if(leaf != 0 && head != 0){
		if(root == leaf){
			//If adding root node as left, make new root the head
			root = head;
		}	
		head->right = leaf;
	}
}

void ast::inorder(node *head){
	if(head != 0){
		inorder(head->left);
		cout << *(head->value) << endl;
		inorder(head->right);
	}
}

void ast::preorder(node *head){
	if(head != 0){
		cout << *(head->value) << endl;
		preorder(head->left);
		preorder(head->right);
	}
}

void ast::postorder(node *head){
	if(head != 0){
		postorder(head->left);
		postorder(head->right);
		cout << *(head->value) << endl;
	}
}

//node *ast::new(node *value, string operation)
node *ast::newval(string key){
	node *head = new node();
	if (root == 0){root = head;}
	head->value = new string(key);
	head->left = 0;
	head->right = 0;
	return head;
}

node *ast::newop(node *value, string operation){
	node *head = new node();
	if (root == value){root = head;}
	head->value = new string(operation);
	head->left = 0;
	head->right = value;
	return head;	
}

node *ast::newmath(node *value, string operation){
	node *head = new node();
	if (root == value){root = head;}
	head->value = new string(operation);
	head->left = value;
	//cout << "HEAD: " << *(head->value) << "Left " << *(head->left->value) << endl;
	head->right = 0;
	return head;
}
