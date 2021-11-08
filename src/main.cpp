//extern "C" 
#include <stdio.h>		/* scanf, printf */
#include <stdlib.h>		/* abort */
#include <stdbool.h>	/* bool, true, false */
#include "dfs.h"
    // Add the header files required to run your main 


// File for sandboxing and trying out code
int main(int argc, char** argv) {

    node* root = make_node(4,
        make_node(7,
            make_node(28,
                make_node(77,
                    NULL,
                    NULL),
                make_node(23,
                    NULL,
                    NULL)),
            make_node(86,
                make_node(3,
                    NULL,
                    NULL),
                make_node(9,
                    NULL,
                    NULL))),
        make_node(98,
            NULL,
            NULL));
    // Print Tree
    int s = 0;
	printf("enter number to search for:\n");
	scanf("%d", &s);
    printf("_________\n");
	struct stack* stack =(struct stack*) malloc(sizeof(struct stack));
	stack->node = root;
    stack->next = NULL;

    if (DFS(stack, s))
        printf("true");
    else 
        printf("false");
    
    return 0;
}