#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <ctype.h>

#define length 30

char arr[length];
int top=-1;

int priority(char ch){
    if(ch=='('){
        return 0;
    }
    if(ch=='^'){
        return 3;
    }
    if(ch=='/'||ch=='*'||ch=='%'){
        return 2;
    }
    if(ch=='+'||ch=='-'){
        return 1;
    }
    return 0;
}

void push(char ch){
    arr[++top]=ch;
}

char pop(){
    if(top==-1){
        return -1;
    }
    return arr[top--];
}


void main(){
    char infix[30];
    printf("Enter infix expression: ");
    scanf("%s",infix);

    char * ptr;
    ptr = infix;
    
    while(*ptr!='\0'){

        char ch = *ptr;

        if(isalnum(ch)){
            printf("%c ",ch);
        }
        else if(ch=='('){
            push('(');
        }
        else if(ch==')'){
            char tc = pop();
            while(tc!='('){
                printf("%c ",tc);
                tc=pop();
            }
        }
        else {
            while(priority(ch)<=priority(arr[top])){
                printf("%c ",pop());
            }
            push(ch);
        }
        ptr++;
    }

    while(top!=-1){
        printf("%c ",pop());
    }

}