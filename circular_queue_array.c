#include <stdio.h>

#define max 5
int queue[max];
int front=-1;
int rear=-1;

void enqueue(int value){
  if((rear+1)%max==front){
    printf("queue is full\n");
    return;
  }
  //queue[++rear]=value;
  if(front==-1){
    front=0;
    rear=0;
  }
  else rear=(rear+1)%max;
  queue[rear]=value;
  printf("element inserted\n");
}

int dequeue(){
  if(front==-1){
    printf("underflow\n");
    return -1;
  }
  int val=queue[front];
  if(front==rear){
    front=-1;
    rear=-1;
  }
  else front=(front+1)%max;
  return val;
}

void display(){
  if(front==-1){
  printf("empty\n");
  return;
  }
  int i=front;
  while(1){
    printf("%d\t",queue[i]);
    if (i==rear) break;
    i=(i+1)%max;
    
  }
  printf("\n");
  
}

int main(){
  int n,val;
  while(1){
    printf("1.push,2.pop,3.display,4.exit\n");
    scanf("%d",&n);
    switch(n){
      case 1:printf("enter the no : ");
             scanf("%d",&val);
             enqueue(val);
             break;
      case 2:val=dequeue();
             if (val!=-1){
              printf("the entered value is %d\n",val);
             }
             break;
      case 3:display();
             break;
      case 4:return 0;
              break;
      default: return 0;
    }
    }
    return 0;
}
