#include <stdlib.h>
#include <stdio.h>

struct node{
    int data;
    struct node * left;
    struct node * right;
};

struct node * root=NULL;
struct node * tree=NULL;

struct node * createNode(int element){
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp->data = element;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void insert(){

    int num;
    printf("Enter the element to be pushed: ");
    scanf("%d",&num);
    struct node * temp = createNode(num);

    if(root==NULL){
        root=temp;
        tree=root;
    }
    else{
        struct node * p = tree;
        while(1){
            if(num>=p->data&&p->right!=NULL){
                p=p->right;
            }
            else if(num<p->data&&p->left!=NULL){
                p=p->left;
            }
            else{
                break;
            }
        }
        if(num>=p->data){
            printf("\n Stored at right");
            p->right=temp;
        }
        else{
            printf("\n Stored at left");
            p->left=temp;
        }
    }

}

void inOrder(struct node * p){
    if(p==NULL){return;}
    inOrder(p->left);
    printf("%d ",p->data);
    inOrder(p->right);
}

void preOrder(struct node * p){
    if(p==NULL){return;}
    printf("%d ",p->data);
    preOrder(p->left);
    preOrder(p->right);
}

void postOrder(struct node * p){
    if(p==NULL){return;}
    postOrder(p->left);
    postOrder(p->right);
    printf("%d ",p->data);
}

void main(){
    int ch,n,pos;

    printf("Choose an operation \n");
    printf("1.  Push an element\n");
    printf("2.  Pre-order Traversal\n");
    printf("3.  In-order Traversal\n");
    printf("4.  Post-order Traversal\n");
    printf("5.  Exit \n");
    
    while(1){
        printf("\n Enter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: insert();
                    break;
            case 2: printf("\n Pre-order Traversal: ");
                    preOrder(tree);
                    break;
            case 3: printf("\n In-order Traversal: ");
                    inOrder(tree);
                    break;
            case 4: printf("\n Post-order Traversal: ");
                    postOrder(tree);
                    break;
            case 5: exit(1);
                    break;
            default: printf("\n No such choice exists");
                    break;
        }
    }
}