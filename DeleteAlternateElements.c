#include <stdlib.h>
#include <stdio.h>

struct node{
    int data;
    struct node * next;
};

struct node * head;

void push(int num){
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp->data=num;
    temp->next=NULL;
    if(head==NULL){
        head=temp;
    }
    else{
        struct node * p = head;
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=temp;
    }
}

void deleteAlternative(){

    if(head==NULL){
        printf("\n No elements present");
        return;
    }

    struct node * prev=head;
    struct node * del=head->next;

    while(prev!=NULL&&del!=NULL){
        prev->next = del->next;
        del->next=NULL;
        free(del);
        prev=prev->next;
        if(prev!=NULL){
            del=prev->next;
        }    
    }

}

void display(){
    struct node * p = head;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }    
}

void main(){
    int ch,n;

    printf("\nChoose an operation");
    printf("\n1.  Push an element");
    printf("\n2.  Delete all alternate position elements");
    printf("\n3.  Display all the elements ");
    printf("\n4.  Exit");
    
    while(1){
        printf("\n Enter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("Enter the element to be pushed: ");
                    scanf("%d",&n);
                    push(n);
                    break;
            case 2: deleteAlternative();
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