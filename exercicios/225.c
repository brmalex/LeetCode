typedef struct head{
    struct stack * next;
} MyStack;

typedef struct stack{
    int val;
    struct node * next;
} Stack;

MyStack* myStackCreate() {
    MyStack * temp = (MyStack *) malloc (sizeof(MyStack));
    temp->next = NULL;
    return temp;
}

void myStackPush(MyStack* obj, int x) {
    Stack * temp = (Stack *) malloc (sizeof(Stack));
    temp->next = obj->next;
    temp->val = x;
    obj->next = temp;
}

int myStackPop(MyStack* obj) {
    Stack * temp = obj->next->next;
    int x = obj->next->val;
    free(obj->next);
    obj->next = temp;
    return x;
}

int myStackTop(MyStack* obj) {
    return obj->next->val;
}

bool myStackEmpty(MyStack* obj) {
    if(obj->next == NULL){
        return true;
    }
    else{
        return false;
    }
}

void myStackFree(MyStack* obj) {
    if(obj->next != NULL){
        stackFree(obj->next);
    }
    free(obj);
}

void stackFree(Stack* obj){
    if(obj->next != NULL){
        stackFree(obj->next);
    }
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
