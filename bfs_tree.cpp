#include<iostream>
using namespace std;

class node
{
 public:
     int data;

     node*left = NULL;
     node* right  = NULL;

};

node* build_tree()
{
    node * root= new node;
    int d;
    cout<<"enter data ";
    cin>>d;
    if(d==-1)
    {
        return NULL;
    }
    else{
        root->data=d;

        root->left = build_tree();
        root->right= build_tree();
        return root;}

}

    void print_tree(node*root)
    {

        if(root!=NULL)
        {
            cout<<root->data<< " -- " ;
            print_tree(root->left);
            print_tree(root->right);
        }

    }

int height_tree(node * root)
{
    if(root==NULL)
    {
        return 0;
    }

    int maxi;
    int l = height_tree(root->left);
    int r = height_tree(root->right);
    if(l>=r)
    {
        maxi = l;
    }
    else{maxi = r;}

    return maxi+1;


}

void print_nthlevel(node*root,int l)
{if(root==NULL)
{
    return;
}
    if(l==0)
    {
        cout<<root->data<<" -- ";
        return;
    }
    else{

        print_nthlevel(root->left,l-1);
        print_nthlevel(root->right,l-1);

    }

}
void bfs_traversal(node * root)
{
    int height=height_tree(root);
    cout<<" height of tree is "<<height<<endl;
    int i=0;
    while(i<=height)
    {
        print_nthlevel(root,i);
        cout<<endl;
        i++;
    }



}



int main()
{

    cout<<"lets make a tree" ;
    node* root= build_tree();
    cout<<endl;
   /*cout<<"now lets print a tree ";
     inorder(root);
     cout<<"height of tree is ";
     cout<<" height == "<<height_tree(root);
     */
    cout<<" normal tree ";
    print_tree(root);
     cout<<endl<<"doing breadth first traversal ";
     bfs_traversal(root);

}

