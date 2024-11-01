#ifndef STACK_H
#define STACK_H

typedef char infotype;
const int IDMAX = 15;

struct Stack {
    infotype info[IDMAX];
    int Top;
};

// Deklarasi Fungsi
void createStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);

#endif
