#include<stdio.h>

#define max 10
int stack[max];
int top=-1;

void push(int value){
  if(top==max-1){
    printf("overflow\n");
    return;
  }
  stack[++top]=value;
  printf("pushed\n");
}

int pop(){
  if(top==-1){
    printf("underflow\n");
    return -1;
  }
  return stack[top--];
}

int peek(){
  if (top==-1){
    printf("empty\n");
    return -1;
  }
  return stack[top];
}

void display(){
  if(top==-1){
   printf("empty\n");
   return;
  }
  printf("stack elements : ");
  for(int i=top;i>=0;i--){
    printf("%d",stack[i]);
  }
}

int main(){
  int n,val;
  while(1){
    printf("1.push,2.pop,3.peek,4.display\n");
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
      case 3:val=peek();
             if (val!=-1){
              printf("the entered value is %d\n",val);
             }
             break;
      case 4:display();
              break;
      default: return 0;
    }
    }
}


























