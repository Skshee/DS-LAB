#include<stdio.h>
#include<stdlib.h>

struct DNode{
    int data;
    struct DNode *llink;
    struct DNode *rlink;
};

 struct DNode *Traversal(struct DNode* head){
    struct DNode* current = head;
    while(current!=NULL){
        printf("%d\n",current->data);
        current=current->rlink;
    }
 }

struct DNode *InsertAtEnd(struct DNode* head, int data){
    struct DNode* p = (struct DNode*)malloc(sizeof(struct DNode));
    struct DNode* current = head;
    p->data=data;
    p->rlink=NULL;
    p->llink=NULL;

    if(head==NULL)
    {
        head=p;
        return head;
    }

    while(current->rlink!=NULL){
        current=current->rlink;
    }
    current->rlink=p;
    p->llink=current;
    return head;
};

struct DNode *InsertAtPosition(struct DNode* head,int position, int data){
    struct DNode* p = (struct DNode*)malloc(sizeof(struct DNode));
    struct DNode* current = head;
    p->data=data;
    p->rlink=NULL;
    p->llink=NULL;

    if(position == 1){
        p->rlink = head;
        head = p;
        return head;
    }

    int i;
    for(i=1;i<position-1;i++){
        current=current->rlink;
        if(current == NULL){
            printf("Position out of range\n");
            return head;
        }
    }
    p->rlink=current->rlink;
    current->rlink=p;
    p->llink=current;
    return head;
};

struct DNode *InsertAfterElement(struct DNode* head, int data,int element){
    struct DNode* p = (struct DNode*)malloc(sizeof(struct DNode));
    struct DNode* current = head;
    p->data=data;
    p->rlink=NULL;
    p->llink=NULL;

    if(head==NULL)
    {
        printf("Element does not exist in list");
        return head;
    }

    while(current->rlink!=NULL){
       if(current->data!=element){
            current=current->rlink;
       }
       else{
            p->rlink=current->rlink;
            current->rlink=p;
            p->llink=current;
       }
}
return head;
}

struct DNode *DeleteAtEnd(struct DNode* head){
struct DNode* p=head;
struct DNode* q=head->rlink;
while(q->rlink!=NULL)
{
    p=p->rlink;
    q=q->rlink;
}
p->rlink=NULL;
free(q);
return head;
};

struct DNode *DeleteAtPosition(struct DNode* head,int position){
struct DNode *p=head;
struct DNode *q=head->rlink;
for(int i=0;i<position-2;i++)
{
   p=p->rlink;
   q=q->rlink;
}
    p->rlink=q->rlink;
    free(q);
    return head;
}

int main()
{
    struct DNode *head=NULL;
    int choice;
    int data,element;
    int position;
    while (1) {
        printf("1. Insert a Node at end \n");
        printf("2. Insert a Node at a position\n");
        printf("3. DeleteAtEnd\n");
        printf("4. Delete at position\n");
        printf("5. Insert After Element\n");
        printf("6. Traversal\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: printf("Enter the value to place at end:");
                    scanf("%d",&data);
                    head = InsertAtEnd(head,data);
                    break;
            case 2: printf("Enter the position:");
                    scanf("%d",&position);
                    printf("Enter the value:");
                    scanf("%d",&data);
                    head = InsertAtPosition(head,position,data);
                    break;
            case 3: head = DeleteAtEnd(head);
                    break;
            case 4: printf("Enter the position:");
                    scanf("%d",&position);
                    head = DeleteAtPosition(head,position);
                    break;
            case 5: printf("Enter the element to put the node after:");
                    scanf("%d",&element);
                    printf("Enter the value:");
                    scanf("%d",&data);
                    head = InsertAfterElement(head,data,element);
            case 6: Traversal(head);
                    break;
            case 7: printf("Exiting\n");
                    return 0;
                    break;
            default: printf("Invalid Input");
                    break;
        }
    }
}

