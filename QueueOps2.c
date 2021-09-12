#include <stdlib.h>
#include <stdio.h>
#define length 5

int arr[length];
int curr=-1;

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
    return curr==length-1?1:0;
}

int isEmpty(){
    return curr==-1?1:0;
}

void enter(){
    if(isFull()){
        printf("Stack overflow \n");
        return;
    }
    int n;
    printf("Enter the element to be entered: ");
    scanf("%d",&n);
    arr[++curr]=n;
}

void delete(){
    if(isEmpty()){
        printf("Stack underflow \n");
        return;
    }
    printf("Element deleted is %d",arr[0]);
    for(int i=0;i<curr;i++){
        arr[i]=arr[i+1];1
    }
    curr--;
}

void display(){
    if(isEmpty()){
        printf("\n Stack underflow");
        return;
    }
    printf("\nElements are: \n");
    for(int i=0;i<=curr;i++){
        printf("%d ",arr[i]);
    }
}