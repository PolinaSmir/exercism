#include "linked_list.h"
#include <stdlib.h>

struct list_node {
   struct list_node *prev, *next;
   ll_data_t data;
};

struct list {
   struct list_node *first, *last;
};

struct list *list_create(void) {
    // Create node
    // struct list_node* newNode = (struct list_node*)malloc(sizeof(struct list_node));
    // newNode->prev = NULL;
    // newNode->next = NULL;
    // Create list and attach newNode
    struct list* newList = (struct list*)malloc(sizeof(struct list));
    newList->first = NULL;
    newList->last = NULL;
    return newList;
}

void list_destroy(struct list *list) {
    struct list_node* tmpFirst = list->first;
    // struct list_node* tmpLast = list->last;
    while(tmpFirst) {
        struct list_node* tmpNext = tmpFirst->next;
        free(tmpFirst);
        tmpFirst = tmpNext;
    }
    list->first = NULL;
    list->last = NULL;
}

// inserts item at back of a list
void list_push(struct list *list, ll_data_t item_data) {
    // Grab last one, 
    struct list_node *tmpLastNewPrev = list->last;
    
    // Create new node
    struct list_node *newNode = (struct list_node*)malloc(sizeof(struct list_node));
    newNode->data = item_data;
    if(!tmpLastNewPrev) {
        newNode->prev = NULL;
        list->first = newNode;
    } else {
        newNode->prev = tmpLastNewPrev;
        tmpLastNewPrev->next = newNode;
    }
    newNode->next = NULL;
    list->last = newNode;   
}

ll_data_t list_pop(struct list *list) {
    struct list_node *tmpLastNewPrev = list->last;
    ll_data_t getData = tmpLastNewPrev->data;
    list->last = tmpLastNewPrev->prev;
    if(tmpLastNewPrev == list->first) {
        list->first = NULL;
        list->last = NULL;
    }
    if(list->last) {
        list->last->next = NULL;
    }
    free(tmpLastNewPrev);
    return getData;
}

// removes item from front of a list
ll_data_t list_shift(struct list *list) {
    struct list_node *tmpFirst = list->first;
    ll_data_t getData = tmpFirst->data;
    list->first = tmpFirst->next;
    if(tmpFirst == list->last) {
        list->first = NULL;
        list->last = NULL;
    }
    if(list->first) {
        list->first->prev = NULL;
    }
    free(tmpFirst);
    return getData;
}

// inserts item at front of a list
void list_unshift(struct list *list, ll_data_t item_data) {
    // Create New Node
    struct list_node *newNode = (struct list_node*)malloc(sizeof(struct list_node));
    newNode->data = item_data;
    // Grab current first
    struct list_node *tmpFirst = list->first;
    if(!tmpFirst) {
        newNode->next = NULL;
        list->last = newNode;
    } else {
        newNode->next = tmpFirst;
        tmpFirst->prev = newNode;
    }
    newNode->prev = NULL;
    list->first = newNode;
    
}

size_t list_count(const struct list *list) {
    // Count from first
    struct list_node *current = list->first;
    size_t counter = 0;
    while(current) {
        counter++;
        struct list_node *next = current->next;
        current = next;
    }
    return counter;
}

// deletes a node that holds the matching data
void list_delete(struct list *list, ll_data_t data) {
    struct list_node *current = list->first;
    while(current) {
        if(current->data == data) {
            struct list_node *tmpA = current->prev;
            struct list_node *tmpC = current->next;
            if(current == list->first && current == list->last) {
                list->first = NULL;
                list->last = NULL;
                free(current);
                break;
            } else if(current == list->first) {
                list->first = current->next;
                current->next->prev = NULL;
            } else if(current == list->last) {
                list->last = current->prev;
                current->prev->next = NULL;
            } else {
                tmpA->next = tmpC;
                tmpC->prev = tmpA;
            }
            free(current);
            break;
        }
        struct list_node *next = current->next;
        current = next;
    }
}


