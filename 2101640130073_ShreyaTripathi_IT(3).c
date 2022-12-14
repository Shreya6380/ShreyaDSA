#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};
struct Node*head;

int main()
{
	head=NULL;
	struct Node*first=(struct Node*)malloc(sizeof(struct Node));
	struct Node*second=(struct Node*)malloc(sizeof(struct Node));
	struct Node*third=(struct Node*)malloc(sizeof(struct Node));
	struct Node*fourth=(struct Node*)malloc(sizeof(struct Node));
	
	head=first;
	first->data=10;
	first->next=second;
	
	second->data=20;
	second->next=third;
	
	third->data=30;
	third->next=fourth;

	fourth->data=40;
	fourth->next=NULL;
	int n,i=1;
	printf("Enter the position: ");
	scanf("%d",&n);
	struct Node* temp=head;
	while(i<=n)
	{
		if(i==n)
		printf("%d ",temp->data);
		else;
		temp=temp->next;
		i++;
	}
	return 0;
	
}
