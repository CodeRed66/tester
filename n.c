#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct node *start;
struct node *temp;
struct node *current;
struct node *previous;
//struct node *nextnode;
//struct node *element;


void deleteBeginning()
{

	if(start==NULL)
	{
		printf("It is empty");
	}
	else
	{
		temp=start;
		start=start->next;
		free(temp);
		
	}
}

void deleteFromEnd()
{
	temp=start;
	while(temp->next!=0)
	{
		previous=temp;
		temp=temp->next;
	}
	if(temp==start)
	{
		start=0;
		free(temp);
	}
	else
	{
		previous->next=0;
	}
	free(temp);
}

void deleteElement(int element)
{
	if(start==NULL)
	{
		printf("List is empty\n");
	}
	else if(start->data==element)
	{
		temp=start;
		start=start->next;
		free(temp);
	}
	else
	{
		current=start->next;
		previous=start;
	while(current!=NULL && current->data!=element)
	{
		previous=current;
		current=current->next;
	}
	if(current==NULL)
	{
		printf("Element not found");
	}
	else
	{
		temp=current;
		previous->next=current->next;
		free(temp);
	}
	}
}
void deleteBefore(int element)
{
	if(start==NULL)
	{
		printf("List is empty\n");
	}
	else if(start->data==element)
	{
		printf("No element found before the first element\n");
	}
	else if(start->next->data==element)
	{
		temp=start;
		start=start->next;
		free(temp);
	}
	else
	{
		current=start->next;
		previous=start;
	while(current!=NULL && current->data!=element)
	{
		previous=current;
		current=current->next;
	}
	if(current==NULL)
	{
		printf("Element not found");
	}
	else
	{
		temp=previous->next;
		previous->next=temp->next;
		free(temp);
	}
	}
}
	
void deleteAfter(int element)
{

	if(start==NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		current=start;
	}
	while(current->next !=NULL && current->data != element)
	{
		current=current->next;
	}
	if(current->next==NULL)
	{
		printf("Element not found\n");
	}
	else
	{
		temp=current->next;
		current->next=temp->next;
		free(temp);
	}
}
void display()
{
	if(start==NULL)
	{
		printf("Empty List");
	}
	printf("Element are:");
	temp=start;
	while(temp->next!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	printf("%d",temp->data);
}

