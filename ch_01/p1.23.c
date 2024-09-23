//Remove Comments

#include<stdio.h>

int main()
{
    int c, d, e, temp;

    while((c = getchar()) != EOF) {             /*fuawf eoifmewfmjwefm*/
        if(c == '"' || c == '\''){
            putchar(c);
            while((d = getchar()) != c )        //Didnot add check for ignoring escape sequence " \" " test case
                putchar(d);        
        }
        else if(c == '/'){
            if((d = getchar()) == '*') 
                while(temp != d &&(e = getchar()) != c )
                    ;       
            else 
                putchar(c);
        }  
        else 
            putchar(c);
    temp = c;
    }
    return 0;
}