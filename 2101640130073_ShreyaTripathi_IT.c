#include<stdio.h>
#include<stdlib.h>

typedef struct nodetype{
	int info;
	struct nodetype *next;
}node;

void insertatbeg(node **start,int item){
	node *ptr;
	ptr=(node*)malloc(sizeof(node));
	ptr->info = item;
	ptr->next= *start;
	*start=ptr;
}

void insertatend(node **start,int item){
	node *ptr,*last;
	ptr=(node*)malloc(sizeof(node));
	ptr->info=item;
	ptr->next=NULL;
	if(start==NULL)
	  *start=ptr;
	else{
		last=*start;
		while(last->next!=NULL)
		 last=last->next;
		last->next=ptr;
	}
}

void display(node *start){
	if(start==NULL){
		printf("\n Linked List is Empty");
		return;
	}
	while(start!=NULL){
		printf("%d-",start->info);
		 start=start->next;
	}
}

void deleteatbeg(node **start){
	node *ptr;
	if(*start==NULL){
		printf("\n Linked List is Empty");
		return;
	}
	ptr= *start;
	*start=ptr->next;
	printf("\n Deleted Value=%d",ptr->info);
	free(ptr);
}

void deleteatend(node ** start){
	node *ptr,*last;
	if(*start==NULL){
		printf("\n Linked List is Empty");
		return;
}
    if ((*start)->next==NULL){
    	ptr=*start;
    	*start=NULL;
	}
	else{
		last=*start;
	while(last->next->next!=NULL)
	   last=last->next;
	   ptr=last->next;
	   last->next=NULL;
	}
	   printf("\n Deleted value=%d",ptr->info);
	   free(ptr);
}

node *search(node *start , int key){
	while(start!=NULL && start->info!=key)
	   start=start->next;
	return start;
}

void displayreverse(node *start){
	if(start->next!=NULL)
	  displayreverse(start->next);
	printf("%d-",start->info);
}
void removeatindx(node **start,int pos)
{
	int temp;
	node *ptr;
	ptr=*start;
	while(pos>1)
	{
		ptr=ptr->next;
		pos--;
}
	ptr->next=ptr->next->next;
	 printf("\n Deleted value=%d",ptr->info);
	free(ptr);
}

void reverselist(node **start){
	node *pnode,*cnode,*nnode;
	pnode=NULL;
	cnode=*start;
	nnode=cnode->next;
	cnode->next=NULL;
	while(pnode!=NULL){
		pnode=cnode;
		cnode=nnode;
		nnode=cnode->next;
		cnode->next-pnode;
	}
	*start=cnode;
}

int main(){
	int item , choice,pos;
	node *head;
	head=NULL;
	while(1){
		printf("\n ----LINKED LIST MENU---\n");
		printf("\n 1. Insert at Beg\n");
		printf("\n 2. Insert at End\n");
		printf("\n 3. Delete at Beg\n");
		printf("\n 4. Insert at End\n");
		printf("\n 5. Display in Order\n");
		printf("\n 6. Display in Reverse\n");
		printf("\n 7. Remove at specific index\n");
		printf("\n 8. Exit");
		printf("\n Enter Your Choice:");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("\n Enter Item=");
				scanf("%d",&item);
				insertatbeg(&head , item);
				break;
			
			case 2:
				printf("\n Enter Item=");
				scanf("%d",&item);
				insertatend(&head , item);
				break;
				
			case 3:
				deleteatbeg(&head);
				break;
				
			case 4:
				deleteatend(&head);
				break;
			
			case 5:
				display(head);
				break;
				
			case 6:
				displayreverse(head);
				break;
			case 7:
				printf("Enter the position\n");
				scanf("%d",&pos);
				removeatindx(&head,pos);
				break;
			default:
				exit(1);
				
		}
	}
}
