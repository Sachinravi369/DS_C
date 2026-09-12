#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *link;
};
typedef struct node node;
node *front=NULL;
node *rear=NULL;

void enque(int value){
  node *newnode;
  newnode=(node*)malloc(sizeof(node));
  if(newnode==NULL){
    printf("overflow\n");
    return;
  }
  newnode->data=value;
  newnode->link=NULL;
  if(front==NULL&&rear==NULL){
    front=rear=newnode;
  }else{
    rear->link=newnode;
    rear=newnode;
  }
  printf("inserted\n");
}

void dequeue(){
  node *temp;
  if(front==NULL){
    printf("underflow\n");
    return;
  }
  temp=front;
  printf("dequeued element is %d",temp->data);
  front=front->link;
  if(front==NULL){
    rear=NULL;
  }
  free(temp);
}

void peek(){
  if(front==NULL){
    printf("empty\n");
  }
  else printf("front element is %d",front->data);
}

int is_Empty(){
  return (front==NULL);
}

void display(){
  node *temp;
  if(front==NULL){
    printf("queue is empty\n");
    return;
  }
  temp=front;
  printf("queue element are :");
  while(temp!=NULL){
    printf("%d\t",temp->data);
    temp=temp->link;
  }
  printf("NULL\n");
}

void countNodes(){
  int count=0;
  node *temp=front;
  while(temp!=NULL){
    count++;
    temp=temp->link;
  }
  printf("total is %d",count);
}

int main(){
  int choice,val;
  while(1){
    printf("1.enqueue\n2.dequeue\n3.peek\n4.checkEmpty\n5.display\n6.count\n7.exit\nenter your choice :");
    scanf("%d",&choice);
    switch(choice){
      case 1:printf("enter : ");
             scanf("%d",&val);
             enque(val);
             break;
      case 2:dequeue();
             break;
      case 3:peek();
             break;
      case 4:if(is_Empty()) printf("empty\n");
             else printf("not empty\n");
             break;
      case 5:display();
             break;
      case 6:countNodes();
             break;
      case 7:exit(0);
      default:printf("invalid");
    }
  }
  return 0;
}
