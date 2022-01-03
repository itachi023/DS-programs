#include <stdio.h>
#include <stdlib.h>
#define SIZE

void push(int *item, int *top, int s[]);
int pop(int *top, int s[]);
void display(int *top, int s[]);

int main()
{
    int item, ch, top = -1, item_del, s[15];

    for (;;)
    {
        printf("choose\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("enter the item\n");
            scanf("%d", &item);
            push(&item, &top, s);
            break;

        case 2:
            item_del = pop(&top, s);
            if (item_del == -1)
            {
                printf("stack Underflow\n");
            }
            else
            {
                printf("%d", item_del);
            }
            break;

        case 3:
            display(&top, s);
            break;

        default:
            printf("enter the valid input");
            break;
        }
    }

    return 0;
}

void push(int *item, int *top, int s[])
{
    if (*top == SIZE - 1)
    {
        printf("stack Overflow");
        return;
        *top = *top + 1;
        s[*top] = *item;
    }
}
int pop(int *top, int s[])
{
    if (*top == -1)
    {
        return -1;
    }

    return s[*top--];
}
void display(int *top, int s[])
{
    if (*top == -1)
    {
        printf("stack Underflow\n");
    }

    for (int i = 0; i <= *top; i++)
    {
        printf("\n%d\t", s[i]);
    }
}