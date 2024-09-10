#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedlistTraversal(struct Node *ptr)
{
    while(ptr!=NULL)
    {
     printf("%d\n",ptr->data);\
     ptr= ptr->next;
    }
}

struct Node* insertAtIndex(struct Node* head,int index,int data)
{
    struct Node* ptr= (struct Node*)malloc(sizeof(struct Node*));
    struct Node* p=head;// IMP STEP I MADE MISTAKE HERE
    for(int i=0;i<index-1;i++)
    {
        p = p->next;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
}

int main()
{
 struct Node *head;
 struct Node *second;
 struct Node *third;


head=(struct Node*)malloc(sizeof(struct Node));
second=(struct Node*)malloc(sizeof(struct Node));
third=(struct Node*)malloc(sizeof(struct Node));

head->data=7;
head->next= second;

second->data=10;
second->next=third;

third->data=900;
third->next=NULL;

insertAtIndex(head,3,11);

linkedlistTraversal(head);
free(head);
free(second);
free(third);
return 0;
}

