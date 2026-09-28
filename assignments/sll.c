#include<stdio.h>
#include<stdlib.h>
struct Node{
int roll;
struct Node*next;
};
struct Node*head=NULL;
void display(){
struct Node*t=head;
printf("List:");
if(t==NULL){
printf("Empty\n");
return;
}
while(t){
printf("%d",t->roll);
if(t->next)printf("->");
t=t->next;
}
printf("\n");
}
void insertBeginning(int r){
struct Node*n=malloc(sizeof(struct Node));
n->roll=r;
n->next=head;
head=n;
printf("Inserted %d at beginning\n",r);
display();
}
void insertEnd(int r){
struct Node*n=malloc(sizeof(struct Node));
n->roll=r;
n->next=NULL;
if(head==NULL)head=n;
else{
struct Node*t=head;
while(t->next)t=t->next;
t->next=n;
}
printf("Inserted %d at end\n",r);
display();
}
void search(int r){
struct Node*t=head;
while(t){
if(t->roll==r){
printf("Roll number %d found\n",r);
return;
}
t=t->next;
}
printf("Roll number %d not found\n",r);
display();
}
void deleteNode(int r){
struct Node*t=head,*p=NULL;
while(t&&t->roll!=r){
p=t;
t=t->next;
}
if(!t){
printf("Roll number %d not found\n",r);
display();
return;
}
if(p==NULL)head=t->next;
else p->next=t->next;
free(t);
printf("Roll number %d deleted\n",r);
display();
}
int main(){
int n,r,i,ch;
printf("Enter number of students:");
scanf("%d",&n);
for(i=0;i<n;i++){
printf("Enter roll number:");
scanf("%d",&r);
insertEnd(r);
}
do{
printf("\n1.Insert Beginning\n2.Insert End\n3.Search\n4.Delete\n5.Display\n6.Exit\nEnter choice:");
scanf("%d",&ch);
switch(ch){
case 1:
printf("Enter roll number:");
scanf("%d",&r);
insertBeginning(r);
break;
case 2:
printf("Enter roll number:");
scanf("%d",&r);
insertEnd(r);
break;
case 3:
printf("Enter roll number:");
scanf("%d",&r);
search(r);
break;
case 4:
printf("Enter roll number:");
scanf("%d",&r);
deleteNode(r);
break;
case 5:
display();
break;
case 6:
printf("Exiting...\n");
break;
default:
printf("Invalid choice\n");
}
}while(ch!=6);
return 0;
}
