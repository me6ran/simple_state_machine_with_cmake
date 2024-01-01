#ifndef MATH_OPERATIONS_H
#define MATH_OPERATIONS_H

typedef enum 
{ 
    ADD,
    SUB,
    DIVIDE,
    /* data */
} operation_state_t;

int add(int, int);
int sub(int, int);

int add(int a, int b)
{
    return a+b;
}

int sub(int a, int b)
{
    return a-b;
}

#endif /* MATH_OPERATIONS_H */