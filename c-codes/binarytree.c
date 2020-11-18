include <stdio.h>
#include <stdlib.h> 
#include <math.h>
#define SIZE 20

struct node                    
{
 int data;
 struct node *lchild;  
 struct node *rchild;
};

struct node *start=NULL;
struct node  *nod, *temp;
struct node *build_node[SIZE]; 
int no_nodes;

void create();
void inordertrav(struct node *n);
void preordertrav(struct node *n);
void postordertrav(struct node *n); 
void display(); 

int main()             
{
 int opt;
 
  do
 {
  printf("\n     1.Create Binary tree\n");
  printf("\n     2.Inorder traversal of the Binary tree\n");
  printf("\n     3.Postorder traversal of the Binary tree\n");
  printf("\n     3.Preorder traversal of the Binary tree\n");  
  printf("\n     5.Display Binary tree\n");
  printf("\n     6.Quit\n");
  
  printf("\nEnter option:   ");
  scanf("%d",&opt);

  switch(opt)
  {
   case 1:
          
          create();
          break;

   case 2:
          inordertrav(start); 
          break; 
          
   case 3:
          postordertrav(start); 
          break;
   case 4:
          preordertrav(start);
          break;
   case 5:
          display();
          break;

   case 6:
          exit(1);
  }
 } while(1);
 
}

void create()                                      
{
  int i, item[SIZE]; 
  int lchld, rchld;
  
                                          
  printf(" Enter the number of nodes in the binary tree inclusive of the null child nodes\n");
  printf(" (input the highest numbered node)!\n");
  printf("-----------------------------------------------------\n");
  scanf("%d", &no_nodes);
  
  printf("\nEnter the elements in a left to right fashion \n");
  printf("in the order of their levels in the binary tree! \n");
  printf("\nEnter the number 0 to indicate a null child\n");
  printf("------------------------------------------------------\n"); 
  
 for (i=1; i<=no_nodes; i++)
 {scanf("%d", &item[i]);                           
  if (item[i] !=0)
     {  nod=(struct node *)calloc(1,sizeof(struct node));
        nod->data = item[i];              
        build_node[i] = nod;
        
      }
   
  else build_node[i]= 0;        
 } 

 for (i=1; i<=no_nodes; i++)     
 {   
     temp = build_node[i];      
     if (temp !=0) 
     {
                lchld = 2*i;
                rchld = 2*i+1;
                if (lchld <= no_nodes)
                          temp->lchild = build_node[lchld];   
                else      temp->lchild = 0;
   
                if (rchld <= no_nodes) 
                          temp->rchild = build_node[rchld];    
                else      temp->rchild = 0; 
      }
 }  
   
start = build_node[1];    /* start points to the root node of the binary tree*/
  
} 
   

/*performs inordertransversal using recursion */
 void inordertrav(struct node *n)     
 { 
    if (n != 0)   
        {  inordertrav(n->lchild);             
           printf("   %d   ", n->data);       
           inordertrav(n->rchild);            
        }
 }

/*performs postordertransversal using recursion */
  void postordertrav(struct node *n)  
 { 
    if (n != 0)   
        {  postordertrav(n->lchild);             
           postordertrav(n->rchild);             
           printf("   %d   ", n->data);       
        }
 }

 /*performs pretransversal using recursion */
 void preordertrav(struct node *n)
 {
    if (n != 0)   
        {   
           printf("   %d   ", n->data);
           preordertrav(n->lchild);             
           preordertrav(n->rchild);           
                 
        }

 }


/*Display output trees */
void display()                                  
 { int level,i=0, count =1;
          
        if(start == NULL)
        printf("\n Binary tree  is empty!    \n");        
        else
             {     printf(" display of node number and data  of  the nodes in the Binary tree\n");
                   for(i=1; i<=no_nodes; i++)
                   {temp = build_node[i];
                    if (temp!=0)
                    printf(" (%d,  %d)   ",i, temp->data); 
                   }
                 
                   printf("\n Hierarchy of nodes in the  Binary tree:    \n"); 
                   level =1; 
                   i=1;
                   while(i<=no_nodes)                    
                   { temp = build_node[i];
                     if (temp !=0) printf("   %d    ", temp->data);
                     else  printf("     0     "); 
                     count = count +1;
                     i=i+1;
                     if (count>pow(2,level-1)){ printf("\n\n");
                                                count =1;
                                                level =level +1;
                                              }
                   } 
                 
            }
                
 }
