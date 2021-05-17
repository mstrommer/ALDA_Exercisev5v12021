//
//  pqueue.c
//  PQueue
//
//  Created by Michael Strommer on 29.04.21.
//  Copyright © 2021 Michael Strommer. All rights reserved.
//

#include "pqueue.hpp"
#include <stdlib.h>

// Erstellt Speicher für Queue und liefert Adresse zurück.
pqueue *p_init(){
    pqueue *tmp = (pqueue *)malloc(sizeof(pqueue));
    tmp->head = NULL;
    tmp->count = 0;
    return tmp;
}

/*
 Comments:
 */
void p_enqueue(pqueue *queue, const char *data, int priority){
    // TODO
}

/*
 Comments:
*/
element *p_peek(pqueue *queue){
    // TODO
    return NULL;
}

/*
 Comments:
*/
void p_dequeue(pqueue *queue){
    // TODO
}

/*
 Comments:
*/
void p_incrementPriority(pqueue *queue, const char *data, int priority){
    // TODO
}

/*
 Comments:
*/
int p_isEmpty(pqueue *queue){
    // TODO
    return -1;
}

/*
 Comments:
*/
void p_print(pqueue *queue){
    // TODO
}
