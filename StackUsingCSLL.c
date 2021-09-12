#include <stdlib.h>
#include <stdio.h>

struct node{
    int data;
    struct node * next;
};

struct node * head = NULL;

void pop(){

    int dno;
    struct node * del = head;
    
    if(head==NULL){
        printf("\nStack Overflow");
        return;
    }

    if(head->next==head){
        head=NULL;
    }

    else{
        struct node * p = head;
        p=p->next;
        while(p->next!=head){
            p=p->next;
        }
        p->next=head->next;
        head=head->next;
    }

    dno=del->data;
    del->next=NULL;
    free(del);

    printf("Deleted Number equals %d",dno);
}

void push(int n){
    
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp->data=n;
    temp->next=NULL;

    struct node * p = head;
    if(p!=NULL){
        p=p->next;
        while(p->next!=head){
            p=p->next;
        }
        p->next=temp;
        temp->next=head;
    }
    else{
        temp->next=temp;
    }
    head=temp;
    
    printf("Element inserted successfully");
}

void display(){
    if(head == NULL){
        printf("\nThe linked list is empty");
    }
    else{
        printf("\nThe elements of the linked list are: ");
        printf("%d ",head->data);
        struct node * p = head->next;
        while(p!= head){
            printf("%d ",p->data);
            p = p->next;
        }
    }
}

void main(){
    int ch,n,pos;

    printf("Choose an operation \n");
    printf("1.  Push \n");
    printf("2.  Pop \n");
    printf("3.  Display \n");
    printf("4.  Exit \n");
    
    while(1){
        printf("\n Enter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("Enter the element to be pushed: ");
                    scanf("%d",&n);
                    push(n);
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