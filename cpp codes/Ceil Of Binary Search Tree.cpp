
// CPP code to find floor of a key in BST 
#include <bits/stdc++.h> 
using namespace std; 

struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};

/* This function is used to insert 
new values in BST*/
Node* insert(Node* root, int key) 
{ 
	if (!root) 
		return new Node(key); 
	if (key < root->data) 
		root->left = insert(root->left, key); 
	else
		root->right = insert(root->right, key); 
	return root; 
} 

//User function Template for C++

/*
struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
*/
int helper(Node *root, int input, int &ans)
{
    //using the below first three if conditions to determine the value of ans at
    //every step of recursion call stack
    if (root == NULL) 
        return -1; 
    if(root->data==input)
        ans=input;
    if(root->data>input&&root->data<ans)
        ans=root->data;
    if(root->data<input)
        helper(root->right,input,ans);
    if (root->data>input)
        helper(root->left,input,ans);
    👀 👀//while backtracking from the leaf node, returning the ans value got at 
    //the end to the previous recursion call stacks    
    return ans;    
}
// Function to find ceil of a given input in BST. If input is more 
// than the max key in BST, return -1 
int findCeil(Node* root, int input) 
{ 
    int ans=INT_MAX;
    int result=helper(root,input,ans);
    ⭐️⭐️//for no value greater than the input value found
    if(result==INT_MAX)
        return -1;
    else
        return result;
    // Base case 
   
   
} 


int main() 
{ 
	
	int t;
	cin >> t;
	
	while(t--){
	    Node* root = NULL;
	    int n, x;
	    cin >> n;
	    int arr[n];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr[i];
	        if(root == NULL) root = insert(root, arr[i]);
	        else insert(root, arr[i]);
	    }
	    cin >> x;
	    cout << findCeil(root, x) << endl;
	}
	
	return 0; 
}  // } Driver Code Ends
