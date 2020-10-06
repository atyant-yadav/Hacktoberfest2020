#include<iostream>
using namespace std;

class node
{
  public:
    int data;
    node*left;
    node* right;
    
    node(int d)
    {
      data = d;
      left = NULL;
      right= NULL;
    }
};

node* buildBST(node* root,int d)
{
	if(root==NULL)
	{
		node* newnode = new node(d);
		return newnode;
	}
	if(root->data>=d)
	{
		root->left = buildBST(root->left,d);
	}
	else
	{
		root->right = buildBST(root->right,d);
	}
	return root;
}


node* build(int arr[],int n)
{
	
	node* root= NULL;
	int i=0;

	while(i!=n)
	{
		root = buildBST(root,arr[i]);
		i++;
	}
	return root;

}

void preorder(node* root)
{
	if(root)
	{
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}
	return;
}

void inorderRange(node* root,int a,int b)
{
	if(root)
	{
		inorderRange(root->left,a,b);
		if(root->data>=a && root->data<=b)
		{
		cout<<root->data<<" ";
		}
		inorderRange(root->right,a,b);
		// if(root->data>b)
		// {
		// 	inorderRange(root->left,a,b);
		// }
		// if(root->data<a)
		// {
		// 	inorderRange(root->right,a,b);
		// }
		// else
		// {
		// 	inorderRange(root->left,a,b);
		// 	inorderRange(root->right,a,b);
		// }
	}
	return;

}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)
		cin>>arr[i];

		int a,b;
		cin>>a>>b;

		node *root = build(arr,n);
		cout<<"# "<<"Preorder"<<" : ";
		preorder(root);
		cout<<endl;
		cout<<"# "<<"Nodes within range are"<<" : ";
		inorderRange(root,a,b);
		cout<<endl;

	}
	return 0;
}