struct student{
	int regno;
	char name[20];
	int mark[5];
};
void input(struct student srecord[],int i)
{
	int j;
	printf("enter name of student %d : ",i+1);
   	scanf("%s",srecord[i].name);
   	printf("enter regno of %s : ",srecord[i].name);
   	scanf("%d",&srecord[i].regno);
     for(j=0;j<5;j++)
     {
     	printf("enter mark subject  %d : ",j+1);
     	scanf("%d",&srecord[i].mark[j]);
     }
 

}
void insertfirst(struct student srecord[],struct student a[],int size)
{
	int i;
	for(i=size;i>0;i--)
		srecord[i]=srecord[i-1];
    srecord[i]=a[0];
	
}
void insertlast(struct student srecord[],struct student a[],int size)
{
	
	
    srecord[size]=a[0];
}

void displayall(struct student srecord[],int size)
{
  int i,j;
	for(i=0;i<size;i++)
	 { 
	  printf("     student %d : %s\n",i+1,srecord[i].name);
	  printf("     regno : %d\n",srecord[i].regno);
	  printf("     marks : ");
	  for(j=0;j<5;j++)
         printf("%d  ",srecord[i].mark[j]);
      printf("\n");
     }	
}

int insert_regno(struct student srecord[],struct student a[],int size,int inreg)
{
	int i,j,temp=-1;
	for(i=0;i<size;i++)
	   {
	   	if(inreg==srecord[i].regno)
               {

               	   temp=i;
                    break;
                }
	   }
	   if(temp==-1)
	   	return -1;
	   else
	   {
	   	for(i=size;i>temp+1;i--)
	         srecord[i]=srecord[i-1];
	      srecord[temp+1]=a[0];
          return 1;
 
        }
}
 
int search_name(struct student srecord[],char sname[],int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		if(strcmp(sname,srecord[i].name)==0)
          return i;

	}
	return -1;
}
int delete_rec(struct student srecord[],int size,int inreg)
{
	int i,j,temp=-1;
	for(i=0;i<size;i++)
	   {
	   	if(inreg==srecord[i].regno)
               {

               	   temp=i;
                    break;
                }
	   }
	   if(temp==-1)
	   	return -1;
	   else
	   {
	   	for(i=temp;i<size;i++)
	         srecord[i]=srecord[i+1];
          return temp;
         }

}
int previous_next(struct student srecord[],int size,int inreg)
{
	int i,j,temp=-1;
	for(i=0;i<size;i++)
	   {
	   	if(inreg==srecord[i].regno)
               {

               	   temp=i;
                    break;
                }
	   }
	   if(temp==-1)
	   	return -1;
	   return temp;

}
void display(struct student srecord[],int size,int i)
{      int j;
   
	  printf("student %d : %s\n",i+1,srecord[i].name);
	  printf("regno : %d\n",srecord[i].regno);
	  printf("marks : ");
	  for(j=0;j<5;j++)
         printf("%d  ",srecord[i].mark[j]);
      printf("\n");
     	
}
