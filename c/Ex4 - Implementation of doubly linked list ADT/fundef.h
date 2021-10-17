node* create_all(node*head)
{
 node *new1,*p;
 int size,i;
 printf("enter size : ");
 scanf("%d",&size);
 for(i=0;i<size;i++)
 { new1=(node*)malloc(sizeof(node));
 	printf("enter name of student %d : ",i+1);
 	scanf("%s",new1->name);
  if(head==NULL)
  {
  new1->previous=NULL;
  new1->next=NULL;
  head=new1;
  }
  else
  {
    p=head;
    while(p->next!=NULL)
       p=p->next;
    new1->next=p->next;
    new1->previous=p;
    p->next=new1;
  }
}

return head;
}
node* insertfirst(node*head)
{
  node*new1;
  new1=(node*)malloc(sizeof(node));
  printf("enter name to insert first in list: ");
  scanf("%s",new1->name);
  new1->previous=head->previous;
  head->previous=new1;
  new1->next=head;
  head=new1;
  printf("NAME ADDED IN FRONT \n");
  return head;
}

node* insertlast(node*head)
{
  node*new1,*p;
  new1=(node*)malloc(sizeof(node));
  printf("enter name to append in last : ");
  scanf("%s",new1->name);
  p=head;
  while(p->next!=NULL)
    p=p->next;
  new1->next=p->next;
  new1->previous=p;
  p->next=new1;
  printf("NAME ADDED IN LAST\n");

  return head;

}
node*insAfterName(node*head)
{
  node*new1,*p;
  p=head;
  char keyname[50];
  printf("enter name to insert new after it :  ");
  scanf("%s",keyname);
  new1=(node*)malloc(sizeof(node));
  printf("(new)enter name to append after the given [%s] : ",keyname);
  scanf("%s",new1->name);
  while(strcmp(p->name,keyname)!=0&&p!=NULL)
    p=p->next;
  if(p==NULL)
    printf("name is not found \n");
  else
  { 
    new1->next=p->next;
    new1->previous=p;
    p->next->previous=new1;
    p->next=new1;
  }
 return head;
}


int search_student(node*head,char stud[])
{
 node*p;
 int count=0;
 p=head;
 while(p!=NULL)
 {
  count++;
  if(strcmp(stud,p->name)==0)
     return count;
  p=p->next;
 }
 return -1;
}
node* delete_student(node*head,char stud[])
{
 node*p,*temp;
 p=head;
 while(strcmp(p->name,stud)!=0&&p!=NULL)
     p=p->next;
  if(p==NULL)
   printf("%s is not present in the give list \n",stud);
  else
    {
    temp=p;
    p->next->previous=p->previous;
    p->previous->next=p->next;
    free(temp);
   }
 return head;
}
void displayInAlphabetical(node*head)
{
  node*ptr1,*ptr2,*temp;
  ptr1=head;
  temp=ptr1;
  char tempvar[50];
  
  while(ptr1!=NULL)
   {
     ptr2=ptr1->next;
    while(ptr2!=NULL)
     {  if(strcmp(ptr1->name,ptr2->name)>1)
           {  
              strcpy(tempvar,ptr2->name);
              strcpy(ptr2->name,ptr1->name);
              strcpy(ptr1->name,tempvar);
              
             
           }
           ptr2=ptr2->next;
     
       }  
 ptr1=ptr1->next;    
   }
}
void display(node*head)
{
  node*temp;
  temp=head;

  while(temp!=NULL)
  {   printf("%s\n",temp->name);
    temp=temp->next;
  }
}
