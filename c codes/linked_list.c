# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>

# define Data int
# define DataDefaultValue 0;


typedef struct node {
    Data data;
    struct node *next;
} Node;


Node *newNode(Data data, Node *next) {
    Node *pnode = (Node *) calloc(1, sizeof(Node));
    pnode->data = data;
    pnode->next = next;
    return pnode;
}

typedef struct list {
    Node *head, *tail;
} List;

List *newList(Node *head, Node *tail) {
    List *plist = (List *) calloc(1, sizeof(List));
    plist->head = head;
    plist->tail = tail;
    return plist;
}

int addWhenEmpty(List *plist, Data data) {
    if (plist->head) {
        return -1;
    }
    plist->head = plist->tail = newNode(data, NULL);
    plist->head->next = plist->head;
    return 0;
}

void addFirst(List *plist, Data data) {
    if (plist->head == NULL) {
        addWhenEmpty(plist, data);
        return;
    }
    plist->head = newNode(data, plist->head);
    plist->tail->next = plist->head;
}

Data removeFirst(List *plist) {
    if (plist->head == NULL) {
        fprintf(stderr, "Failed to remove.\n");
        return DataDefaultValue;
    }
    if (plist->head == plist->tail) {
        Data data = plist->head->data;
        free(plist->head);
        plist->head = plist->tail = NULL;
        return data;
    }
    Data data = plist->head->data;
    plist->head = plist->head->next;
    free(plist->tail->next);
    plist->tail->next = plist->head;
    return data;
}

void printList(List *plist) {
    Node *pnode = plist->head;
    if (pnode == NULL) {
        printf("NULL\n");
        return;
    }
    do {
        printf("%d -> ", pnode->data);
        pnode = pnode->next;
    } while (pnode != plist->head);
    printf("HEAD\n");
    return;
}

int main(int argc, char *argv[]) {
    List *plist = newList(NULL, NULL);
    int k = 1,c,v;

    while(k != 0){

        printf("1. Print List.\n");
        printf("2. Add element at first of the List.\n");
        printf("3. Remove element from the first of the List.\n");
        printf("4. Exit the program.\n");
        printf("Enter your choice: ");
        scanf("%d", &c);
        switch(c){
            case 1: printList(plist);
                    break;
            case 2: printf("Enter the element value: ");
                    scanf("%d", &v);
                    addFirst(plist,v);
                    break;
            case 3: removeFirst(plist);
                    break;
            case 4: printf("Exiting");
                    k=0;
                    break;
            default: printf("Invalid input");
        }

    }
 return 0;
}
