typedef struct Stack{
 int top;
 int capacity;
 int* array;
}Stack;




Stack* createStack(unsigned capacity);
int isEmpty(Stack* stack);
int isFull(Stack* stack);
char peek(Stack* stack);
char pop(Stack* stack);
void push(Stack *stack,char op);
int isOperand(char ch);
int precedence(char ch);
char* infixtopost(char*exp);
