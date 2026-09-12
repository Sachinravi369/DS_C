#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *link;
};
struct node *start=NULL;

void insert_at_beg(){
  struct node *newnode;
  newnode=(struct node*)malloc(sizeof(struct node));
  printf("enter the data : ");
  scanf("%d",&newnode->data);
  newnode->link=NULL;
  if(start==NULL) start=newnode;
  else{
    newnode->link=start;
    start=newnode;
  }
}

void insert_at_end(){
  struct node *newnode,*trav;
  newnode=(struct node*)malloc(sizeof(struct node));
  printf("enter the data : ");
  scanf("%d",&newnode->data);
  newnode->link=NULL;
  if(start==NULL) start=newnode;
  else{
    trav=start;
    while(trav->link!=NULL)
      trav=trav->link;
    trav->link=newnode;
  }
}

void insert_at_mid(){
  int i,pos;
  struct node *newnode,*temp,*temp1;
  newnode=(struct node*)malloc(sizeof(struct node));
  printf("enter the data : ");
  scanf("%d",&newnode->data);
  newnode->link=NULL;
  printf("enter the pos : ");
  scanf("%d",&pos);
  if(pos==1){
    newnode->link=start;
    start=newnode;
    return;
  }
  temp=start;
  for(i=1;i<pos-1&&temp!=NULL;i++)
    temp=temp->link;
  if(temp==NULL){
    printf("invalid position\n");
    free (newnode);
    return;
  }
  temp1=temp->link;
  newnode->link=temp1;
  temp->link=newnode;
}

void del_beg(){
  struct node *temp;
  if(start==NULL){
    printf("list is empty \n");
    return;
  }
  temp=start;
  start=start->link;
  free(temp);
  printf("element deleted\n");
}

void del_end(){
  struct node *temp,*prev;
  if(start==NULL){
    printf("list is empty\n");
    return;
  }
  if(start->link==NULL){
    printf("element deleted \n");
    free(start);
    start=NULL;
    return;
  }
  temp=start;
  while(temp->link!=NULL){
    prev=temp;
    temp=temp->link;
  }
  prev->link=NULL;
  printf("element deleted \n");
  free(temp);
}

void del_mid(){
  int pos,i;
  struct node *prev,*temp;
  if(start==NULL){
    printf("list is empty\n");
    return;
  }
  printf("enter pos : ");
  scanf("%d",&pos);
  if(pos==1){
    del_beg();
    return;
  }
  temp=start;
  for(i=1;i<pos&&temp!=NULL;i++){
    prev=temp;
    temp=temp->link;
  }
  if(temp==NULL){
    printf("invalid pos\n");
    return;
  }
  prev->link=temp->link;
  printf("element deleted \n");
  free(temp);
}

void display(){
  struct node *temp;
  if(start==NULL){
    printf("empty\n");
    return;
  }
  temp=start;
  printf("linkedlist : ");
  while(temp!=NULL){
    printf("%d-",temp->data);
    temp=temp->link;
  }
  printf("NULL\n");
}

void search(){
  int key,pos=1,found=0;
  struct node *temp=start;
  if(start==NULL){
    printf("list is empty\n");
    return;
  }
  printf("enter the element to search : ");
  scanf("%d",&key);
  while(temp!=NULL){
    if(temp->data==key){
      printf("found at pos %d",pos);
      found=1;
      break;
    }
    temp=temp->link;
    pos++;
  }
  if(!found){
    printf("element not found \n");
  }
}

void count_nodes(){
  int count=0;
  struct node *temp=start;
  while(temp!=NULL){
    count++;
    temp=temp->link;
  }
  printf("total nodes %d\n",count);
}

void reverse(){
  struct node *prev=NULL,*current=start,*next=NULL;
  while(current!=NULL){
    next=current->link;
    current->link=prev;
    prev=current;
    current=next;
  }
  start=prev;
  printf("list reversed\n");
}

void sort(){
  struct node *i,*j;
  int temp_data;
  if(start==NULL){
    printf("list empty\n");
    return;
  }
  for(i=start;i->link!=NULL;i=i->link){
    for(j=i->link;j!=NULL;j=j->link){
      if(i->data>j->data){
        temp_data=i->data;
        i->data=j->data;
        j->data=temp_data;
      }
    }
  }
  printf("sorted sucessfully \n");
}

int main(){
  int choice;
  while(1){
    printf("1.in beg\t 2.in end\t 3.in mid\t 4.del beg \t 5.del end\t6.del mid\t 7.dislay\t8.search\t9.count nodes\t10.reverse\t11.sort\t12.exit : ");
    scanf("%d",&choice);
    switch (choice){
      case 1:insert_at_beg();
             break;
      case 2: insert_at_end();
             break;
      case 3:insert_at_mid();
             break;
      case 4:del_beg();
             break;
      case 5:del_end();
             break;
      case 6:del_mid();
             break;
      case 7:display();
             break;
      case 8:search();
             break;
      case 9:count_nodes();
             break;
      case 10:reverse();
             break;
      case 11:sort();
             break;
      case 12:exit(0);
     default:printf("invalid input");
     }
     }
     return 0;
     }
  
