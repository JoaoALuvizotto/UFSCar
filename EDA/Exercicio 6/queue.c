#include <stdlib.h>
#include "queue.h"

void initialize(queue *q) {
    q->first = NULL;
    q->last = NULL;
}

void destroy(queue *q) {
    while(!empty(q))
        pop(q);
}

void* front(queue *q) {
    if(!empty(q))
        return q->first->data;
    return 0;
}

void push(queue *q, void* data) {
    
    qnode *newNode = (qnode*) malloc (sizeof(qnode));
    newNode->data = data;
    newNode->next = NULL;

    if (empty(q)) {
        q->first = newNode;
        q->last = newNode;
    }
    else {
        q->last->next = newNode;
        q->last = newNode;
    }
}

void pop(queue *q) {
    
    if (empty(q))
    {
        return;
    }
    
    if (q->first == q->last)
    {
        free(q->first);
        q->first = NULL;
        q->last = NULL;
    }
    else
    {
        qnode *temp = q->first;
        q->first = q->first->next;
        free(temp);
    }
    

}

int empty(queue *q) {
    return q->first == 0;
}