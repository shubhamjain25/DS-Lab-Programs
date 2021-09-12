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
        printf("\nInvalid Position");
        return;
    }

    int dno;
    struct node * del = head;

    if(pos==1){
        head=head->next;
        if(del==tail){
            head=NULL;
            tail=NULL;
        }
        else{
            tail->next = head;
            head->prev=tail;
        }
    }

    else{
        struct node * p = head;
        pos=pos-1;
        while(pos--){
            if(pos==0){
                del=p->next;
                struct node * second = del->next;
                p->next=second;
                second->prev=p;
                if(second==head){
                    tail=p;
                }
            }
            p=p->next;
        }
    }

    dno=del->data;
    printf("Number deleted equals %d",dno);
    del->next=NULL;
    del->prev=NULL;
    free(del);
    size--;
}

void insertAtPos(int num, int pos){
    if(pos<1 || pos>size+1){
        printf("\nInvalid Position");
        return;
    }

    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp->data=num;
    temp->next=NULL;
    temp->prev=NULL;

    if(pos==1){
        temp->next=head;
        if(head!=NULL){
            head->prev=temp;
            tail->next=temp;
        }
        else{
            tail=temp;
            temp->next=tail;
        }
        temp->prev=tail;
        head=temp;
    }
    else{
        struct node * p = head;
        pos--;
        while(pos--){
            if(pos==0){
                struct node * second = p->next;
                if(second==head){
                    tail = temp;
                }
                
                //Left Connection
                p->next=temp;
                temp->prev=p;
                
                //Right Connection
                temp->next=second;
                second->prev=temp;

            }
            p=p->next;
        }
    }
    size++;
}

void display(){
    struct node * p = head;
    if(head==NULL){
        printf("\nEmpty Queue");
        return;
    }
    printf("%d ",p->data);
    p=p->next;
    while(p!=head){
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