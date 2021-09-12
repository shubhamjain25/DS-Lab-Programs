#include <stdlib.h>
#include <stdio.h>
#define length 5

int arr[length];
int root=-1;

void push();
void pop();
void display();

void main(){
    int ch;

    printf("Choose an operation \n");
    printf("1.  Push an element \n");
    printf("2.  Pop the element \n");
    printf("3.  Display all the elements \n");
    
    while(1){
        printf("\n Enter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: push();
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

int isFull(){
    if(root == length-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(){
    if(root == -1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(){

    int num;
    if(isFull()){
        printf("\n Stack overflow");
    }
    else{
        printf("\n Enter the element to be pushed ");
        scanf("%d",&num);
        root++;
        arr[root]=num;       
    }
}

void pop(){
    int deletedNum;
    if(isEmpty()){
        printf("\n Stack underflow");
    }
    else{
        deletedNum=arr[root];
        root--;
        printf(" \n The element to be deleted is %d", deletedNum);   
    }
}

void display(){
    if(isEmpty()){
        printf("\n Stack underflow");
        return;
    }
    else{
        printf("\n Elements are");
        for(int i=root;i>=0;i--){
            printf("\n %d", arr[i]);
        }  
    }
}