#include <stdio.h>
typedef struct node_s
{
    int val;
    struct queue_s* next;
}Node;
typedef struct Queue
{
    Node *front;
    Node *rear;
}Queue;
void ft_queue(int *arr, int size)
{

    int front = -1 ;//implying that the array is empty!
    int  rear = - 1;
        int new_el = 6;
    if (!arr[0])
    {
        rear++;
    arr[rear] = new_el;

    }

}
int main ()
{
    int arr[];
    int size = 5;
}