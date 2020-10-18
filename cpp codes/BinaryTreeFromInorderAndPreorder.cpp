 #include<iostream>

using namespace std;
class node
{
	public:
	char data;
	node *left,*right;
};
node *newnode(int x)
{
	node *temp=new node;
	temp->data=x;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
void printinorder(node* temp) 
{ 
    if (!temp) 
        return; 
  
    printinorder(temp->left); 
    cout << temp->data << " "; 
    printinorder(temp->right); 
} 
int search(char *inorder,int start,int end,int target)
{
	for(int i=0;i<=end;++i)
	{
		if(inorder[i]==target)
		{
			return i;
		}
	}
	return -1;
}
node *buildtree(char *inorder,char *preorder,int start,int end)
{
	static int preindex=0;
	if(start>end)
	return NULL;
	
	int target=preorder[preindex];
	preindex++;
	int index=search(inorder,start,end,target);
	
	node *root=new node;
	
	root->left=buildtree(inorder,preorder,start,index-1);
	root->right=buildtree(inorder,preorder,index+1,end);
	
	root->data=target;
	
	return root;
}
int main()
{
	char inorder[]={'D','B','E','A','F','C'};
	char preorder[]={'A','B','D','E','C','F'};
	
	node *root=buildtree(inorder,preorder,0,5);
	printinorder(root);
}

