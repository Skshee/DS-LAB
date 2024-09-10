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
     printf("%d\n",ptr->data);
     ptr= ptr->next;
    }
}

struct Node* deleteAtIndex(struct Node* head,int index)
{
 //struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
 struct Node* p=head;
 struct Node* q=head->next;
 int i=0;
 while(i!=index-1)
 {
   p=p->next;
   q=q->next;
   i++;
 }
  p->next=q->next;
  free(q);
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

head=deleteAtIndex(head,1);

linkedlistTraversal(head);
free(head);
free(second);
free(third);

return 0;
}

