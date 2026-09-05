#include <stdio.h>

#define max 5
int queue[max];
int front=-1;
int rear=-1;

void enqueue(int value){
  if(rear==max-1){
    printf("queue is full\n");
    return;
  }
  queue[++rear]=value;
  if(front==-1) front=0;
  printf("element inserted\n");
}

int dequeue(){
  if(front==-1 || front>rear){
    printf("underflow\n");
    return -1;
  }
  int val=queue[front++];
  if(front>rear){
    front=-1;
    rear=-1;
  }
  return val;
}

void display(){
  if(front==-1 || front>rear){
    printf("empty\n");
    return ;
  }
  printf("queue elements : ");
  for(int i=front;i<=rear;i++){
    printf("%d\t",queue[i]);
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
