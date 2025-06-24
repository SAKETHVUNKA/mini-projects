#include "dll.h"
#include <stdio.h>
#include <stdlib.h>

list_t *create_list() // return a newly created empty doubly linked list
{
    // DO NOT MODIFY!!!
    list_t *l = (list_t *)malloc(sizeof(list_t));
    l->head = NULL;
    l->tail = NULL;
    l->size = 0;
    return l;
}

void insert_front(list_t *list, int data) // TODO: inserts data to the beginning of the linked list
{
    if (list->head == NULL)
    {
        node_t *temp = malloc(sizeof(node_t));
        temp->next = NULL;
        temp->prev = NULL;
        temp->data = data;
        list->head = temp;
        list->tail = temp;
    }
    else
    {
        node_t *temp = malloc(sizeof(node_t));
        temp->next = NULL;
        temp->prev = NULL;
        temp->data = data;
        temp->next = list->head;
        temp->next->prev = temp;
        list->head = temp;
    }
    list->size += 1;
}

void insert_back(list_t *list, int data) // TODO: inserts data to the end of the linked list
{
    if (list->head == NULL)
    {
        node_t *temp = malloc(sizeof(node_t));
        temp->next = NULL;
        temp->prev = NULL;
        temp->data = data;
        list->head = temp;
        list->tail = temp;
    }
    else
    {
        node_t *temp = malloc(sizeof(node_t));
        temp->next = NULL;
        temp->prev = NULL;
        temp->data = data;
        temp->prev = list->tail;
        temp->prev->next = temp;
        list->tail = temp;
    }
    list->size += 1;
}

void insert_after(list_t *list, int data, int prev) // TODO: inserts data after the node with data “prev”. Do not insert or do anything if prev doesn't exist
{
    node_t *temp = list->head;
    if (temp == NULL)
    {
        return;
    }
    else
    {
        while ((temp != NULL) && (temp->data != prev))
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            return;
        }
        else if (temp->data == prev)
        {
            node_t *new = (node_t *)malloc(sizeof(node_t));
            new->data = data;
            new->next = temp->next;
            new->prev = temp;
            if (temp->next != NULL)
                temp->next->prev = new;
            temp->next = new;
            list->size += 1;
        }
    }
}

void delete_front(list_t *list) // TODO: delete the start node from the linked list.
{
    if (list->head != NULL)
    {
        node_t *temp;
        if (list->head == list->tail)
            list->tail = NULL;
        temp = list->head;
        if (list->head->next == NULL)
        {
            list->head = NULL;
        }
        else
        {
            list->head = list->head->next;
        }
        free(temp);
        temp = NULL;
        if (list->head != NULL)
        {
            list->head->prev = NULL;
        }
        list->size -= 1;
    }
}

void delete_back(list_t *list) // TODO: delete the end node from the linked list.
{
    if (list->tail != NULL)
    {
        node_t *temp;
        if (list->head == list->tail)
            list->head = NULL;
        temp = list->tail;
        if (list->tail->prev != NULL)
        {
            list->tail = list->tail->prev;
        }
        else
        {
            list->tail = NULL;
        }
        free(temp);
        temp = NULL;
        if (list->tail != NULL)
            list->tail->next = NULL;
        list->size -= 1;
    }
}

void delete_node(list_t *list, int data) // TODO: delete the node with “data” from the linked list.
{
    node_t *temp;
    temp = list->head;
    while ((temp != NULL) && (temp->data != data))
    {
        temp = temp->next;
    }
    if (temp != NULL)
    {
        if (temp == list->head)
        {
            delete_front(list);
        }
        else if (temp == list->tail)
        {
            delete_back(list);
        }
        else
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp);
            temp = NULL;
            list->size -= 1;
        }
    }
}

node_t *search(list_t *list, int data) // TODO: returns the pointer to the node with “data” field. Return NULL if not found.
{
    node_t *temp = NULL;
    temp = list->head;
    while ((temp != NULL) && (temp->data != data))
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        return NULL;
    }
    else if (temp->data == data)
    {
        return temp;
    }
    else
    {
        return NULL;
    }
}

int is_empty(list_t *list) // return true or 1 if the list is empty; else returns false or 0
{
    // DO NOT MODIFY!!!
    return list->size == 0;
}

int size(list_t *list) // returns the number of nodes in the linked list.
{
    // DO NOT MODIFY!!!
    return list->size;
}

void delete_nodes(node_t *head) // helper
{
    // DO NOT MODIFY!!!
    if (head == NULL)
        return;
    delete_nodes(head->next);
    free(head);
}

void delete_list(list_t *list) // free all the contents of the linked list
{
    // DO NOT MODIFY!!!
    delete_nodes(list->head);
    free(list);
}

void display_list(list_t *list) // print the linked list by separating each item by a space and a new line at the end of the linked list.
{
    // DO NOT MODIFY!!!
    node_t *it = list->head;
    while (it != NULL)
    {
        printf("%d ", it->data);
        it = it->next;
    }
    printf("\n");
}