
#include<bits/stdc++.h> 
using namespace std; 

struct Node 
{ 
	int key; 
	struct Node *left, *right; 
}; 

Node *newNode(int key) 
{ 
	Node *temp = new Node; 
	temp->key = key; 
	temp->left = temp->right = NULL; 
	return (temp); 
} 

void createNode(int parent[], int i, Node *created[], Node **root) 
{ 
	if (created[i] != NULL) 
		return; 

	created[i] = newNode(i); 

	if (parent[i] == -1) 
	{ 
		*root = created[i]; 
		return; 
	} 

	if (created[parent[i]] == NULL) 
		createNode(parent, parent[i], created, root); 

	Node *p = created[parent[i]]; 
	if (p->left == NULL) 
		p->left = created[i]; 
	else 
		p->right = created[i]; 
} 

Node *createTree(int parent[], int n) 
{ 
	Node *created[n]; 
	for (int i=0; i<n; i++) 
		created[i] = NULL; 

	Node *root = NULL; 
	for (int i=0; i<n; i++) 
		createNode(parent, i, created, &root); 

	return root; 
} 

inline void newLine(){ 
	cout << "\n"; 
} 

void inorder(Node *root) 
{ 
	if (root != NULL) 
	{ 
		inorder(root->left); 
		cout << root->key << " "; 
		inorder(root->right); 
	} 
} 

int main() 
{ 
	int parent[] = {-1, 0, 0, 1, 1, 3, 5}; 
	int n = sizeof parent / sizeof parent[0]; 
	Node *root = createTree(parent, n); 
	cout << "Inorder Traversal of constructed tree\n"; 
	inorder(root); 
	newLine(); 
} 
