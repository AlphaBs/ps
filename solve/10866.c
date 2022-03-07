#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* front;
    struct Node* back;
} Node;

typedef struct Deque {
    int size;
    struct Node* front;
    struct Node* back;
} Deque;

Deque* createDeque()
{
    Deque* d = (Deque*) malloc(sizeof(Deque));
    d->size = 0;
    d->front = NULL;
    d->back = NULL;
    return d;
}

Node* createNode(int data)
{
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->front = NULL;
    newNode->back = NULL;
    return newNode;
}

void pushFront(Deque* d, int data)
{
    Node* newNode = createNode(data);
    if (d->front == NULL)
    {
        d->front = newNode;
    }
    else
    {
        d->front->front = newNode;
        newNode->back = d->front;
        d->front = newNode;
    }

    if (d->back == NULL)
        d->back = newNode;

    d->size++;
}

void pushBack(Deque* d, int data)
{
    Node* newNode = createNode(data);
    if (d->back == NULL)
    {
        d->back = newNode;
    }
    else
    {
        d->back->back = newNode;
        newNode->front = d->back;
        d->back = newNode;
    }

    if (d->front == NULL)
        d->front = newNode;

    d->size++;
}

int popFront(Deque* d)
{
    if (d->size == 0)
        return -1;

    int data = d->front->data;

    Node* front = d->front;
    d->front = front->back;
    free(front);
    d->size--;

    if (d->size > 0)
        d->front->front = NULL;
    else if (d->size == 0)
        d->back = NULL;

    return data;
}

int popBack(Deque* d)
{
    if (d->size == 0)
        return -1;

    int data = d->back->data;

    Node* back = d->back;
    d->back = back->front;
    free(back);
    d->size--;

    if (d->size > 0)
        d->back->back = NULL;
    else if (d->size == 0)
        d->front = NULL;

    return data;
}

int peekFront(Deque* d)
{
    if (d->size == 0)
        return -1;
    return d->front->data;
}

int peekBack(Deque* d)
{
    if (d->size == 0)
        return -1;
    return d->back->data;
}

void destroyDeque(Deque* d)
{
    if (d == NULL)
        return;
    
    if (d->size > 0)
    {
        while (d->size)
        {
            popFront(d);
        }
    }

    free(d);
}

int main()
{
    int n;
    scanf("%d", &n);

    int temp;
    Deque* d = createDeque();
    char buffer[16];
    while (n--)
    {
        scanf("%s", buffer);

        if (strcmp(buffer, "push_front") == 0)
        {
            scanf("%d", &temp);
            pushFront(d, temp);
        }
        else if (strcmp(buffer, "push_back") == 0)
        {
            scanf("%d", &temp);
            pushBack(d, temp);
        }
        else if (strcmp(buffer, "pop_front") == 0)
        {
            printf("%d\n", popFront(d));
        }
        else if (strcmp(buffer, "pop_back") == 0)
        {
            printf("%d\n", popBack(d));
        }
        else if (strcmp(buffer, "size") == 0)
        {
            printf("%d\n", d->size);
        }
        else if (strcmp(buffer, "empty") == 0)
        {
            printf("%d\n", d->size == 0 ? 1 : 0);
        }
        else if (strcmp(buffer, "front") == 0)
        {
            printf("%d\n", peekFront(d));
        }
        else if (strcmp(buffer, "back") == 0)
        {
            printf("%d\n", peekBack(d));
        }
        else
        {
            printf("no\n");
        }
    }

    return 0;
}