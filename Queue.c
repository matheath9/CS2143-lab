#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* stack1;
    int* stack2;
    int top1;
    int top2;
    int size;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    obj->stack1 = (int*)malloc(100*sizeof(int));
    obj->stack2 = (int*)malloc(100*sizeof(int));
    obj->top1 = -1;
    obj->top2 = -1
    obj->size = 0;
    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->stack1[++obj->top1] = x;
    obj->size++;
}

int myQueuePop(MyQueue* obj) {
    if (obj->top2==-1){
        while(obj->top1!=-1){
            obj->stack2[++obj->top2] = obj->stack1[obj->top1--];
        }
    }
    obj->size--;
    return obj->stack2[obj->top2--];
}

int myQueuePeek(MyQueue* obj) {
    if (obj->top2==-1){
        while (obj->top1!=-1){
            obj->stack2[++obj->top2] = obj->stack1[obj->top1--];
        }
    }
    return obj->stack2[obj->top2];
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->size=0;
}

void myQueueFree(MyQueue* obj) {
    free (obj->stack1);
    free (obj->stack2);
    free (obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/








