#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
typedef struct student
{
  int data;
  struct student*link;
}student;
//intializing memory
student* create_memory()
{
 student *head = (student*)malloc(sizeof(student));
// head->link=NULL;
 return head;
}

//link nodes
student* link_node(student *temp){
	if(temp==NULL)
	temp=create_memory();
	else{
	while(temp->link!=NULL)
	temp=temp->link;
	temp->link=temp;
	}
	return temp;
}


// add at first position
student* add_at_first_position(student *temp,int data)
{
 student *node =create_memory();
 node->data=data;
 node->link=temp;
  temp=node;
  return temp;
}
 //int count number of nodes
int count_number_nodes(student *temp)
{
 int count=0;
 while(temp!=NULL)
 {
  temp=temp->link;
  count++;
 }
 return count;
}

//add node at last position
student* add_at_last_position(student *temp,int data)
{
 student *node=create_memory();
 node->data=data;
 node->link=NULL;
 temp->link=node;
 return temp;
}

//add at any postion
void add_at_between(student* temp,int data,int position)
{
 int pos_count=1;
 student* node=(student*)malloc(sizeof(student));
 node->data=data;
 node->link=NULL;
 while(pos_count++<position-1)
 {
  temp=temp->link;
 }
 node->link=temp->link;
 temp->link=node;
}

//print data
void print_data(student*temp)
{
 clrscr();
 while(temp!=NULL)
 {
  printf("%d->",temp->data);
  temp=temp->link;
 }
 printf("NULL");
}

//add node at before the position
student* add_at_after_between(student* temp,int data,int position)
{
int pos_count=1;
position+=1;
 student* node=create_memory();
 node->data=data;
 node->link=NULL;
// position--;
 while(pos_count<position-1)
 {
  temp=temp->link;
  pos_count++;
 }
 node->link=temp->link;
 temp->link=node;
 return temp;
}

//add node at after the position
student* add_at_before_between(student* temp,int data,int position)
{
 int pos_count=1;
position-=1;
 student* node=create_memory();
 node->data=data;
 node->link=NULL;
// position--;
 while(pos_count<position-1)
 {
  temp=temp->link;
  pos_count++;
 }
 node->link=temp->link;
 temp->link=node;
 return temp;

}

//delete node at first
student* delete_node_at_first(student* temp)
{
 student *node=temp;
 if(temp==NULL)
 printf("List is already empty");
 else
 {
  temp=temp->link;
  node=NULL;
  free(node);
 }
 return temp;
}

//delete node from last
student* delete_node_at_last(student*temp)
{
 student*node;
  while(temp->link->link!=NULL)
  {
   temp=temp->link;
  }
   node=temp->link;
   temp->link=NULL;
    free(node);
 return temp;
}

//delete node at any position
student* delete_node_at_between(student *temp,int position)
{
 student* node,*stemp=temp;
 int pos_count=1;
 while(pos_count++<position-1)
 {
  temp=temp->link;
 }
 node=temp->link;
 temp->link=node->link;
 node->link=NULL;
 free(node);
 return stemp;
}
//delete node at after between thr position
student* delete_node_after_between(student *temp,int position)
{
 student* node,*stemp=temp;
 int pos_count=1;
 position+=1;
 while(pos_count++<position-1)
 {
  temp=temp->link;
 }
 node=temp->link;
 temp->link=node->link;
 node->link=NULL;
 free(node);
 return stemp;
}

//delete node at before between the position
student* delete_node_before_between(student *temp,int position)
{
 student* node,*stemp=temp;
 int pos_count=1;
 position-=1;
 while(pos_count++<position-1)
 {
  temp=temp->link;
 }
 node=temp->link;
 temp->link=node->link;
 node->link=NULL;
 free(node);
 return stemp;
}

// to reverse the linked list
student* reverseNode(student *temp)
{
 student *revhead=NULL;
 if(temp==NULL||temp->link==NULL)
 return temp;
 revhead=reverseNode(temp->link);
 temp->link->link=temp;
 temp->link=NULL;
 return revhead;
}


 void main()
 {
  int a,c;
  student* head,*tail;
  student* node=create_memory();
  student* node1 =create_memory();
  clrscr();
  node->data=10;
  node->link=NULL;
  head=node;
  node1->data=20;
  node->link=node1;
  tail=node1;
  while(1)
  {
  puts("\n1.add data at first position\n2.add data at specific position\n3.add data at last position\n4.add data before postion\n5.add data after position");
  puts("6.delete data at first position\n7.delete data at last postion\n8.delete data at specific position\n9.delete data before position\n10.delete data after postion");
  puts("11.display data\n12.count number node\n13.exit\n14.reverse the linked list");
  scanf("%d",&a);
  switch(a)
  {
   case 1:
	 head=add_at_first_position(head,5);
	 break;
   case 2:
	  add_at_between(head,15,3);
	  break;
   case 3:
	 tail=add_at_last_position(tail,25);
	  break;
   case 4:
	 add_at_before_between(head,60,3);
	 break;
   case 5:
	 add_at_after_between(head,50,2);
	 break;
   case 6:
	 head=delete_node_at_first(head);
	 break;
   case 7:
	  tail=delete_node_at_last(head);
	 break;
   case 8:
	 delete_node_at_between(head,3);
	  break;
   case 9:
	  delete_node_before_between(head,3);
	  break;
   case 10:
	 delete_node_after_between(head,3);
	  break;
   case 12:
	 c=count_number_nodes(head);
	 printf("\nno of nodes are->%d",c);
	 break;
   case 11:
	 print_data(head);
	 break;
   case 13:
	   exit(0);
   case 14:
	 head=reverseNode(head);
	 break;
   default:
	 printf("invalid choice!");
  }
 }
 getch();

 }