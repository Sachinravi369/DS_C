#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *link;
};

typedef struct node node;

node *top=NULL;

void push(int value){
  node *s;
  s=(node*) malloc (sizeof(node));
  if(s==NULL){
    printf("overflow");
    return ;
  }
  s->data=value;
  s->link=top;
  top=s;
  printf("pushed\n");
}

int pop(){
  node *temp;
  if(top==NULL){
    printf("underflow\n");
    return -1;
  }
  temp=top;
  int value=top->data;
  top=top->link;
  free(temp);
  return value;
}

void display(){
  node *temp;
  if(top==NULL){
    printf("empty\n");
    return;
  }
  temp=top;
  printf("elements : ");
  while(temp!=NULL){
     printf("%d\t",temp->data);
     temp=temp->link;
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
             push(val);
             break;
      case 2:val=pop();
             if (val!=-1){
              printf("the entered value is %d\n",val);
             }
             break;
      case 3:display();
              break;
      case 4:return 0;
      default: return 0;
    }
    }
  return 0;
}
