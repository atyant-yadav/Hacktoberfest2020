#include<iostream>
using namespace std;

// The first node structure.
struct node
{
    int data;
    struct node* next;
};
struct node *head = NULL;

// function to add data at the place of head
void insertbegin(int new_data)
{
    struct node* new_node;
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = head;
    head = new_node;
}

//function to add data at the end
void insertend(int new_data)
{
    struct node *new_node;
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = NULL;
    struct node *temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}

//function to add the data after the position given in arguement
void insertafterpoint(int new_data,int position)
{
    struct node *new_node;
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    struct node* temp = head;
    while(temp->data != position)
    {
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}
void display()
{
    struct node* ptr;
    ptr = head;
    while(ptr != NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
}

int main()
{
    insertbegin(1);
    insertbegin(2);
    insertbegin(3);
    insertend(0);
    insertafterpoint(4,3);
    cout<<"The linked list is: ";
    display();
    return 0;
}
