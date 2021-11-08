/*
* Search an expression using DFS.
*/

#include <stdio.h>		/* scanf, printf */
#include <stdlib.h>		/* abort */
#include <stdbool.h>	/* bool, true, false */
#include "dfs.h"

// precondition stack har stack->node = root og stack->next = NULL (se eventuelt main for at se input)
bool DFS(stack* top, int s) {

	struct stack* temp = (struct stack*)malloc(sizeof(struct stack));
	if (top == NULL) {
		return false; // returner false når stack'en er tom
	}
	else {
		temp->next = top->next;
		temp->node = top->node;
	}

	pop(&top); //fjerner øverste element på stack: top
	print_node(temp->node); // printer rækkefølgen træet bliver tjekket i
	printf("\n");

	// pusher nodes i form af typedef stacks, hvis der er nogle
	if (temp->node->rchild != NULL) {
		(push(&top, temp->node->rchild));
	}
	if (temp->node->lchild != NULL) {
		push(&top, temp->node->lchild);
	}

	// tjekker search og returner enten true eller returner DFS, men en længere nede i stacken.
	if (temp != NULL) {
		if (temp->node->num == s) {
			return true;
		}
		else
			return DFS(top, s);
	}

}

node* make_node(int num, node* left, node* right)
{
	node* new_node = malloc(sizeof(node));
	if (left != NULL)
		new_node->lchild = left;
	else
		new_node->lchild = NULL;

	if (right != NULL)
		new_node->rchild = right;
	else
		new_node->rchild = NULL;

	new_node->num = num;

	new_node->visited = false;

	return new_node;
}

void free_node(node* p)
{

}


void print_node(node* p)
{
	if (p == NULL)
		printf("NULL\n");
	else
		printf("%d", p->num);
}


void print_tree(node* p, int depth)
{
	for (int i = 0; i < depth; i = i + 1)
		printf(" ");
	printf("| ");

	if (p == NULL)
		printf("NULL\n");
	else
		printf("[%d]\n", p->num);


	if (p->lchild)
	{
		print_tree(p->lchild, depth + 1);
	}

	if (p->rchild)
		print_tree(p->rchild, depth + 1);
}

void push(stack** topp, node* node)
{
	struct stack* tmp = (struct stack*)malloc(sizeof(struct stack));
	if (*topp != NULL) {
		tmp->node = node;
		tmp->next = *topp;
		*topp = tmp;
	}
	else {
		tmp->node = node;
		tmp->next = NULL;
		*topp = tmp;
	}

	return;
}

bool isEmpty(struct stack* topp)
{
	return 0;
}

node* top(struct stack* topp)
{
	return 0;
}

// Utility function to pop topp  
// element from the stack 

void pop(stack** topp)
{
	if (*topp != NULL) {
		struct stack* tmp = (struct stack*)malloc(sizeof(struct stack));
		tmp->node = (*topp)->node; // bliver nød til at assigne værdierne en efter en eller er det bare den samme pointer
		tmp->next = (*topp)->next;
		*topp = (*topp)->next;
		free(tmp); // free den stack der bliver poppet
	}

	return;
}

void print_stack(stack* topp)
{
	struct stack* temp = topp;

	while (temp != NULL)
	{

		print_node(temp->node);
		printf("\n");

		temp = temp->next;
	}

	printf("====\n");

	return;
}
