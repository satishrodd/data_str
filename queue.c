/*---------------------------------------------------------------------------
 * 
 * queue.c 
 *
 *     06/08/2019 - 
 *
 *---------------------------------------------------------------------------
 */
#include<stdio.h>

#define SIZE 100

typedef struct queue_s {
    void  *arr[SIZE];
    int front, tail;
} queue_t;

typedef struct stack_s {
    void *arr[SIZE];
    int top;
}stack_t;
void 
push(stack_t *s, void *node) {
    if(s->top>SIZE) {
        printf("\nStack Full");
        return;
    }
    s->arr[s->top] = node;
    s->top++;
    return;
}
void *
pop(stack_t *s) {
    if(!s->top){
        printf("\nStack empty");
        return;
    }
    s->top--;
    return s->arr[s->top];
}
void
stack_init(stack_t *s) {
    s->top = 0;
}

void
enqueue(queue_t *q, void * node) {
    q->front = (q->front+1) % SIZE;
    q->arr[q->front] = node;
}

void *
dequeue(queue_t *q) {
    if (q->tail > q->front ) {
        printf("\nQueue empty");
        return NULL;
    }
    void *tmp = q->arr[q->tail];
    q->tail = (q->tail+1)%SIZE;
    return tmp;
}

void
queue_init(queue_t *q) {
    q->front = -1;
    q->tail  = 0;
}

void main() {
    int a[10] = {1,3,2,4,5,6,7,100,200,1000};
    int i;
    int *x;
    queue_t q;
    stack_t s;
    queue_init(&q);
    stack_init(&s);
    for (i=0;i<10;i++) {
        enqueue(&q, &a[i]);
        push(&s, &a[i]);
    }
    for (i=0;i<10;i++) {
        x =(int*)dequeue(&q);
        if (!x) break;
        printf(" %d", *x);
    }
    printf("\n");
    for (i=0;i<10;i++) {
        x = (int*)pop(&s);
        if (!x) break;
        printf(" %d", *x);
    }
    printf("\n");
    return;

}
