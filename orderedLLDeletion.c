#include <stdlib.h>
#include <stdio.h>

struct node{
    int data;
    struct node * next;
    struct node * prev;
};

struct node * head;

void insertAtPos(int n){

    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp->data=n;
    temp->next=NULL;
    temp->prev=NULL;

    if(head==NULL){
        head=temp;
    }
    else{
        struct node * p = head;
        if(n<=p->data){
            temp->next=head;
            head->prev=temp;
            head=temp;
        }
        else{
            struct node * par;
            while(p!=NULL&&n>p->data){
                par=p;
                p=p->next;
            }
            struct node * second = par->next;
            par->next=temp;
            temp->prev=par;
            if(second!=NULL){
                second->prev=temp;
            }
            temp->next=second;
        }
    }
}

void display(){
    struct node * p = head;
    if(head==NULL){
        printf("\nEmpty Queue");
        return;
    }
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }

}

void main(){
    int ch,n,pos;

    printf("Choose an operation \n");
    printf("1.  Push an element \n");
    printf("2.  Display all the elements \n");
    printf("3.  Exit \n");
    
    while(1){
        printf("\n Enter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("Enter the element to be pushed: ");
                    scanf("%d",&n);
                    insertAtPos(n);
                    break;
            case 2: display();
                    break;
            case 3: exit(1);
                    break;
            default: printf("\n No such choice exists");
                    break;
        }
    }
}