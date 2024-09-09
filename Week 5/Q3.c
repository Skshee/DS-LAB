#include<stdio.h>
#include<string.h>
#define MAX 20

char stack[20];
int top=-1;

void push(char ele)
{
    if(top==MAX-1)
        printf("Stack Overflow");
    else
        stack[++top]=ele;
}

char pop()
{
    if(top==-1){
        printf("Stack Underflow");
        return '\0';
    }
    else
        return stack[top--];
}

int isOperand(char ele)
{
    if((ele>='A' && ele<='Z')||(ele>='a' && ele<='b'))
        return 1;
    else
        return 0;
}


int main()
{
    char postfix[MAX];
    char ele;
    char i,j;
    printf("Enter the postfix expression:\n");
    scanf("%s",postfix);
    i=0;
    while(i<strlen(postfix))
    {
        ele=postfix[i];
        if(isOperand(ele))
        {
            push(ele);
            push(' ');
        }
        else{
            for(j=top-1;j>=0;j--)
            {
                if(stack[j]==' ')
                {
                    stack[j]=ele;
                }
            }
        }
        //display();
        i++;
    }
    printf("infix expression: %s\n",stack);
}
