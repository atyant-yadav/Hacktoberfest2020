#include<iostream>
using namespace std;
struct node {
int data;
struct node *left;
struct node *right;
};
struct node *tree=NULL;
struct node *insert_tree(struct node *);
struct node *preoder(struct node *);
struct node *inoder(struct node *);
struct node *postoder(struct node *);
struct node *delete1(struct node *,int);
struct node *delete_nochild(struct node *,struct node *);
struct node * delete_onechild(struct node *,struct node *);
struct node *delete_twochild(struct node *);
int total_node(struct node *);
 int totalexternal_node(struct node *);
 int totalinternal_node(struct node *);
  int height(struct node * );
 int main()
 {
     tree= insert_tree(tree);
     preoder(tree);
     cout<<"\n";
     inoder(tree);
     cout<<"\n";
     postoder(tree);
     cout<<"element you  want to delete";
     int x; cin>>x;

     tree =delete1(tree,x);
     inoder(tree);
      x=total_node(tree);
     cout<<"\ntotal node "<<x<<"\n";
     x=totalexternal_node(tree);
       cout<<"total external node "<<x<<"\n";
       x=totalinternal_node(tree);
          cout<<"total internal node = "<<x<<"\n";
          x=height(tree);
          cout<<"height= "<<x<<" \n";

 }
 struct node *insert_tree( struct node *tree){
 struct node *ptr=tree,*newnode,*parptr=tree;
 int x;cin>>x;
 while(x!=-1){
    newnode=(struct node *)malloc(sizeof(struct node ));
    newnode->data=x;
    newnode->left=NULL;
    newnode->right=NULL;
    if(tree==NULL){
        tree=newnode;
        tree->left=NULL;
        tree->right=NULL;
    }
    else
      {
         ptr=tree;
     while(ptr!=NULL)
       {parptr=ptr;
       if(x<ptr->data)
       {ptr=ptr->left;
       }
   else
        ptr=ptr->right;
 }
 if(x<parptr->data)
    parptr->left=newnode ;
 if(x>parptr->data)
    parptr->right=newnode;}
      cin>>x;
    }
    return tree;
};
struct node *preoder(struct node *tree)
{ struct node *ptr=tree;

if(ptr!=NULL)
 {cout<<ptr->data;
 preoder(ptr->left);
 preoder(ptr->right);}
};
struct node *inoder(struct node *tree){
struct node *ptr=tree;
if(ptr!=NULL){
    inoder(ptr->left);
    cout<<ptr->data;
    inoder(ptr->right);
}};
struct node *postoder(struct node *tree){
struct node *ptr=tree;
if(ptr!=NULL){
    postoder(ptr->right);
    postoder(ptr->left);
    cout<<ptr->data;
}
};
struct node * delete_nochild(struct node *ptr,struct node *parptr){

    if(ptr==parptr->left)
      {

       parptr->left=NULL;}
   else
   {
    parptr->right=NULL;
   }
free(ptr);

};
struct node *delete_onechild(struct node *ptr,struct node *parptr){
 if(ptr->left!=NULL&&ptr->right==NULL){cout<<" left"<<" ";
     if(parptr->left==ptr){

        parptr->left=ptr->left;
        }
        else {

            parptr->right=ptr->left;
        }
        ptr->left=NULL;
        free  (ptr);
}
else if(ptr->right!=NULL&&ptr->left==NULL)
{  if(parptr->left==ptr){
        parptr->left=ptr->right;
        }
        else {
            parptr->right=ptr->right;
        }cout<<"right"<<" " ;
        ptr->right=NULL;
        free(ptr);
    }

};
struct node * delete_twochild(struct node * ptr){cout<<"2 ";

    struct node *count=ptr;struct node *parptr=ptr;

ptr=ptr->right;
cout<<ptr->data<<" ";
while(ptr->left!=NULL){
parptr=ptr;
    ptr=ptr->left;
}


count->data=ptr->data;
cout<<parptr->data<<" ";
if(ptr->left==NULL&&ptr->right==NULL)
{cout<<"0"<<" ";

      delete_nochild(ptr,parptr);}
else{
       cout<< "1";

     delete_onechild(ptr,parptr);

}

};
struct node *delete1( struct node *parent, int ele){
struct node *ptr,*parptr=parent;
 ptr=parent;


    while(ptr!=NULL&&ptr->data!=ele)
       {parptr=ptr;
       if(ele<ptr->data)
       {ptr=ptr->left;
       }
   else
        ptr=ptr->right;
       }

if(ptr->left==NULL&&ptr->right==NULL)
{cout<<"0"<<" ";
      delete_nochild(ptr,parptr);

}
else if(ptr->left!=NULL&&ptr->right!=NULL){
    delete_twochild(ptr);
}

else{   cout<<" 1  "<<" ";
        delete_onechild(ptr,parptr);

}
    return tree;
};
int total_node(struct node *tree){
 if(tree==NULL){
    return 0;
 }
 else
    return (total_node(tree->left)+total_node(tree->right)+1);
 }
 int totalexternal_node(struct node *tree){
    if(tree==NULL) return 0;
    else if(tree->left==NULL&&tree->right==NULL)return 1;
    else
        return (totalexternal_node(tree->left)+totalexternal_node(tree->right));
    }
int totalinternal_node(struct node *tree){
 if(tree==NULL||(tree->left==NULL&&tree->right==NULL))
    return 0;
  else
    return (totalinternal_node(tree->left)+totalinternal_node(tree->right)+1);
 }
 int height(struct node * tree){ int lh=0,rh=0;

  if( tree!=NULL)
{ lh=height(tree->left);
rh=height(tree->right);
if( rh>lh)return rh+1;
else
    return lh+1;
    }
  }


