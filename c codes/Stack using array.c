#include<stdio.h>
#include<stdlib.h>
struct stack {
    int size;
    int top;
    int *arr;
    
};


int isEmpty(struct stack *ptr)
{
    if(ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if(ptr->top==ptr->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct stack *ptr, int val){
    if(isFull(ptr))
    {
        printf("stack is overflow can not push %d to the stack\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}

int pop(struct stack *ptr){
    if(isEmpty(ptr))
    {
        printf("stack is underflow can not pop to the stack\n");
    }
    else
    {
        int val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
        
    }
}
int peek(struct stack *sp, int i){
    if(sp->top-i+1<0){
        printf("not a valid position");
        return -1;
    }
    else{
        return sp->arr[sp->top-i+1];
    }
}

int stackTop(struct stack *sp){
    return sp->arr[sp->top];
}

int stackBottom(struct stack *sp){
    return sp->arr[0];
}

int main(){
    struct stack *sp;
    sp=(struct stack *)malloc(sizeof(struct stack ));
    sp->size=10;
    sp->top=-1;
    sp->arr=(int *)malloc(sp->size * sizeof(int));
    printf("stack is make successfully\n");
    printf("before pushing , empty: %d\n",isEmpty(sp));
    printf("before pushing , full: %d\n",isFull(sp));
    push(sp,1);
    push(sp,2);
    push(sp,3);
    push(sp,4);
    push(sp,5);
    push(sp,6);
    push(sp,7);
    push(sp,8);
    push(sp,9);
    push(sp,10);
    //push(sp,11);
    printf("after pushing,empty: %d\n",isEmpty(sp));
    printf("after pushing ,full: %d\n",isFull(sp));
    
    printf("popped %d from the stack\n",pop(sp));
    printf("popped %d from the stack\n",pop(sp));
    printf("popped %d from the stack\n",pop(sp));
    return 0;
    
    for(int j=0;i<sp->top+1;j++){
        printf("The value of position is %d is %d\n",j,peek(sp,j));
    }
    
    printf("value of stack top is %d",stackTop(sp));
    printf("value of stack bottom is %d",stackBottom(sp));
}



