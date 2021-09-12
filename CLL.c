#include <stdlib.h>
#include <stdio.h>

struct node{
    int data;
    struct node * next;
};

struct node * head;
int size=0;

void deleteAtPos(int pos){
    if(pos<1||pos>size){
        printf("Invalid position \n");
        return;
    }
    int deletedNum;
    
    if(pos==1){
        struct node * temp=head;
        deletedNum=temp->data;

        if(size==1){
            head=NULL;
        }

        else{
            struct node * p = head;
            while(p->next!=head){
                p=p->next;
            }
            p->next=head->next;
            head=head->next;
        }

        temp->next=NULL;
        free(temp);
    }

    else if(pos==size){
        struct node * p = head;
        while(p->next->next!=head){
            p=p->next;
        }
        struct node * temp = p->next;
        deletedNum=temp->data;
        p->next=head;
        temp->next=NULL;
        free(temp);
    }

    else{
        pos=pos-1;
        struct node * p = head;
        while(pos--){
            if(pos==0){
                struct node * temp;
                temp=p->next;
                deletedNum=temp->data;
                p->next=temp->next;
                temp->next=NULL;
                free(temp);
            }
            p=p->next;
        }   
    }

    printf("Deleted Number equals %d",deletedNum);
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

    if(pos==1){
        if(head==NULL){
            head=temp;
            temp->next=head;
        }
        else{
            struct node * p = head;
            while(p->next!=head){
                p=p->next;
            }
            p->next=temp;
            temp->next=head;
            head=temp;
        }        
    }

    else if(pos==size+1){
        struct node * p = head;
        while(p->next!=head){
            p=p->next;
        }
        p->next=temp;
        temp->next=head;
    }

    else{
        struct node * p = head;
        pos=pos-1;
        while(pos--){
            if(pos==0){
                temp->next=p->next;
                p->next=temp;
            }
            p=p->next;
        }
    }

    printf("Element inserted successfully");
    size++;
}

void display(){
    if(head == NULL){
        printf("\nThe linked list is empty");
    }
    else{
        printf("\nThe elemnets of the linked list are: ");
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