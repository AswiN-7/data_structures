Stack* createStack(unsigned capacity)
 { 
   Stack* stack=(Stack*)malloc(sizeof(Stack));
   stack->top=-1;
   stack->capacity=capacity;
   stack->array=(int*)malloc(sizeof(int)*capacity);
   return stack;
   
 }
int isEmpty(Stack* stack)
{
 return stack->top==-1;
}
int isFull(Stack* stack)
{
  return stack->top==stack->capacity;
}
char peek(Stack* stack)
{
 return stack->array[stack->top];
}
char pop(Stack* stack)
{
 if(!isEmpty(stack))
      return stack->array[stack->top--];
 
}
void push(Stack *stack,char op)
{
  if(!isFull(stack))
   stack->array[++stack->top]=op;
 
}
int isOperand(char ch)
{
  return isdigit(ch);
}
int precedence(char ch)
{
 switch (ch)
 {
  case '+':
  case  '-':
               return 1;
  case '/':
  case '*':
             return 2;
   case '^':
             return 3;
   
 }
 return -1;
}

char* infixtopost(char*exp)
{
  char* postfix;
  postfix=(char*)malloc(sizeof(exp));
  int i,k;
 Stack*stack=createStack(strlen(exp));
 for(i=0,k=-1;exp[i];i++)
 {
   if(isOperand(exp[i]))
   postfix[++k]=exp[i];
  else if(exp[i]=='(')
    push(stack,exp[i]);
  else if(exp[i]==')')
    {
      while(!isEmpty(stack)&&peek(stack)!='(')
       postfix[++k]=pop(stack);
      if(isEmpty(stack)||peek(stack)!='(')
         {
       return NULL;
        }    
     else 
        pop(stack);
    }
   else
   {
    while(!isEmpty(stack)&&precedence(exp[i])<=precedence(peek(stack)))
              postfix[++k]=pop(stack);
  push(stack,exp[i]);
   }
  
 }
 while(!isEmpty(stack))
   {
       char temp;
           temp=pop(stack);
             if(temp=='('||temp==')') 
                 return NULL;  
     postfix[++k]=temp;
    
    }
postfix[++k]='\0';
return postfix;
   
}
 
