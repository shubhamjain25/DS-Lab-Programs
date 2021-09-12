#include <stdlib.h>
#include <stdio.h>

struct node{
    int data;
    struct node * next;
    struct node * prev;
};

struct node * head;

void insert(int num){

    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp->data=num;
    temp->next=NULL;
    temp->prev=NULL;
    
    struct node * p = head;
    struct node * par = NULL;

    while(p!=NULL&&num>p->data){
        par=p;
        p=p->next;
    }

    if(par==NULL){
        if(head!=NULL){
            head->prev=temp;
        }
        temp->next=head;
        head=temp;
    }

    else{
        temp->next=par->next;
        temp->prev=par;
        if(par->next!=NULL){
            par->next->prev=temp;
        }
        par->next=temp;
    }

    printf("Element entered successfully");
}

void display(){
    struct node * p = head;
    if(p==NULL){
        printf("No elements present");
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
    printf("1.  Push an element\n");
    printf("2.  Display all the elements \n");
    printf("3.  Exit \n");
    
    while(1){
        printf("\n Enter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("Enter the element to be pushed: ");
                    scanf("%d",&n);
                    insert(n);
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