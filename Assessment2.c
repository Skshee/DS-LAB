// Construct a binary tree and count number of odd and even data

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* root=NULL;
int EvenCount=0;
int OddCount=0;


struct Node* createNode(int data){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->left=newNode->right=NULL;
    return newNode;
};

struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

struct Node* InorderTraversal(struct Node* root){
        if(root==NULL)return;
        root->left=InorderTraversal(root->left);
        if((root->data)%2==0){
            EvenCount++;
        }
        else{
            OddCount++;
        }
    return root;
};

int main(){
    int choice,value;
    while(1){
    printf("1.Insert\n");
    printf("2.Count\n");
    printf("3.Exit\n");
    printf("1.Enter Choice:");
    scanf("%d",&choice);
    switch(choice){
        case 1: printf("Enter insertion value:\n");
                scanf("%d",&value);
                insertNode(root,value);
                break;
        case 2: InorderTraversal(root);
                printf("OddCount:%d\n",OddCount);
                printf("EvenCount:%d\n",EvenCount);
                break;
        case 3: exit(0);
                break;
        default:printf("Invalid");
    }
    }

}
