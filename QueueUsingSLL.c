#include <stdlib.h>
#include <stdio.h>

struct node{
    int data;
    struct node * next;
};

struct node * front=NULL;
struct node * rear=NULL;

int isEmpty(){
    return front==NULL?1:0;
}

void enter(){
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    printf("\n Enter the element to be entered: ");
    scanf("%d",&temp->data);
    temp->next=NULL;
    if(rear==NULL){
        front=temp;
        rear=temp;
    }
    else{
        rear->next=temp;
        rear=temp;
    }
}

void delete(){
    int deletedNum;
    if(isEmpty()){
        printf("\n Stack underflow");
    }
    else{
        deletedNum=front->data;
        struct node * temp = front;
        printf(" \n The element to be deleted is %d", deletedNum);
        if(front->next==NULL){
            front = NULL;
            rear = NULL;
        }
        else{
            front=front->next;
        }   
        free(temp);
    }
}

void display(){
    if(isEmpty()){
        printf("\n Stack underflow");
        return;
    }
    else{
        printf("\n Elements are: ");
        struct node * temp = front;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }  
    }
}

void main(){
    int ch;

    printf("Choose an operation \n");
    printf("1.  Enter an element \n");
    printf("2.  Delete an element \n");
    printf("3.  Display all the elements \n");
    printf("4.  Exit \n");
    
    while(1){
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: enter();
            break;
            case 2: delete();
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