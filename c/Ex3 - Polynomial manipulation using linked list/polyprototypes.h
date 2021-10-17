typedef struct node{
   int coe;
   int exp;
   struct node*next;
} node;
void display(node*,char );
node* sumEqualpow(node*head);
node* insertlast(node*);
node* addinsert(node*head,int coe,int exp);
node* add_polynomial(node*p1,node*p2);
node* multiply_polynomial(node*p1,node*p2);
node* sort(node*head);
