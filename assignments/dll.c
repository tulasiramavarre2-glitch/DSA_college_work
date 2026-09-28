#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node
{
char page[50];
struct Node *prev;
struct Node *next;
};
struct Node *head=NULL,*current=NULL;
void insertPage()
{
struct Node *newnode;
char page[50];
newnode=(struct Node*)malloc(sizeof(struct Node));
printf("Enter page name: ");
scanf("%s",page);
strcpy(newnode->page,page);
newnode->prev=NULL;
newnode->next=NULL;
if(head==NULL)
{
head=newnode;
current=newnode;
}
else
{
newnode->prev=current;
newnode->next=current->next;
if(current->next!=NULL)
current->next->prev=newnode;
current->next=newnode;
current=newnode;
}
printf("Page inserted successfully.\n");
}
void forward()
{
if(current==NULL)
printf("No pages available.\n");
else if(current->next==NULL)
printf("Already at the last page.\n");
else
{
current=current->next;
printf("Current page: %s\n",current->page);
}
}
void backward()
{
if(current==NULL)
printf("No pages available.\n");
else if(current->prev==NULL)
printf("Already at the first page.\n");
else
{
current=current->prev;
printf("Current page: %s\n",current->page);
}
}
void deletePage()
{
struct Node *temp;
char page[50];
printf("Enter page to delete: ");
scanf("%s",page);
temp=head;
while(temp!=NULL&&strcmp(temp->page,page)!=0)
temp=temp->next;
if(temp==NULL)
{
printf("Page not found.\n");
return;
}
if(temp->prev!=NULL)
temp->prev->next=temp->next;
else
head=temp->next;
if(temp->next!=NULL)
temp->next->prev=temp->prev;
if(current==temp)
{
if(temp->next!=NULL)
current=temp->next;
else
current=temp->prev;
}
free(temp);
printf("Page deleted successfully.\n");
}
void displayForward()
{
struct Node *temp=head;
if(temp==NULL)
{
printf("No pages available.\n");
return;
}
printf("Pages from first to last:\n");
while(temp!=NULL)
{
printf("%s ",temp->page);
temp=temp->next;
}
printf("\n");
}
void displayBackward()
{
struct Node *temp=head;
if(temp==NULL)
{
printf("No pages available.\n");
return;
}
while(temp->next!=NULL)
temp=temp->next;
printf("Pages from last to first:\n");
while(temp!=NULL)
{
printf("%s ",temp->page);
temp=temp->prev;
}
printf("\n");
}
int main()
{
int choice;
while(1)
{
printf("\n1.Insert Page\n2.Move Forward\n3.Move Backward\n4.Delete Page\n5.Display First to Last\n6.Display Last to First\n7.Exit\n");
printf("Enter choice: ");
scanf("%d",&choice);
switch(choice)
{
case 1:insertPage();break;
case 2:forward();break;
case 3:backward();break;
case 4:deletePage();break;
case 5:displayForward();break;
case 6:displayBackward();break;
case 7:exit(0);
default:printf("Invalid choice.\n");
}
}
return 0;
}
