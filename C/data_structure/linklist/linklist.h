#ifndef __LINKLIST_H__
#define __LINKLIST_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int datatype_t;

typedef struct node
{
    datatype_t data;
    struct node *next;
}linknode_t;


extern linknode_t *create_linklist();
extern void insert_head_linklist(linknode_t *head, datatype_t data);
extern void printf_data_linklist(linknode_t *head);

#endif