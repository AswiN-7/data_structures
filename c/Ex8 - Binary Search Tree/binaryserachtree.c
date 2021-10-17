#include<stdio.h>
#include<stdlib.h>
typedef struct treenode *searchtree;
typedef struct treenode *position;

struct treenode
{
  int element;
  searchtree left,right;
};
void preorder(searchtree t)
{
  if(t!=NULL)
  {
   printf("%d ",t->element);
   preorder(t->left);
   preorder(t->right);      
  }
  
}
void postorder(searchtree t)
{
 if(t!=NULL)
 {
  postorder(t->left);
  postorder(t->right);
  printf("%d ",t->element);
 }
}
void inorder(searchtree t)
{
  if(t!=NULL)
 {
  inorder(t->left);
   printf("%d ",t->element);
  inorder(t->right);
 }
}
searchtree makeempty(searchtree t)
{
  if(t!=NULL)
 {
  makeempty(t->left);
  makeempty(t->right);
  free(t);
 }
  return NULL;
}

searchtree findmin(searchtree t)
{
  if(t==NULL)
       return NULL;

  else if(t->left!=NULL)
  {
   t=findmin(t->left);
  }
  return t;
}

searchtree findmax(searchtree t)
{
   if(t==NULL)
       return NULL;
  else if(t->right!=NULL)
  {
    t=findmax(t->right);
  }
 return t;
}

searchtree insert(int x,searchtree t)
{
 
 if(t==NULL)
 {
    t=(searchtree)malloc(sizeof(searchtree));
  if(t==NULL)
              printf("out of space \n");
  else
    {    printf("memory is allocated\n");
          t->element=x;
          t->left=t->right=NULL;
    } 
 }
 else if(x<t->element)
  {
   t->left=insert(x,t->left);
  }
 else if(x>t->element)
  {
    t->right=insert(x,t->right);
  }
  
  return t;
}
searchtree delete(int x,searchtree t)
{
    position tempnode; 
 if(t==NULL)
    printf("element is not found \n");
 else if(x<t->element)
    t->left=delete(x,t->left);
 else if(x>t->element)
    t->right=delete(x,t->right);
  else if(t->right&&t->left)
     {
       
      tempnode=findmin(t->right);
      t->element=tempnode->element;
      t->right=delete(tempnode->element,t->right);
     }
  else
   {
             tempnode=t;
        if(t->right==NULL&&t->left==NULL)
            t=NULL;
       else if(t->right==NULL)
          t=t->left;
        else if(t->left==NULL)
             t=t->right;
           free(tempnode);         
     
   } 
  return t;
  
}
int main()
{
    searchtree head=NULL;
  searchtree temp;
    while(1)
      {
        int choice,element;
     
       printf("\n\t1--insert\n\t2--delete\n\t3--findmin\n\t4--findmax\n\t5 --inorder traversal\n\t5 --preorder traversal\n\t6 --postorder traversal\n\t-1--stop\nenter your choice : ");
       scanf("%d",&choice);
        if(choice==1)
           {
                printf("enter element to insert :");
                scanf("%d",&element);
                head=insert(element,head);
                //printf("%d\n",head->element);
           }
           else if(choice==2)
            {
               printf("enter element to delete : ");
               scanf("%d",&element);
               temp=delete(element,head);
                /*if(temp==NULL)
                  printf("element not found \n");
                else 
                     printf("%d is deleted \n",element);   
           */ } 
             else if(choice==3)
               {
                  temp=findmin(head);
                   if(temp==NULL)
                  printf("there is no element  \n");
                else 
                     printf("%d is the min element\n",temp->element); 
               }
             else if(choice==4)
               {
                  temp=findmax(head);
                   if(temp==NULL)
                  printf("there is no element  \n");
                else 
                     printf("%d is the max element\n",temp->element); 
               }
               else if(choice==5)
                {
                     inorder(head);
                }
                else if(choice==6)
                     preorder(head);
                else if(choice==7)
                      postorder(head);
              else if(choice==-1)
                  break;
                      
     }
}
/*
 SAMPLE I/O :
aswin@aswin-pavilion-15:~/Desktop/sem3/data structures in c/lab/ex7$ ./bst

	1--insert
	2--delete
	3--findmin
	4--findmax
	5 --inorder traversal
	5 --preorder traversal
	6 --postorder traversal
	-1--stop
enter your choice : 1
enter element to insert :6
memory is allocated

	1--insert
	2--delete
	3--findmin
	4--findmax
	5 --inorder traversal
	5 --preorder traversal
	6 --postorder traversal
	-1--stop
enter your choice : 1
enter element to insert :5
memory is allocated

	1--insert
	2--delete
	3--findmin
	4--findmax
	5 --inorder traversal
	5 --preorder traversal
	6 --postorder traversal
	-1--stop
enter your choice : 1
enter element to insert :4
memory is allocated

	1--insert
	2--delete
	3--findmin
	4--findmax
	5 --inorder traversal
	5 --preorder traversal
	6 --postorder traversal
	-1--stop
enter your choice : 1
enter element to insert :3
memory is allocated

	1--insert
	2--delete
	3--findmin
	4--findmax
	5 --inorder traversal
	5 --preorder traversal
	6 --postorder traversal
	-1--stop
enter your choice : 1
enter element to insert :10
memory is allocated

	1--insert
	2--delete
	3--findmin
	4--findmax
	5 --inorder traversal
	5 --preorder traversal
	6 --postorder traversal
	-1--stop
enter your choice : 1
enter element to insert :7
memory is allocated

	1--insert
	2--delete
	3--findmin
	4--findmax
	5 --inorder traversal
	5 --preorder traversal
	6 --postorder traversal
	-1--stop
enter your choice : 1
enter element to insert :11
memory is allocated

	1--insert
	2--delete
	3--findmin
	4--findmax
	5 --inorder traversal
	5 --preorder traversal
	6 --postorder traversal
	-1--stop
enter your choice : 3
3 is the min element

	1--insert
	2--delete
	3--findmin
	4--findmax
	5 --inorder traversal
	5 --preorder traversal
	6 --postorder traversal
	-1--stop
enter your choice : 4
11 is the max element

	1--insert
	2--delete
	3--findmin
	4--findmax
	5 --inorder traversal
	5 --preorder traversal
	6 --postorder traversal
	-1--stop
enter your choice : 5
3 4 5 6 7 10 11 
	1--insert
	2--delete
	3--findmin
	4--findmax
	5 --inorder traversal
	5 --preorder traversal
	6 --postorder traversal
	-1--stop
enter your choice : 6
6 5 4 3 10 7 11 
	1--insert
	2--delete
	3--findmin
	4--findmax
	5 --inorder traversal
	5 --preorder traversal
	6 --postorder traversal
	-1--stop
enter your choice : 7
3 4 5 7 11 10 6 
	1--insert
	2--delete
	3--findmin
	4--findmax
	5 --inorder traversal
	5 --preorder traversal
	6 --postorder traversal
	-1--stop
enter your choice : 6
6 5 4 3 10 7 11 
	1--insert
	2--delete
	3--findmin
	4--findmax
	5 --inorder traversal
	5 --preorder traversal
	6 --postorder traversal
	-1--stop
enter your choice : -1

*/
