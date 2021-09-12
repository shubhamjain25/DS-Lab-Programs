#include <stdlib.h>
#include <stdio.h>

struct node{
    int data;
    struct node * next;
};

struct node * top=NULL;

int isEmpty(){
    return top==NULL?1:0;
}

void push(){
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    printf("\n Enter the element to be entered: ");
    scanf("%d",&temp->data);
    temp->next=NULL;
    if(top!=NULL){
        temp->next=top;
    }
    top=temp;
}

void pop(){
    int deletedNum;
    if(isEmpty()){
        printf("\n Stack underflow");
    }
    else{
        deletedNum=top->data;
        struct node * del = top;
        printf(" \n The element to be deleted is %d", deletedNum);
        top=top->next;
        free(del);   
    }
}

void display(){
    if(isEmpty()){
        printf("\n Stack underflow");
        return;
    }
    else{
        printf("\n Elements are: ");
        struct node * temp = top;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }  
    }
}

void main(){
    int ch;

    printf("Choose an operation \n");
    printf("1.  Push an element \n");
    printf("2.  Pop an element \n");
    printf("3.  Display all the elements \n");
    printf("4.  Exit \n");
    
    while(1){
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: push();
            break;
            case 2: pop();
            break;
            case 3: display();
            break;
            case 4: exit(1);
            break;
            default: printf("\n No such choice exists");
            break;
        }
    }

}