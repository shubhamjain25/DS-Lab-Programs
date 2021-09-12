#include <stdlib.h>
#include <stdio.h>
#define length 5

int arr[length];
int f=-1;
int r=-1;

void enter();
void delete();
void display();

void main(){
    int ch;

    printf("Choose an operation \n");
    printf("1.  Enter an element \n");
    printf("2.  Delete an element \n");
    printf("3.  Display all the elements \n");
    printf("4.  Exit \n");
    
    while(1){
        printf("\nEnter your choice: ");
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
    if(r == length-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(){
    if(f==-1){
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
        printf("\n Enter the element to be entered: ");
        scanf("%d",&num);
        if(f==-1){
            f=0;
        }
        arr[++r]=num;
    }
}

void delete(){
    int deletedNum;
    if(isEmpty()){
        printf("\n Stack underflow");
    }
    else{
        deletedNum=arr[0];
        printf(" \n The element to be deleted is %d", deletedNum);
        if(f==r){
            f=-1;
            r=-1;
        }
        else{
            for(int i=0;i<r;i++){
                arr[i]=arr[i+1];
            }
            r--;
        }   
    }
}

void display(){
    if(isEmpty()){
        printf("\n Stack underflow");
        return;
    }
    else{
        printf("\n Elements are");
        for(int i=0;i<=r;i++){
            printf("\n %d", arr[i]);
        }  
    }
}