typedef struct node
{
  struct node*previous,*next;
     char name[50];
} node;
node* insertlast(node*head);
node* insertfirst(node*head);
node* create_all(node*head);
node* insAfterName(node*head);
int search_student(node*head,char stud[]);
node* delete_student(node*head,char stud[]);
void displayInAlphabetical(node*head);
void display(node*head);

