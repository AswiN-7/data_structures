#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#include<ctype.h> 

typedef struct mynode{    
    char node;    
    struct mynode *left,*right;
}exp_tree;

typedef struct{     
    int top;    
    int capacity;    
    exp_tree* array[50]; 
}stackexp;  

int isOperation(char c); 
int getPriority(char op); 
int isEmpty(stackexp *s); 
int isFull(stackexp *s); 
exp_tree* createNode(char c); 
void push(char c,stackexp* s); 
char pop(stackexp *s); char top(stackexp *s); 
void convertInToPost(char infix[],char postfix[]); 
exp_tree* convertPostToExp(char postfix[]); 
void PreOrderTraversal(exp_tree *t); 
void InOrderTraversal(exp_tree *t); 
void PostOrderTraversal(exp_tree *t);

int isOperation(char c) {    
    switch(c)
    {   case '+':        
        case '-':        
        case '/':        
        case '*':         
        case '%': return 1;        
        default: return 0;    
    } 
}

int getPriority(char op)
{   
    switch(op)     
    {        
        case '/':        
        case '*':         
        case '%':return 1;         
        case '+':         
        case '-':return 0;         
        default: return -1;     
    } 
}   

int isEmpty(stackexp *s)
{   
    if(s->top==-1)         
        return 1;         
    else        
        return 0; 
} 

int isFull(stackexp *s) 
{     
    if(s->top==s->capacity)         
        return 1;     
    else         
        return 0; 
}

exp_tree* createNode(char c) {     
    exp_tree* temp=(exp_tree*)malloc(sizeof(exp_tree));     
    temp->left=temp->right=NULL;     
    temp->node=c;     
    return temp;
}  

void push(char c,stackexp* s) {     
    if(isFull(s)==1)
        printf("Stack full no elements can be pushed");          
    else     
    {         
        s->top=s->top+1;         
        exp_tree *t1=createNode(c);         
        s->array[s->top]=t1;     
    } 
}  

char pop(stackexp *s) {     
    if(isEmpty(s)==1)     
    {         
        printf("No elements left to pop");         
        return '\0';     
    }     
    else {        
        exp_tree *pop=s->array[s->top];         
        s->top=s->top-1;         
        return pop->node;     
    } 
}


char top(stackexp *s) {     
    exp_tree *t=s->array[s->top];     
    return t->node; 
}  

void convertInToPost(char infix[],char postfix[]) {     
    stackexp *s1;     
    s1=(stackexp*)malloc(sizeof(stackexp));     
    s1->top=-1;     
    s1->capacity=50;     
    int in=0,post=0;    
    strcpy(postfix,"");     
    while(infix[in]!='\0')     
    {         
        if(infix[in]=='(')         
        {             
            push(infix[in],s1);             
            in++;         
        }         
        else if(infix[in]==')')         
        {
            while(s1->top!=-1 && top(s1)!='(')             
            {
                postfix[post]=pop(s1);                 
                post++;             
            }             
            if(s1->top==-1)             
            {                 
                printf("INCORRECT EXP.\n");                 
                exit(0);             
            }             
            char temp;             
            temp=pop(s1);            
            in++;         
        }        
        else if(isdigit(infix[in]) || isalpha(infix[in])) 
        {        
            postfix[post]=infix[in];             
            post++;             
            in++;         
        }         
        else if(isOperation(infix[in]))         
        {             
            while(s1->top!=-1 && top(s1)!='(' && getPriority(top(s1))>getPriority(infix[in]) )             
            {                 
                postfix[post]=pop(s1);                
                post++;             
            }             
            push(infix[in],s1);            
            in++;         
        }        
        else {             
            printf("INCORRECT ELEMENT IN EXP.\n");            
            exit(0);         
        }
    }     
    while(s1->top!=-1 && top(s1)!='(')     
    { 
        postfix[post]=pop(s1);         
        post++;     
    }     
    postfix[post]='\0'; 
} 
            
 exp_tree* convertPostToExp(char postfix[]) {     
    stackexp *s1;     
    exp_tree *tree;     
    tree=(exp_tree*)malloc(sizeof(exp_tree));     
    s1=(stackexp*)malloc(sizeof(stackexp));     
    s1->top=-1;     
    s1->capacity=49;    
    exp_tree *temp,*temp1,*temp2;     
    for(int i=0;i<strlen(postfix);i++)     
    {         
        if(isOperation(postfix[i])==0)         
            push(postfix[i],s1); 
        else{             
            temp = createNode(postfix[i]);              
            temp1=s1->array[s1->top--];             
            temp2=s1->array[s1->top--];            
            temp->right = temp1;              
            temp->left = temp2;             
            s1->top=s1->top+1;             
            s1->array[s1->top]=temp;         
            }     
    }     
    tree=s1->array[s1->top];     
    return tree; 
}  
                
void PreOrderTraversal(exp_tree *t) {
    if(t==NULL)    
        return;        
    else{         
        printf("%c",t->node);         
        PreOrderTraversal(t->left);         
        PreOrderTraversal(t->right);     
        } 
                
} 

 void InOrderTraversal(exp_tree *t) {     
     if(t==NULL)        
        return;          
     else
    {         
        InOrderTraversal(t->left);         
        printf("%c",t->node);         
        InOrderTraversal(t->right);     
    } 
} 
     
     
 void PostOrderTraversal(exp_tree *t) {     
     if(t==NULL)
        return;    
     else     
     {         
        PostOrderTraversal(t->left);         
        PostOrderTraversal(t->right);         
        printf("%c",t->node);     
    } 
}  

int main() 
{     
    char infix[60],postfix[60];     
    printf("Enter Infix Expression: ");     
    scanf("%s",infix);     
    convertInToPost(infix,postfix);     
    exp_tree *tree1;     
    tree1=(exp_tree*)malloc(sizeof(exp_tree));     
    tree1=convertPostToExp(postfix);     
    printf("\nPre Order Traversal: ");    
    PreOrderTraversal(tree1);     
    printf("\n");     
    printf("\nIn Order Traversal: ");     
    InOrderTraversal(tree1);     
    printf("\n");     
    printf("\nPost Order Traversal: ");     
    PostOrderTraversal(tree1);    
 
} 
/*Sample output:

Enter Infix Expression: (9+8)*9(1-2)                                                                                             
                                                                                                                                 
Pre Order Traversal: *9-12                                                                                                       
                                                                                                                                 
In Order Traversal: 9*1-2                                                                                                        
                                                                                                                                 
Post Order Traversal: 912-*  
*/
