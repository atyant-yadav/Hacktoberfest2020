#include <stdio.h>
#include <stdlib.h>
struct btnode
{ int value;
    struct btnode *l;
    struct btnode *r;
}*root = NULL, *ptr = NULL, *t2, *t1;
void insertion();
void deletion();
void delete_node(struct btnode *t);
void i_search(struct btnode *t);
void d_search(struct btnode *t,int data);
int smallest(struct btnode *t);
int largest(struct btnode *t);
void inorder(struct btnode *t);
void preorder(struct btnode *t);
void postorder(struct btnode *t);
int flag = 1;
int main()
{ int ch;
    printf("1 - Insert an element into tree\n");
    printf("2 - Delete an element from the tree\n");
    printf("3 - Inorder Traversal\n");
    printf("4 - Preorder Traversal\n");
    printf("5 - Postorder Traversal\n");
    printf("6 - Exit");
    while(1)
    { printf("\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        { case 1:
            insertion();
            break;
            case 2:
            deletion();
            break;
            case 3:
            inorder(root);
            break;
            case 4:
            preorder(root);
            break;
            case 5:
            postorder(root);
            break;
            case 6:
            exit(0);
            default :
            printf("Wrong choice, Please enter correct choice ");
            break;
        }
    }
    return 0;
}
void insertion()// To insert a node in the tree
{ int data;
    printf("Enter data of node to be inserted : ");
    scanf("%d", &data);
    ptr = (struct btnode *)malloc(1*sizeof(struct btnode));
    ptr->value = data;
    ptr->l = ptr->r = NULL;
    if (root == NULL)
        root = ptr;
    else
        i_search(root);
}
void i_search(struct btnode *t)//to search the appropriate position to insert the new node
{
    if ((ptr->value > t->value) && (t->r != NULL)) /* value more than root node value insert at right */
        i_search(t->r);
    else if ((ptr->value > t->value) && (t->r == NULL))
        t->r = ptr;
    else if ((ptr->value < t->value) && (t->l != NULL)) /* value less than root node value insert at left */
        i_search(t->l);
    else if ((ptr->value < t->value) && (t->l == NULL))
        t->l = ptr;
}
void deletion()//to check for the deleted node
{ int data;
    if (root == NULL)
    { printf("No elements in a tree to delete");
        return;
    }
    printf("Enter the data to be deleted : ");
    scanf("%d", &data);
    t1 = root;
    t2 = root;
    d_search(root, data);
}
void d_search(struct btnode *t, int data)//search for the appropriate position to delete node
{ if ((data>t->value))
    { t1 = t;
        d_search(t->r, data);
    }
    else if ((data < t->value))
    { t1 = t;
        d_search(t->l, data);
    }
    else if ((data==t->value))
    { delete_node(t);
    }
}
void delete_node(struct btnode *t)//to delete a node
{ int k;
    if ((t->l == NULL) && (t->r == NULL))//to delete leaf node
    { if (t1->l == t)
        { t1->l = NULL;
        }
        else
        { t1->r = NULL;
        }
        free(t);
        return;
    }
    else if ((t->r == NULL))//to delete node having one left hand child
    { if (t1 == t)
        { root = t->l;
            t1 = root;
        }
        else if (t1->l == t)
        { t1->l = t->l;
        }
        else
        { t1->r = t->l;
        }
        free(t);
        return;
    }
    else if (t->l == NULL)//to delete node having right hand child
    { if (t1 == t)
        { root = t->r;
            t1 = root;
        }
        else if (t1->r == t)
            t1->r = t->r;
        else
            t1->l = t->r;
        free(t);
        return;
    }
    else if ((t->l != NULL) && (t->r != NULL))//to delete node having two child
    { t2 = root;
        if (t->r != NULL)
        { k = smallest(t->r);
            flag = 1;
        }
        else
        { k =largest(t->l);
            flag = 2;
        }
        d_search(root, k);
        t->value = k;
    }
}
int smallest(struct btnode *t)//to find the smallest element in the right sub tree
{ t2 = t;
    if (t->l != NULL)
    { t2 = t;
        return(smallest(t->l));
    }
    else
        return (t->value);
}
int largest(struct btnode *t)//to find the largest element in the left sub tree
{ if (t->r != NULL)
    { t2 = t;
        return(largest(t->r));
    }
    else
        return(t->value);
}
void inorder(struct btnode *t)
{ if (root == NULL)
    { printf("No elements in a tree to display");
        return;
    }
    if (t->l != NULL)
        inorder(t->l);
    printf("%d -> ", t->value);
    if (t->r != NULL)
        inorder(t->r);
}
void preorder(struct btnode *t)
{ if (root == NULL)
    { printf("No elements in a tree to display");
        return;
    }
    printf("%d -> ", t->value);
    if (t->l != NULL)
        preorder(t->l);
    if (t->r != NULL)
        preorder(t->r);
}
void postorder(struct btnode *t)
{ if (root == NULL)
    { printf("No elements in a tree to display ");
        return;
    }
    if (t->l != NULL)
        postorder(t->l);
    if (t->r != NULL)
        postorder(t->r);
    printf("%d -> ", t->value);
}
