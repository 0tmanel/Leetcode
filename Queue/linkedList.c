#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node* next;
    int val;
} Node;

typedef struct Queue {
    Node* first; // Pointer to the first node
    Node* rear;  // Pointer to the last node
} Queue;
void initQueue(Queue* queue, int value)
{
    queue->first = malloc (sizeof(Node));
     queue->rear = malloc (sizeof(Node));
    Node* new_node = malloc(sizeof(Node));
    if(new_node == NULL)
    {
        return;
    }
    new_node->val = value;
    if(queue == NULL)
    {
        queue->first = new_node;
        queue->rear = new_node;
    }else{
        queue->rear->next = new_node;
        queue->rear = new_node;
    }
    printf("%d", queue->rear->val);
    if(queue->rear->val == 5)
    {
        Node*temp = queue->rear;
        free(temp);
    }
}
int main ()
{
    Queue* node = malloc(sizeof(Queue));

     node->first = NULL;//THE QUEUE IS EMPTY
     node->rear = NULL;

     int i = 0;
     while (i <= 5)
     {
        initQueue(node, i);
        i++;
     }

     Node*current = node->first;
     while (current != NULL)
     {
        Node*temp = current;
        current = current->next;
        free(temp);
     }
     free(node);
}

