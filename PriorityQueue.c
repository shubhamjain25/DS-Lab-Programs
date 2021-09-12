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
    return curr == length-1?1:0;
}

int isEmpty(){
    return curr == -1?1:0;
}

void enter(){
    int num;
    if(isFull()){
        printf("\n Stack overflow");
    }
    else{
        printf("\n Enter the element to be entered ");
        scanf("%d",&num);
        curr++;
        int i,ind;
        for(ind=0;ind<curr;ind++){
            if(arr[ind]>num){break;}
        }
        for(i=curr;i>ind;i--){
            arr[i]=arr[i-1];
        }
        arr[ind]=num;
    }
}

void delete(){
    int deletedNum;
    if(isEmpty()){
        printf("\n Stack underflow");
    }
    else{
        printf(" \n The element to be deleted is %d", arr[0]);
        for(int i=0;i<curr;i++){
            arr[i]=arr[i+1];
        }
        curr--;   
    }
}

void display(){
    if(isEmpty()){
        printf("\n Stack underflow");
        return;
    }
    else{
        printf("\n Elements are");
        for(int i=0;i<=curr;i++){
            printf("\n %d", arr[i]);
        }  
    }
}