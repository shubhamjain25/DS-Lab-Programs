#include <stdlib.h>
#include <stdio.h>

struct node{
    int data;
    struct node * next;
    struct node * prev;
};

struct node * head;
struct node * tail;

int size=0;

void deleteAtPos(int pos){
    if(pos<1||pos>size){
        printf("Invalid position \n");
        return;
    }

    int deletedNum;
    struct node * temp=head;

    if(pos==1){
        head=temp->next;
        if(head!=NULL){head->prev=NULL;}
        temp->next=NULL;
        deletedNum=temp->data;
        free(temp);
    }
    pos=pos-1;
    while(pos--){
        if(pos==0){
            struct node * p;
            p=temp->next;
            deletedNum=p->data;
            temp->next=p->next;
            if(temp->next!=NULL){
                temp->next->prev=temp;
            }
            p->next=NULL;
            p->prev=NULL;
            free(p);
        }
        temp=temp->next;
    }
    size--;
}

void insertAtPos(int num, int pos){
    if(pos<1||pos>size+1){
        printf("Invalid position \n");
        return;
    }

    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp->data=num;
    temp->next=NULL;
    temp->prev=NULL;

    if(pos==1){
        if(size!=0){
            head->prev = temp;
        }
        temp->next=head;
        head=temp;
    }

    struct node * p = head;
    pos=pos-1;
    while(pos--){
        if(pos==0){
            struct node * sec = p->next;
            if(sec!=NULL){
                sec->prev=p;
            } 
            temp->next=p->next;
            temp->prev=p;
            p->next=temp;
        }
        p=p->next;
    }
    size++;
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
    printf("1.  Push an element at a position \n");
    printf("2.  Delete the element from a position\n");
    printf("3.  Display all the elements \n");
    printf("4.  Exit \n");
    
    while(1){
        printf("\n Enter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("Enter the element to be pushed: ");
                    scanf("%d",&n);
                    printf("Enter the position to be pushed at: ");
                    scanf("%d",&pos);
                    insertAtPos(n,pos);
                    break;
            
            case 2: printf("Enter the position at which element is to be deleted: ");
                    scanf("%d",&pos);
                    deleteAtPos(pos);
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