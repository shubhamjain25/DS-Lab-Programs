/* Ordered Linked List in Ascending Order*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>  /* For having the maximum value of int by using the variable INT_MAX*/


struct node {
    int data;
    struct node *next;
};

struct node * root;

void insert();
void sortInAscending(struct node * p, int n);
void displayElements();

void main(){
    int ch;
    printf("\n Choose any option");
    printf("\n 1. Insert and Display");
    printf("\n 2. Exit");
    while(1)
    {
        printf("\n Enter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: insert();
                    displayElements();
                    break;
            case 2: printf("\n You have exited the program");
                    exit(1);
                    break;
            default: printf("\n Invalid Choice, Choose again");
                    break;
        }
    }
}

void insert(){
    int n, i;
    struct node * temp;
    printf("\n Enter the number of elements you want to add: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        temp=(struct node *)malloc(sizeof(struct node));
        printf("\n Enter element number %d :",i+1);
        scanf("%d",&temp->data);
        temp->next=NULL;
        if(root==NULL){
            root=temp;
        }
        else{
            struct node * p;
            p=root;
            while(p->next!=NULL){
                p=p->next;
                }
            p->next=temp;
        }
    }
    sortInAscending(root,n);
    
}

 void sortInAscending(struct node * p, int n){
    struct node * minLoc;
    struct node * q;
    int i,duplicate,min=0;

    for(i=0;i<n;i++){
        q=p;
        min=INT_MAX;
        while(q!=NULL){
            if(min>q->data){
                min=q->data;
                minLoc=q;
            }
            q=q->next;
        }
        duplicate=p->data;
        p->data=min;
        minLoc->data=duplicate;
        p=p->next;
    }
}

void displayElements(){
    struct node * p = root;
    printf("\n Ordered Linked List in Ascending Order: ");
    while(p!=NULL){
        printf("\n %d",p->data);
        p=p->next;
    }
}