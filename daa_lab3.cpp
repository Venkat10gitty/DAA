#include <iostream>
using namespace std;
 
struct stack {
    int data;
    struct stack* next;
};
void initStack(struct stack** s) { *s = NULL; }
 
int isEmpty(struct stack* s)
{
    if (s == NULL)
        return 1;
    return 0;
}
void push(struct stack** s, int x)
{
    struct stack* p = (struct stack*)malloc(sizeof(*p));
 
    if (p == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
 
    p->data = x;
    p->next = *s;
    *s = p;
}
int pop(struct stack** s)
{
    int x;
    struct stack* temp;
 
    x = (*s)->data;
    temp = *s;
    (*s) = (*s)->next;
    free(temp);
 
    return x;
}
 
int top(struct stack* s) { return (s->data); }
 
void sortedInsert(struct stack** s, int x)
{
    if (isEmpty(*s) or x > top(*s)) {
        push(s, x);
        return;
    }
    int temp = pop(s);
    sortedInsert(s, x);
    push(s, temp);
}

void sortStack(struct stack** s)
{
    if (!isEmpty(*s)) {
        int x = pop(s);
        sortStack(s);
        sortedInsert(s, x);
    }
}
void insertAtBottom(struct stack** s, int item) {  
    if (isEmpty(*s)) {  
        push(s, item);  
    } else {  
       int top = pop(s);  
        insertAtBottom(s, item);  
        push(s, top);  
    }  
} 
void reverse(struct stack** s) {  
    if (!isEmpty(*s)) {  
         int top = pop(s);  
        reverse(s);  
        insertAtBottom(s, top);  
    }  
} 
void printStack(struct stack* s)
{
    while (s) {
        cout << s->data << " ";
        s = s->next;
    }
    cout << "\n";
}
int main(void)
{
    int size;
    cin>>size;
    struct stack* top;
 
    initStack(&top);
    
    for(int i=0; i<size; i++){
        int k;
        cin>>k;
        push(&top, k);
    }
    sortStack(&top);
    reverse(&top);
    cout << "Stack elements after sorting:\n";
    printStack(top);
    return 0;
}