#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *next;
  struct node *prev;
};
typedef struct node node;
node *head=NULL;

node* createNode(int value){
  node *newnode=(node*)malloc(sizeof(node));
  if(newnode==NULL){
    printf("memory allocation failed\n");
    return NULL;
  }
  newnode->data=value;
  newnode->prev=NULL;
  newnode->next=NULL;
  return newnode;
}

void insert_at_beg(int value){
  node *newnode=createNode(value);
  if(newnode==NULL){
    return;
  }
  if(head==NULL){
      newnode->next=NULL;
      newnode->prev=NULL;
      head=newnode;
  }
  else{
      newnode->next=head;
      head->prev=newnode;
      head=newnode;
  }
  printf("element inserted\n");
}

void insert_at_end(int value){
  node *newnode=createNode(value);
  if(newnode==NULL)return;
  if(head==NULL){
    head=newnode;
    return;
  }
  node *temp=head;
  while(temp->next!=NULL)
    temp=temp->next;
  temp->next=newnode;
  newnode->prev=temp;
  printf("element inserted\n");
}

void insert_at_pos(int value,int pos){
  if(pos==1){
    insert_at_beg(value);
    return;
  }
  node *temp=head;
  for(int i=1;i<pos-1&&temp!=NULL;i++)
    temp=temp->next;
  if(temp==NULL){
    printf("invalid position\n");
    return;
  }
  node *newnode=createNode(value);
  if(newnode==NULL)return;
  newnode->next=temp->next;
  newnode->prev=temp;
  if(temp->next!=NULL){
    temp->next->prev=newnode;
  }
  temp->next=newnode;
  printf("element inserted\n");
}

void del_beg(){
  if(head==NULL){
    printf("list is empty \n");
    return;
  }
  node *temp=head;
  head=head->next;
  if(head!=NULL)head->prev=NULL;
  printf("element deleted\n");
  free(temp);
}

void del_end(){
  if(head==NULL){
    printf("list is empty\n");
    return;
  }
  node *temp=head;
  if(temp->next==NULL){
    printf("element deleted \n");
    free(temp);
    head=NULL;
    return;
  }

  while(temp->next!=NULL){
    temp=temp->next;
  }
  temp->prev->next=NULL;
  printf("element deleted \n");
  free(temp);
}

void del_pos(int pos){
  if(head==NULL){
    printf("list is empty\n");
    return;
  }
  if(pos==1){
    del_beg();
    return;
  }
  node *temp=head;
  for(int i=1; i<pos && temp!=NULL ;i++){
    temp=temp->next;
  }
  if(temp==NULL){
    printf("invalid pos\n");
    return;
  }
  if(temp->next!=NULL)
    temp->next->prev=temp->prev;
  if(temp->prev!=NULL)
    temp->prev->next=temp->next;
  printf("element deleted \n");
  free(temp);
}

void forward_traverse(){
  if(head==NULL){
    printf("empty\n");
    return;
  }
  node *temp=head;
  printf("forward traverse : ");
  while(temp!=NULL){
    printf("%d-",temp->data);
    temp=temp->next;
  }
  printf("NULL\n");
}

void backward_traverse(){
  if(head==NULL){
    printf("empty\n");
    return;
  }
  node *temp=head;
  while(temp->next!=NULL)
    temp=temp->next;
  printf("backward traverse : ");
  while(temp!=NULL){
    printf("%d-",temp->data);
    temp=temp->prev;
  }
  printf("NULL\n");
}

void search(int key){
  node *temp=head;
  int pos=1;
  while(temp!=NULL){
    if(temp->data==key){
      printf("found at pos %d\n",pos);
      return;
    }
    temp=temp->next;
    pos++;
  }
  printf("element not found \n");
}

void count_nodes(){
  int count=0;
  node *temp=head;
  while(temp!=NULL){
    count++;
    temp=temp->next;
  }
  printf("total nodes %d\n",count);
}

void reverse(){
  if(head==NULL){
    printf("list empty\n");
    return;
  }
  node *temp=NULL;
  node *current=head;
  while(current!=NULL){
    temp=current->prev;
    current->prev=current->next;
    current->next=temp;
    current=current->prev;
  }
  if(temp!=NULL)
    head=temp->prev;
  printf("list reversed\n");
}

void sort(){
  if(head==NULL){
    printf("list empty\n");
    return;
  }
  node *i,*j;
  int temp_data;
  for(i=head;i->next!=NULL;i=i->next){
    for(j=i->next;j!=NULL;j=j->next){
      if(i->data >j->data){
        temp_data=i->data;
        i->data=j->data;
        j->data=temp_data;
      }
    }
  }
  printf("sorted sucessfully \n");
}

int main(){
  int choice,val,pos;
  while(1){
    printf("1.in beg\t 2.in end\t 3.in mid\t 4.del beg \t 5.del end\t6.del mid\t 7.forw trav \t 8back trav \t9.search\t10.count nodes\t11.reverse\t12.sort\t13.exit : ");
    scanf("%d",&choice);
    switch (choice){
      case 1:printf("enter the value : ");
             scanf("%d",&val);
            insert_at_beg(val);
             break;
      case 2:printf("enter the value : ");
             scanf("%d",&val);
            insert_at_end(val);
             break;
      case 3:printf("enter the value : ");
             scanf("%d",&val);
             printf("enter the pos: ");
             scanf("%d",&pos);
              insert_at_pos(val,pos);
             break;
      case 4:del_beg();
             break;
      case 5:del_end();
             break;
      case 6:printf("enter the position : ");
             scanf("%d",&pos);
             del_pos(pos);
             break;
      case 7:forward_traverse();
             break;
      case 8:backward_traverse();
             break;
      case 9:printf("enter item to be searched : ");
             scanf("%d",&val);
            search(val);
             break;
      case 10:count_nodes();
             break;
      case 11:reverse();
             break;
      case 12:sort();
             break;
      case 13:exit(0);
     default:printf("invalid input");
     }
     }
     return 0;
     }
  
