#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node*next;
};
struct node* head=NULL;

int middle()
{
	struct node* fast=head;
	struct node* slow=head;
	
	while(fast!=NULL && fast->next!=NULL && fast->next->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
	}
	return slow->data;
}
int main()
{
	struct node* first=(struct node*)malloc(sizeof(struct node));
	struct node* second=(struct node*)malloc(sizeof(struct node));
	struct node* third=(struct node*)malloc(sizeof(struct node));
	struct node* fourth=(struct node*)malloc(sizeof(struct node));
	struct node* fifth=(struct node*)malloc(sizeof(struct node));
	struct node* sixth=(struct node*)malloc(sizeof(struct node));
	
	head=first;
	first->data=10;
	first->next=second;
	
	second->data=20;
	second->next=third;
	
	third->data=30;
	third->next=fourth;
	
	fourth->data=40;
	fourth->next=fifth;
	
	fifth->data=50;
	fifth->next=sixth;
	
	sixth->data=60;
	sixth->next=NULL;
	int a=middle();
	printf("%d",a);
}
