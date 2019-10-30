#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int val;
	struct node *next;
};

struct node * detectLoop(struct node *head)
{
	struct node *fast = head, *slow = head;
	do
	{
		if (fast == NULL || fast->next == NULL)
		{
			return NULL;
		}
		fast = fast->next->next;
		slow = slow->next;
	} while (fast != slow);
	return fast;
}

struct node *loopStart(struct node *head, struct node *meetingPoint)
{
	while (head != meetingPoint)
	{
		head = head->next;
		meetingPoint = meetingPoint->next;
	}
	return head;
}

int main()
{
	struct node *head = NULL, *newNode = NULL, *temp = NULL, *start = NULL;
	int nodeCount, val;
	printf("enter no.of nodes: ");
	scanf("%d", &nodeCount);
	printf("enter values: ");
	for (int i = 0; i < nodeCount; i++)
	{
		scanf("%d", &val);
		newNode = (struct node *)malloc(sizeof(struct node));
		newNode->val = val;
		newNode->next = NULL;
		if (head == NULL)
		{
			head = newNode;
			temp = newNode;
		}
		else
		{
			temp->next = newNode;
			temp = temp->next;
		}
		if (i == 3)
		{
			start = newNode;
		}
	}
	temp->next = start;
	temp = detectLoop(head);
	if (head == NULL)
	{
		printf("no loop\n");
	}
	else
	{
		printf("meeting point is at %d\n", temp->val);
		printf("loop start is at %d\n", loopStart(head, temp)->val);
	}
	system("pause");
	return 0;
}