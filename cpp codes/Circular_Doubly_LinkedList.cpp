/*
Write a program to create a circular doubly linked list. You program should be able to perform the following operations:
1) Inserting a node at the beginning,
2) Inserting a node at the end,
3) Inserting a node before a given location,
4) Inserting a node after a given location,
5) Delete the first node,
6) Delete the last node, and
7) Delete a node at a specific location.
*/
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
//structure defination of doubly linked list
struct node
{
    string s;
    struct node * next;
    struct node * prev;
};

//creating a node;
struct node * create(string a)
{
    struct node * new_node = new node;
    new_node->s = a;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}


void insertBegin(struct node **start, struct node **end, string a)
{
    struct node * temp = create(a);
    
    //Base Case , if no element is present
    if(*start == NULL)
    {
        *start = *end = temp;
        temp->next = *start;
        temp->prev = *start;
    }

    //Next case
    else
    {
        (*start)->prev = temp;
        temp->next = *start;
        (*end)->next = temp;
        temp->prev = *end;
        *start = temp;
    }
}
void insertEnd(struct node **start, struct node **end, string a)
{
    struct node * temp = create(a);
    
    //Base Case , if no element is present
    if(*start == NULL)
    {
        *start = *end = temp;
        (*start)->next = *start;
        (*start)->prev = *start;
    }

    //Next Case
    else
    {
        (*start)->prev = temp;
        temp->next = *start;
        (*end)->next = temp;
        temp->prev = *end;
        *end = temp;
    }
}

// Find the location of a given node using its data element
struct node * findLoc(struct node * start, struct node * end, string a)
{
    while(start != end)
    {
        if(start->s == a)
            return start;
        start = start->next;
    }
    if(end->s == a)
        return end;
    else
        return NULL;
}

void insertBefore(struct node **start, struct node **end, string a, string b)
{
    struct node * Loc = findLoc(*start, *end, b);
    struct node * temp = create(a);
    
    // If element is not found in the node
    if(Loc == NULL)
        cout<<"Element node not found before which new node is to be inserted\n";
    //Next Case
    else
    {
        Loc->prev->next = temp;
        temp->prev = Loc->prev;
        Loc->prev = temp;
        temp->next = Loc;
        if(Loc == *start)   // if found node is start node the new node becomes start node
            *start = temp; 
    }
}
void insertAfter(struct node **start, struct node **end, string a, string b)
{
    struct node * Loc = findLoc(*start, *end, b);
    struct node * temp = create(a);
    
    // If element is not found in the node
    if(Loc == NULL)
        cout<<"Element node not found after which new node is to be inserted\n";
    
    //Next Case
    else
    {
        Loc->next->prev = temp;
        temp->next = Loc->next;
        Loc->next = temp;
        temp->prev = Loc;
        if(Loc == *end)     // if found node is end node the new node becomes end node
            *end = temp;
    }
}
void deleteFirst(struct node **start, struct node **end)
{

    //Base Case , If no element Present
    if(*start == NULL)
        cout<<"List is Empty. No nodes to be deleted.\n";
    
    // If Only One node present
    else if (*start == *end)
    {
        struct node * temp = *start;
        *start = *end = NULL;
        free(temp);
    }

    //Next Case
    else
    {
        struct node * temp = *start;
        *start = (*start)->next;
        (*start)->prev = *end;
        (*end)->next = *start;
        temp->next = NULL;
        temp->prev = NULL;
        free(temp);
    }  
}
void deleteLast(struct node **start, struct node **end)
{

    //Base Case , If no element Present
    if(*start == NULL)
        cout<<"List is Empty. No nodes to be deleted.\n";

    // If Only One node present
    else if (*start == *end)
    {
        struct node * temp = *start;
        *start = *end = NULL;
        free(temp);
    }

    //Next Case
    else
    {
        struct node * temp = *end;
        *end = (*end)->prev;
        (*end)->next = *start;
        (*start)->prev = *end;
        temp->next = NULL;
        temp->prev = NULL;
        free(temp);
    }   
}
void deleteLoc(struct node **start, struct node **end, string b)
{
    struct node * Loc = findLoc(*start, *end, b);
    
    //Base Case , If no such element found to be deleted 
    if(Loc == NULL)
        cout<<"No such node found to be deleted.\n";

    // If only one node in list and it is to be deleted
    else if(*start == Loc && *end == Loc)
    {
        struct node * temp = *start;
        *start = *end = NULL;
        free(temp);
    }

    //Next Case
    else
    {
        Loc->prev->next = Loc->next;
        Loc->next->prev = Loc->prev;
        if(Loc == *end)                 //If Found node is end node, then end node is shifted to previous
            *end = Loc->prev;
        else if(Loc == *start)          //If Found node is start node, then start node is shifted to next
        if(Loc == *end)                 
        if(Loc == *end)                 
            *start = Loc->next;
        Loc->next = NULL;
        Loc->prev = NULL;
        free(Loc);
    }
}

//Displaying the List structure
void display (struct node * start, struct node * end)
{
    if(start == NULL)
        cout<<"List is Empty.\n";
    else
    {
        while (start != end)
        {
            cout<<start->s<<"->";
            start = start->next;
        }
    cout<<end->s<<"\n";
    }
}


int main ()
{
    struct node * start = NULL;
    struct node * end = NULL;
    char ch;
    int ch1;
    string value, value1;
    cout<<"Menu Driven Program for Circular doubly linked list.\n";
    cout<<"Press 1 to perform insertion at beginning.\n";
    cout<<"Press 2 to perforn insertion at end.\n";
    cout<<"Press 3 to perforn insertion before a specific node.\n";
    cout<<"Press 4 to perform insertion after a specific node.\n";
    cout<<"Press 5 to perform deletion at beginning.\n";
    cout<<"Press 6 to perform deletion at end.\n";
    cout<<"Press 7 to perform deletion of a specific node.\n";
    cout<<"Press 8 to display the doubly linked list.\n";

    do
    {
        cout<<"Please Enter your choice among '1'   '2'   '3'   '4'   '5'   '6'   '7'   '8'.\n";
        cin>>ch1;
        switch(ch1)                             // menu driven cases
        {
            case 1: cout<<"Enter element to be inserted.\n";
                    cin>>value;
                    insertBegin(&start, &end, value);
                    break;
            case 2: cout<<"Enter element to be inserted.\n";
                    cin>>value;
                    insertEnd(&start, &end, value);
                    break;
            case 3: cout<<"Enter a node element before which new value is to be inserted.\n";
                    cin>>value1;
                    cout<<"Enter new element to be inserted.\n";
                    cin>>value;
                    insertBefore(&start, &end, value, value1);
                    break;       
            case 4: cout<<"Enter a node element after which new value is to be inserted.\n";
                    cin>>value1;
                    cout<<"Enter new element to be inserted.\n";
                    cin>>value;
                    insertAfter(&start, &end, value, value1);
                    break;
            case 5: deleteFirst(&start, &end);
                    break;
            case 6: deleteLast(&start, &end);
                    break;
            case 7: cout<<"Enter a node element which is to be deleted.\n";
                    cin>>value;
                    deleteLoc(&start, &end, value);
                    break;
            case 8:cout<<"The given linked list elements are : \n";
                    display(start, end);
                    break;
            default:cout<<"Wrong Choice Entered.\n";
        }
        cout<<"Dou you want to continue performing operation?.\n";
        cout<<"Enter y for YES else n for NO.\n";
        cin>>ch;
    } while (ch == 'y' || ch == 'Y');
    return 0;
}