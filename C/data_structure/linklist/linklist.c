#include "linklist.h"

linknode_t *create_linklist()
{
    linknode_t *head = NULL;
    head = malloc(sizeof(linknode_t));
    if (NULL == head)
    {
        printf("Malloc fail!");
    }
    memset(head, 0, sizeof(linknode_t));
    return head;
}

// 头插法
void insert_head_linklist(linknode_t *head, datatype_t data)
{
    // create an temporary linklist node
    linknode_t *temp = NULL;
    temp = create_linklist();
    if (NULL == temp)
    {
        return;
    }

    temp->data = data;
    temp->next = head->next;
    head->next = temp;

    return;
}

// print link list
void printf_data_linklist(linknode_t *head)
{
    linknode_t *p = head;
    while(p->next != NULL)
    {
        printf("%d ", p->next->data);
        printf("\n");
        p = p->next;
    }
    return;
}

int main()
{
    linknode_t * head = NULL;
    head = create_linklist();
    int n = 0;
    int i = 0;
    datatype_t data;

    printf("Please input the data number:\n");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Please input the link node data:\n");
        scanf("%d", &data);
        insert_head_linklist(head, data);
    }

    printf_data_linklist(head);

    return 0;
}