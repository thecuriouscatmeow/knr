// Rudimentary Syntax Error Checking
// Unbalanced Parenthesis brackets and braces

#include<stdio.h>

int brace, brack, paren;

void in_quote(int c);
void in_comment(void);
void search(int c);

int main()
{
    int c;
    extern int brace, brack, paren;
    // brace = brack = paren = 0;

    while( (c = getchar()) != EOF ) {
        if(c =='/') {
            if( (c = getchar()) == '*' )        //Comment
                in_comment();
            else
                search(c);
        }
        else if(c == '"' || c == '\''){         //Quote
            in_quote(c);       
        }
        else
            search(c);
        //Immediately warn unbalanced closing brace
        if(brace < 0){
            printf("Unbalenced closeing brace");
            brace = 0;
        }
        else if(brack < 0){
            printf("Unbalenced closeing bracket");
            brack = 0;
        }
        else if(paren < 0){
            printf("Unbalenced closeing parenthesis");
            paren = 0;
        }        
    }
    printf("\n%d %d %d\n", brace, brack, paren);
   //Finally warn unbalanced opening brace at end.
    if(brace > 0)
        printf("Unbalenced opening brace");
    else if(brack > 0)
        printf("Unbalenced opening bracket");
    else if(paren > 0)
        printf("Unbalenced opening parenthesis");

return 0;
}

void in_quote(int c)
{
    int d;
    while((d = getchar()) != c )
        if(d == '\\')
            getchar();
        
}

void in_comment(void)
{
    int c,d;

    c = getchar();
    d = getchar();
    while( c != '*' && d != '/' ) {
        c = d;
        d = getchar();
    }
}

void search(int c)
{
    extern int brace, brack, paren;
    if(c =='{')
        ++brace;
    else if(c =='}')
        --brace;
    else if(c =='[')
        ++brack;
    else if(c ==']')
        --brack;
    else if(c =='(')
        ++paren;
    else if(c ==')')
        --paren;
}
