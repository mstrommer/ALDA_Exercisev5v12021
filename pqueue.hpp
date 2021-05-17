//
//  pqueue.h
//  PQueue
//
//  Created by Michael Strommer on 29.04.21.
//  Copyright © 2021 Michael Strommer. All rights reserved.
//
#ifndef pqueue_h
#define pqueue_h

#include <stdio.h>
struct _element {
    char data[100];
    int priority;
    struct _element *next;
};

typedef struct _element element;

struct _pqueue {
    struct _element *head; // Erstes Element in der Queue
    int count; // Anzahl der Elemente in der Queue
};

typedef struct _pqueue pqueue;

pqueue *p_init(void);
void p_enqueue(pqueue *queue, const char *data, int priority);
element *p_peek(pqueue *queue);
void p_dequeue(pqueue *queue);
void p_incrementPriority(pqueue *queue, const char *data, int priority);
int p_isEmpty(pqueue *queue);
void p_print(pqueue *queue);

#endif /* pqueue_h */
