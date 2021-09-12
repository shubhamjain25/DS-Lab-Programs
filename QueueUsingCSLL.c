#include <stdlib.h>
#include <stdio.h>

struct node{
    int data;
    struct node * next;
};

struct node * f = NULL;
struct node * r = NULL;


void pop(){

    if(f==NULL){
        printf("\n Queue is empty");
        return;
    }

    int dno;
    struct node * del = f;
    
    if(f==r){
        f=NULL;
        r=NULL;
    }
    else{
        f=f->next;
        r->next=f;
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

    if(r==NULL){
        f=temp;
    }
    else{
        r->next=temp;
    }

    r=temp;
    temp->next=f;
    printf("Element inserted successfully");
}

void display(){
    if(f==NULL){
        printf("\n Queue is empty");
        return;
    }
    struct node * ptr = f;
    printf("\nElements of queue are: ");
    printf("%d ",ptr->data);
    ptr=ptr->next;
    while(ptr!=f){
        printf("%d ",ptr->data);
        ptr=ptr->next;
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