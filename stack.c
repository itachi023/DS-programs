#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int s[SIZE];
int top = -1;
int item;

//by passing  the parameter [pointer]
void push();
int pop();
void display();


int main()
{
    int ch;
    int item_deleted;
    
    for(;;)
    {
        printf("Enter the choice\n1  2  3  4\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("enter the item\n");
            scanf("%d",&item);
            push();
            break;
            
        case 2:
            item_deleted=pop();
            if (item_deleted==-1)
            {
                printf("stack is empty");
            }
            else
            {
                printf(" deleted item is %d\n",item_deleted);
            }
            break;

        case 3:
            display();
            break;
        
        case 4:
            exit(0);
            break;
        
        default:
            printf("enter the valid input\n");
            break;
        }
    }


    return 0;
}


void push()
{
    if (top == SIZE - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    top = top + 1;
    s[top] = item;
    // s[++top]= item;
}



int pop()
{
    if (top == -1)
    {
        return -1;
    }
    return s[top--];
}




void display()
{
    if (top == -1)
    {
        printf("stack is Empty!!!\n");
        return;
    }
    for (int i = 0; i <= top; i++)
    {
        printf("%d\t", s[i]);
    }
    printf("\n");
}