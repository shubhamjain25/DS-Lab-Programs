#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void TOH(int n, char fromT, char toT, char auxT){
    if(n==1){
        printf("Move tower 1 from %c to %c\n", fromT, toT);
        return;
    }
    TOH(n-1,fromT,auxT,toT);
    printf("Move tower %d from %c to %c\n",n, fromT, toT);
    TOH(n-1,auxT,toT,fromT);
}

int binarySearch(int arr[], int l, int h, int key){
    if(l>h){
        return -1;
    }
    int mid = l+(h-l)/2;
    if(arr[mid]==key){
        return mid;
    }
    else if(arr[mid]>key){
        return binarySearch(arr,l,mid-1,key);
    }
    else{
        return binarySearch(arr,mid+1,h,key);
    }
}

int gcd(int n1, int n2){
    if(n2!=0){
        return gcd(n2,n1%n2);
    }
    else{
        return n1;
    }
}

int main(){
    //Tower of Hanoi
    int n;
    printf("Enter the number of disks: ");
    scanf("%d",&n);
    printf("The sequence of movement:\n");
    TOH(n,'A','C','B');

    // Binary Sarch
    int num,key;
    printf("Enter the size of the list: ");
    scanf("%d",&num);
    int arr[num];
    printf("Enter the elements in the list: ");
    for(int i=0;i<num;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the element to be searched : ");
    scanf("%d",&key);

    int idx = binarySearch(arr,0,num-1,key);

    if(idx!=-1){
        printf("Element is present at index %d",idx);
    }
    else{
        printf("Element is not present");
    }

    //GCD
    int a,b;
    printf("Enter the two numbers: ");
    scanf("%d %d",&a,&b);
    printf("The GCD of the two numbers %d and %d equals %d",a,b,gcd(a,b));
}
