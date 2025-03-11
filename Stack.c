#include <stdio.h>
#include <stdio.h>

typedef struct {
    int* queue1;
    int* queue2;
    int front1;
    int rear1;
    int front2;
    int rear2;
    int size;

} MyStack;


MyStack* myStackCreate() {
    MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
    obj->queue1 = (int*)malloc(100 * sizeof(int));
    obj->queue2 = (int*)malloc(100 * sizeof(int));
    obj->front1 = obj->rear1 = 0;
    obj->front2 = obj->rear2 = 0;
    obj->size = 0;
    return obj;
}

void myStackPush(MyStack* obj, int x) {
    obj->queue1[obj->rear1++] = x;
    obj->size++;
}

int myStackPop(MyStack* obj) {
    if (obj->size == 0){
        printf("Underflow");
        return -1;
    }
    while (obj->front1 < obj->rear1){
        obj->queue2[obj->rear2++] = obj->queue1[obj->front1++];
    }
    int topElement = obj->queue1[obj->front1++];
    obj->size--;

    int* tempQueue = obj->queue1;
    obj->queue1 = obj->queue2;
    obj->queue2 = tempQueue;

    // Reset front and rear pointers for queue2
    obj->front1 = obj->rear1 = 0;
    obj->front2 = obj->rear2 = 0;

    return topElement;
}

int myStackTop(MyStack* obj) {
    if (obj->size == 0) {
        printf("Stack underflow\n");
        return -1; // Or some other error code
    }
    while (obj->front1 < obj->rear1 - 1) {
        obj->queue2[obj->rear2++] = obj->queue1[obj->front1++];
    }
    int topElement = obj->queue1[obj->front1];

    // Transfer the last element back to queue2
    obj->queue2[obj->rear2++] = obj->queue1[obj->front1++];

    // Swap queue1 and queue2
    int* tempQueue = obj->queue1;
    obj->queue1 = obj->queue2;
    obj->queue2 = tempQueue;

    // Reset front and rear pointers for queue2
    obj->front1 = obj->rear1 = 0;
    obj->front2 = obj->rear2 = 0;

    return topElement;
}

bool myStackEmpty(MyStack* obj) {
    return obj->size == 0;
}

void myStackFree(MyStack* obj) {
    free(obj->queue1);
    free(obj->queue2);
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/