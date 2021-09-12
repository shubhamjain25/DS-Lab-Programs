#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define length 20

char spc[] = {'/', '*', '+', '-'};

int root = -1;
int arr[length];

void push(int num){
    root++;
    arr[root]=num;       
}

void pop(char spec){
    int new;
    int rNum, lNum;
    
    rNum=arr[root--];
    lNum=arr[root--];

    if(spec==47){
            new = lNum/rNum;    
        }
    else if(spec==42){
            new = lNum*rNum;    
        }
    else if(spec==43){
            new = lNum+rNum;    
        }    
    else if(spec==45){
            new = lNum-rNum;    
    }
    else{
        printf("Invalid Character Entered");
        exit(1);
    }         
    push(new);
}

void finalPop(){
    printf("\n Value comes out to be %d",arr[0]);
    root=-1;
}

void main(){
    int dg;
    int i,j;
    char exp[20];
    printf("\n Enter the postfix expression: ");
    scanf("%[^\n]%*c", exp);
    for(i=0;i<strlen(exp);i++){
        dg = exp[i]-'0';
        if(dg>=0){      /* Digit */
            push(dg);
        }
        else{           /* Special Character */
            pop(exp[i]);
        }
    }
    finalPop();
}
