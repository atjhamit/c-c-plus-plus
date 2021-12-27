// queue with fixed length and
// start of with defining the APIs  - enqueue etc
// it should be able to take data of any type - not templates
// mixed type of componenets
// simple in terms of memory management

// int, string, struct?? - anything

// skeleton code should do

#include <stdio.h>

#define INPUTS 10

void *arr[INPUTS];
int lenVar = 0;

typedef struct node
{
    void *ele;
    struct node *next;
} node;

node *head = NULL, *tail = NULL;

node *temp_store = 0;

bool isFull()
{
    if (lenVar == INPUTS)
        return true;
    return false;
}

bool isEmpty()
{
    if (!lenVar)
        return true;
    return false;
}

bool enqueue(void *arg)
{
    if (isFull())
    {
        printf("Queue Full. Please dequeue\n");
        return false;
    }

    lenVar++;
    node *newEle = malloc(sizeof(arg));
    newEle->ele = arg;
    newEle->next = 0;
    if (isEmpty())
        head = tail = newEle;
    else
    {
        tail->next = newEle;
        tail = newEle;
    }

    return true;
}

bool dequeue(void **arg)
{
    if (isEmpty())
    {
        printf("Queue Empty. Please enqueue first.\n");
        return false;
    }
    *(*arg) = **(head->ele); // copy the value from head-ele to arg deferenced and then deallocate

    node *temp = head->next;
    free(head); // deallocate
    head = temp;
    --lenVar;
    return true;
}

int getLength()
{
    return lenVar;
}

int main()
{
    int intVar = 5;
    char charVar = 'a';
}