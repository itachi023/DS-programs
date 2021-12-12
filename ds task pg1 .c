#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};
typedef struct node *NODE;

NODE getnode()
{
    NODE x;
    x = (NODE)malloc(sizeof(struct node));
    if (x == NULL)
    {
        printf("Out of memory\n");
        exit(0);
    }
    return x;
}

NODE insert_front(int item, NODE first)
{
    NODE temp;
    temp = getnode();
    temp->info = item;
    temp->link = first;
    return temp;
}

void display(NODE first)
{
    NODE cur;
    if (first == NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("The contents of singly linked list\n");
    cur = first;
    while (cur != NULL)
    {
        printf("%d   ", cur->info);
        cur = cur->link;
    }
    printf("\n");
}

NODE delete_front(NODE first)
{
    NODE temp;
    if (first == NULL)
    {
        printf("List is empty cannot delete\n");
        return NULL;
    }
    temp = first;
    temp = temp->link;
    printf("Item deleted = %d\n", first->info);
    free(first);
    return temp;
}

NODE insert_rear(int item, NODE first)
{
    NODE temp;
    NODE cur;
    temp = getnode();
    temp->info = item;
    temp->link = NULL;
    if (first == NULL)
        return temp;
    cur = first;
    while (cur->link != NULL)
    {
        cur = cur->link;
    }
    cur->link = temp;
    return first;
}

NODE delete_rear(NODE first)
{
    NODE cur, prev;
    if (first == NULL)
    {
        printf("List is empty cannot delete\n");
        return first;
    }
    if (first->link == NULL)
    {
        printf("The item to deleted is % d\n", first->info);
        free(first);
        return NULL;
    }
    prev = NULL;
    cur = first;
    while (cur->link != NULL)
    {
        prev = cur;
        cur = cur->link;
    }
    printf("The item deleted is % d\n", cur->info);
    free(cur);
    prev->link = NULL;
    return first;
}
NODE reverse(NODE first)
{
    NODE cur, temp;
    cur = NULL;
    while (first != NULL)
    {
        temp = first->link;
        first->link = cur;
        cur = first;
        first = temp;
    }
    return cur;
}
void main()
{
    NODE first;
    int choice, item;
    first = NULL;
    for (;;)
    {
        printf("1:Insert at Front\n2:Insert at rear\n");
        printf("3:Delete from Front\n4:Delete from rear\n");
        printf("5:Display\n6:reverse current list\n7:Exit\n");
        printf("Enter the choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the item to be inserted\n");
            scanf("%d", &item);
            first = insert_front(item, first);
            break;
        case 2:
            printf("Enter the item to be inserted\n");
            scanf("%d", &item);
            first = insert_rear(item, first);
            break;
        case 3:
            first = delete_front(first);
            break;
        case 4:
            first = delete_rear(first);
            break;
        case 5:
            display(first);
            break;
        case 6:
            first = reverse(first);
            break;
        default:
            exit(0);
        }
    }
}
