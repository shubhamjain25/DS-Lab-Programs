#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

struct node{
    char data;
    struct node * right;
    struct node * left;
};

struct node * head;
struct node * stack[20];
int top=-1;

struct node * createNode(char ch){
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp->data=ch;
    temp->right=NULL;
    temp->left=NULL;
    return temp;
}

void push(char ch){
    struct node * temp = createNode(ch);
    stack[++top]=temp;
}

void popAndPush(char ch){
    struct node * temp = createNode(ch);
    temp->right = stack[top--];
    temp->left = stack[top--];
    stack[++top]=temp;
    head=temp;
}

void inOrder(struct node * p){
    if(p==NULL){
        return;
    }
    inOrder(p->left);
    printf("%c ",p->data);
    inOrder(p->right);
}

int isOperator(char ch){
    if(ch=='/'||ch=='*'||ch=='+'||ch=='-'){
        return 1;    
    }
    return 0;
}

int eval(struct node * p){
    char ch = p->data;
    if(!isOperator(ch)){
        return ch-'0';
    }
    else{
        if(ch=='+'){return eval(p->left)+eval(p->right);}
        if(ch=='-'){return eval(p->left)-eval(p->right);}
        if(ch=='*'){return eval(p->left)*eval(p->right);}
        if(ch=='/'){return eval(p->left)/eval(p->right);}
    }
}

void main(){

    char exp[30];
    printf("\n Enter the of expression: ");
    scanf("%s",exp);

    printf("Length equals %d\n", strlen(exp));
    for(int i=0;i<strlen(exp);i++){
        if(!isOperator(exp[i])){
            // printf("\nPush operation for %c",exp[i]);
            push(exp[i]);
        }
        else{
            // printf("\nPop and Push operation for %c",exp[i]);
            popAndPush(exp[i]);
        }
    }
    inOrder(stack[top]);
    printf("\n Value of the expression: %d",eval(stack[top]));
}