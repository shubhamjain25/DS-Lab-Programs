#include <stdlib.h>
#include <stdio.h>

int s=0;

void main(){
    int n, sum=1;
    printf("\n Enter the number of terms you want ");
    scanf("%d",&n);
    if(n<=0){
        printf("Not possible");
    }
    else if(n==1){
        sum=0;
        printf("\n Sum of elements equals %d",sum);
    }
    else{
        printf("\n Fibonacci Series");
        printf("\n 0");
        printf("\n 1");
        fib(n-2);
    }

}

void fib(int num){
    int n1=0, n2=1, n3;
    if(num>0){
        n3=n1+n2;
        n1=n2;
        n2=n3;
        printf("\n %d",n3);
        fib(num-1);
    }
}