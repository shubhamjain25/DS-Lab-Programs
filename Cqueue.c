#include <stdlib.h>
#include <stdio.h>
#define length 5

int arr[length];
int rear=-1;
int front=-1;

void enter();
void delete();
void display();

void main(){
    int ch;

    printf("Choose an operation \n");
    printf("1.  Enter an element \n");
    printf("2.  Delete an element \n");
    printf("3.  Display all the elements \n");
    
    while(1){
        printf("\n Enter your choice: ");
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

int isFull(){
    if( (rear == length-1&&front==0) || (rear+1==front) ){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(){
    if(rear == -1 && front == -1){
        return 1;
    }
    else{
        return 0;
    }
}

void enter(){

    int num;
    if(isFull()){
        printf("\n Stack overflow");
    }
    else{
        printf("\n Enter the element to be entered ");
        scanf("%d",&num);
        if(rear== -1 && front== -1){
            rear=0;
            front=0;
            arr[rear]=num;
        }
        else if(front>0 && rear==length-1){
            rear=0;
            arr[rear]=num;
        }
        else{
            rear++;
            arr[rear]=num;
        }
    }
}

void delete(){
    int deletedNum;
    if(isEmpty()){
        printf("\n Stack underflow");
    }
    else{
        if(rear==front){
            deletedNum=arr[front];
            front=-1;
            rear=-1;
        }
        else if(front==length-1){
            deletedNum=arr[front];
            front=0;
        }
        else{
            deletedNum=arr[front];
            front++;
        }
        printf(" \n The element to be deleted is %d", deletedNum);  
    }
}

void display(){
    if(isEmpty()){
        printf("\n Stack underflow");
        return;
    }
    else{
        printf("\n Elements are:");
        if(rear>=front){
            for(int i=front;i<=rear;i++){
                printf("%d ",arr[i]);
            }
        }
        else{
            for (int i=front; i<length; i++)
                printf("%d ", arr[i]);
 
            for (int i = 0; i<=rear; i++)
                printf("%d ", arr[i]);
        } 
    }
}