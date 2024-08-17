#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define MAX 2

struct student
{
    char name[20];
    int id;
    int age;
};

typedef struct student datatype_t;

typedef struct
{
    datatype_t buf[MAX];
    int n;
}seqlist_t;

seqlist_t *create_empty_seqlist()
{
    seqlist_t *l = NULL;
    l = malloc(sizeof(seqlist_t));
    if (NULL == l)
    {
        printf("malloc failed\n");
        return NULL;
    }
    memset(l, 0, sizeof(seqlist_t));
    l->n = 0;
    return l;
}

int is_full_seqlist(seqlist_t *l)
{
    return l->n == MAX ? 1 : 0;
}

void insert_data_seqlist(seqlist_t *l, datatype_t data)
{
    l->buf[l->n] = data;
    l->n += 1;
    return;
}

void print_data_seqlist(seqlist_t *l)
{
    int i = 0;

    for (i=0; i<l->n; i++)
    {
        printf("student name: %s\n", l->buf[i].name);
        printf("student id: %d\n", l->buf[i].id);
        printf("student age: %d\n", l->buf[i].age);
    }
    printf("\n");
    return;
}

int is_empty_seqlist(seqlist_t *l)
{
    if (l->n == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int delete_data_seqlist(seqlist_t *l, char *str)
{
    int res, i, j;

    res = is_empty_seqlist(l);

    if (res == 0)
    {
        printf("The seqlist is empty!\n");
        return 0;
    }

    i = 0;
    j = 0;

    for (i = 0; i < l->n; i++)
    {
        int temp;
        temp = strcmp(str, l->buf[i].name);
        if (temp != 0)
        {
            l->buf[j] = l->buf[i];
            j++;
        }
    }

    if ( i == j)
    {
        printf("The item does not exist\n");
        return 2;
    }

    printf("Delete successfully\n");
    return 1;
}

int main()
{
    seqlist_t *l = NULL;
    l = create_empty_seqlist();
    datatype_t data;
    printf("Please input %d data : ", MAX);

    while(!is_full_seqlist(l))
    {
        printf("Please input the name of the student: \n");
        scanf("%s", &(data.name));
        printf("Please input the id of the student: \n");
        scanf("%d", &(data.id));
        printf("Please input the age of the studnet: \n");
        scanf("%d", &(data.age));
        insert_data_seqlist(l,data);
    }

    print_data_seqlist(l);

    int temp = 0;

    temp = delete_data_seqlist(l, "Jack");

    free(l);
    l = NULL;
    return 0;
}




