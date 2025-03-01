#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Node{
    struct Node* next;
    char character;
}Node;
typedef struct Stack{
    Node* top;
}Stack;
Node *ft_create_elem(char data)
{
	Node* new_node;
	
	new_node = (Node*)malloc(sizeof(Node));
	if(new_node)
	{
		new_node->character = data;
		new_node->next = NULL;
	}
	return (new_node);
}
bool isValid(char *s) {
    Stack* stack;
    stack = malloc(sizeof(Stack));
    stack->top = NULL;

    

    int i = 0;
    while (s[i] != '\0')
    {
            char current = s[i];
        if(s[i] == '[' || s[i] == '{' || s[i] == '(')
        {
        Node* new_node = ft_create_elem(current);
        new_node->next = stack->top;
        stack->top = new_node; 
        }else {
            char top_char = stack->top->character;
            if((current == ']' && top_char == '[') ||
            (current == '}' && top_char == '{') || 
            (current == ')' && top_char == '('))
            {
                Node*temp = stack->top;
                stack->top = stack->top->next;
                free(temp);
            }else{
                free(stack);
                return false;
            }
        }
        i++;
    } 
    bool isValid = (stack->top == NULL);
    free(stack);
    return isValid;
}

int main ()
{
    char s[] = "([])";
    
    int boo = isValid(s);
    printf("%d", boo);
   
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    struct Node* next;
    char character;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

Node* ft_create_elem(char data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node) {
        new_node->character = data;
        new_node->next = NULL;
    }
    return new_node;
}

bool isValid(char* s) {
    Stack* stack = malloc(sizeof(Stack));
    stack->top = NULL;

    for (int i = 0; s[i] != '\0'; i++) {
        char current = s[i];
        
        // Push opening brackets onto the stack
        if (current == '(' || current == '{' || current == '[') {
            Node* new_node = ft_create_elem(current);
            new_node->next = stack->top;
            stack->top = new_node;
        } 
        // Check for closing brackets
        else {
            if (stack->top == NULL) {
                // Stack is empty, but found a closing bracket
                free(stack);
                return false;
            }
            char top_char = stack->top->character;

            // Check if the top of the stack matches the closing bracket
            if ((current == ')' && top_char == '(') ||
                (current == '}' && top_char == '{') ||
                (current == ']' && top_char == '[')) {
                // Pop the stack
                Node* temp = stack->top;
                stack->top = stack->top->next;
                free(temp);
            } else {
                // Mismatched closing bracket
                free(stack);
                return false;
            }
        }
    }

    // If stack is empty, all brackets matched
    bool isValid = (stack->top == NULL);
    free(stack);
    return isValid;
}

int main() {
    char s[] = "([])";
    bool boo = isValid(s);
    printf("%d\n", boo);  // Should print 1 for true

    return 0;
}
