node* insertlast(node*head)
{
  node*new,*p;
  static int time=0;
  int data,size,i;
  printf("enter how many variabels are going to in this equation %d : ",++time);
  scanf("%d",&size);
  for(i=0;i<size;i++)
  {
   new=(node*)malloc(sizeof(node));
   printf("enter coefficient variable %d : ",i+1);
   scanf("%d",&new->coe);
   printf("enter exponent of variable %d : ",i+1);
   scanf("%d",&new->exp);
   if(head==NULL)
    {
      head=new;
      new->next=NULL;
    }
    else
    {
      p=head;
      while(p->next!=NULL)
          p=p->next;
     new->next=p->next;
     p->next=new;
    }
  }
  
  return head;
}
 void display(node*head,char var)
 {
  int i=0;
  node*temp;
  temp=head;
  while(temp!=NULL)
   { 
    printf("%d%c^%d ",temp->coe,var,temp->exp);
    if(temp->next!=NULL)
     printf(" + ");
    temp=temp->next;
    
   }
 }






node* add_polynomial(node*p1,node*p2)
{
 node*p,*q,*add,*new;
  add=NULL;
 p=p1;
 q=p2;
 while(p!=NULL&&q!=NULL)
 {
  if(p->exp==q->exp)
  {
   if(p->coe+q->coe!=0)
   {
    add=addinsert(add,(p->coe+q->coe),p->exp); }
       p=p->next;
       q=q->next;
  }
  else if(p->exp>q->exp)
   {
    add=addinsert(add,p->coe,p->exp);
    p=p->next;
   }
  else if(p->exp<q->exp)
   {
   add=addinsert(add,q->coe,q->exp);
   q=q->next;
   }
   
 }
if(p!=NULL)
{
 while(p!=NULL)
 {
   add=addinsert(add,p->coe,p->exp);
   p=p->next;
 
 }
}
 else if(q!=NULL)
 {
 while(q!=NULL)
  {
  add=addinsert(add,q->coe,q->exp);
  q=q->next;
  }
 }
return add;
  
}

node* addinsert(node*head,int coe,int exp)
{
 node*new,*p;
 new=(node*)malloc(sizeof(node));
 new->coe=coe;
 new->exp=exp;
 if(head==NULL)
  {
   head=new;
   new->next=NULL;
  }
 else
  {
   p=head;
   while(p->next!=NULL)
    p=p->next;
  new->next=p->next;
  p->next=new;
  }
return head;
}
node* multiply_polynomial(node*p1,node*p2)
{
 int exp,coe;
 node*temp1,*temp2,*multi;
 temp1=p1;
 multi=NULL;
 
 while(temp1!=NULL)
 {
    temp2=p2;
  while(temp2!=NULL)
  {
   exp=temp1->exp+temp2->exp;
   coe=temp1->coe*temp2->coe;
   multi=addinsert(multi,coe,exp);
   temp2=temp2->next;
  }
   temp1=temp1->next;
 }

 return multi;
}

node* sumEqualpow(node*head)
{
 node*temp1,*temp2,*dup;
 temp1=head;
 
 while(temp1->next!=NULL)
 {
   temp2=temp1;
   while(temp2->next!=NULL)
   {
    if(temp1->exp==temp2->next->exp)
    {

     temp1->coe+=temp2->next->coe;
     dup=temp2->next;
     temp2->next=temp2->next->next;
     free(dup);
     }
    else
     temp2=temp2->next;
   }
   temp1=temp1->next;
  
  
 }
return head;
}

node* sort(node*head)
{  
int tcoe,texp;
node*temp1,*temp2;
temp1=head;
while(temp1->next!=NULL)
{
temp2=temp1->next;
while(temp2!=NULL)
{
  if(temp1->exp<temp2->exp)
  {
   tcoe=temp1->coe;
   texp=temp1->exp;
  temp1->coe=temp2->coe;
  temp1->exp=temp2->exp;
  temp2->coe=tcoe;
  temp2->exp=texp;
  
  }
  temp2=temp2->next;
}
temp1=temp1->next;
}
return head; 
}

