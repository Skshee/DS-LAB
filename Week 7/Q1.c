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

struct Node* insertAfterElement(struct Node* head,int element,int data)
{
    struct Node* ptr= (struct Node*)malloc(sizeof(struct Node*));
    struct Node* p=head;
    while(p->data!=NULL){
    if(p->data!=element)
    {
        p=p->next;
    }
    else{
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
    }
    }
}

struct Node* insertBeforeElement(struct Node* head,int element,int data)
{
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node*));
    struct Node* p=head;
    while(p->data!=NULL){
    if(p->data!=element)
    {
        p=p->next;
    }
    else{
    ptr->data=data;
    ptr->next=p;
    return head;
    }
  }
}

struct Node* deleteElement(struct Node* head,int element)
{
 //struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
 struct Node* p=head;
 struct Node* q=head->next;
 int i=0;
 while(p->data!=NULL)
 {
   if(q->data!=element){
   p=p->next;
   }
  else{
  p->next=q->next;
  free(q);
  return head;
  }
}
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

second->data=5;
second->next=third;

third->data=900;
third->next=NULL;

    int element,data,choice;
 while (1) {
    printf("1. Insert a Node before an element \n");
    printf("2. Insert a Node after an element\n");
    printf("3. Delete Element\n");
    printf("4. Traversal\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice){
        case 1: printf("Enter the element to place the new node before:");
                scanf("%d",&element);
                printf("Enter the value:");
                scanf("%d",&data);
                insertBeforeElement(head,element,data);
                break;
        case 2: printf("Enter the element to place the new node before:");
                scanf("%d",&element);
                printf("Enter the value:");
                scanf("%d",&data);
                insertAfterElement(head,element,data);
                break;
        case 3: printf("Enter the element to delete:");
                scanf("%d",&element);
                deleteElement(head,element);
                break;
        case 4: linkedlistTraversal(head);
                break;
        case 5:
                printf("Exiting the program.\n");
                return 0;
                break;
        default: printf("Invalid Input");
                break;
    }
}
}
