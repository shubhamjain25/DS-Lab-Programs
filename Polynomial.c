#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
    int coeff;
    int pow;
    struct node * next;
};

struct node * head;

void push(){

    int n;
    printf("Enter the highest power of X: ");
    scanf("%d",&n);

    for(int i=n;i>=0;i--){
        
        int p;
        printf("Enter the coeff for x^%d: ",i);
        scanf("%d",&p);

        if(p==0){continue;}

        struct node * temp = (struct node *)malloc(sizeof(struct node));
        temp->coeff=p;
        temp->pow=i;
        temp->next=NULL;

        if(head==NULL){
            head=temp;
        }
        else{
            struct node * p = head;
            while(p->next!=NULL){p=p->next;}
            p->next=temp;
        }
    }

}

void display(){
    struct node * p = head;
    if(head==NULL){
        printf("\nNo equation exists");
        return;
    }
    while(p->next!=NULL){
        printf("(%d)X^%d + ",p->coeff,p->pow);
        p=p->next;
    }
    printf("(%d)X^%d",p->coeff,p->pow);
}

void evaluate(int val){
    struct node * p = head;
    int res=0;
    if(head==NULL){
        printf("\nNo equation exists");
        return;
    }
    while(p!=NULL){
        res+=(p->coeff)*pow(val,p->pow);
        p=p->next;
    }
    printf("\n The result equals %d",res);
}

void main(){

    int val;
    push();
    display();
    printf("\n Enter the value of X: ");
    scanf("%d",&val);
    evaluate(val);

}