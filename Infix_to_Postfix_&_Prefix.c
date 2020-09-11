#include <stdio.h>
#include <ctype.h>

#define SIZE 50            

char stack[SIZE],infix[SIZE],infix1[SIZE],postfix1[SIZE],postfix2[SIZE];
int top=-1;       /* Global declarations */
 
push(char elem)
{                       /* Function for PUSH operation */
    stack[++top]=elem;
}
 
char pop()
{                      /* Function for POP operation */
    return(stack[top--]);
}
 
int pr(char symbol)
{                 /* Function for precedence */
    
	if(symbol == '^')/* exponent operator, highest precedence*/
	{
		return(3);
	}
	else if(symbol == '*' || symbol == '/')
	{
		return(2);
	}
	else if(symbol == '+' || symbol == '-')          /* lowest precedence */
	{
		return(1);
	}
	else
	{
		return(0);
	}
}
void postfix()
{
char postfix[SIZE],ch,elem;
    int i=0,k=0;

    push('#');
    while( (ch=infix[i++]) != '\0')
    {
        if( ch == '(') push(ch);
        else
            if(isalnum(ch)) postfix[k++]=ch;
            else
                if( ch == ')')
                {
                    while( stack[top] != '(')
                        postfix[k++]=pop();
                    elem=pop(); /* Remove ( */
                }
                else
                {       /* Operator */
                    while( pr(stack[top]) >= pr(ch) )
                        postfix[k++]=pop();
                    push(ch);
                }
    }
    while( stack[top] != '#')     /* Pop from stack till empty */
        postfix[k++]=pop();
    postfix[k]='\0';          /* Make postfix as valid string */
    printf("\nPostfix Expression =  %s\n",postfix);

}
void prefix(){
char postfix[SIZE],ch,elem;
    int i=0,k=0;
    strrev(infix);
    //printf("%s",infix);
    push('#');
    while( (ch=infix[i++]) != '\0')
    {
        if( ch == ')') push(ch);
        else
            if(isalnum(ch)) postfix[k++]=ch;
            else
                if( ch == '(')
                {
                    while( stack[top] != ')')
                        postfix[k++]=pop();
                    elem=pop(); /* Remove ( */
                }
                else
                {       /* Operator */
                    while( pr(stack[top]) >= pr(ch) )
                        postfix[k++]=pop();
                    push(ch);
                }
    }
    while( stack[top] != '#')     /* Pop from stack till empty */
        postfix[k++]=pop();
    postfix[k]='\0';          /* Make postfix as valid string */
        strrev(postfix);
    printf("\nPostfix Expression =  %s\n",postfix);


}
/*void postfix_to_prefix()
{
//printf("\nPrefix expression is :- %d\n",&postfix2);
strrev(postfix1);
printf("\nPrefix expression is :- %s\n",postfix1);

}*/
void postfix_to_infix()
{
      int count, length;
      char element, operator;
      length = strlen(postfix1);
      for(count = 0; count < SIZE; count++)
      {
            stack[count] = 0;
      }
      printf("\nInfix expression :");
      printf("%c", postfix1[0]);
      for(count = 1; count < length; count++)
      {
            if(postfix1[count] == '-' || postfix1[count] == '/' || postfix1[count] == '*'|| postfix1[count] == '+')
            {
                  element = pop();
                  operator = postfix1[count];
                  printf(" %c %c", operator, element);
            }
            else
            {
                  push(postfix1[count]);
            }
      }
      //printf("%c", postfix1[top-2]);
}
  /* Main Program */

void main()
{  
	int i,j,sel,k,l;
printf("Enter Infix Expression :- ");
    scanf("%s",infix);
    infix1[j] = infix[i];                   
    postfix();
    prefix();  

 printf("Enter postfix expression :- ");
         scanf("%s",postfix1);
         postfix1[SIZE]=infix1[i];
         postfix_to_infix();
         prefix();
}
