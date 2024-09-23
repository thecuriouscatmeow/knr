//entab: Replace blanks with proper number of tabs & blanks 
// error for input "aa                              b"
//but I forgot what combination of space and tab i used here

#include <stdio.h>

#define TABINC 4

int replace(int blanks, int position);

int main(){
    int c, last;
    int nblank = 0;     //Number of blank necessary
    int nt = 0;         //Number of tabs necessary
    int pos = 1;        //position of charecter in line

    while((c = getchar()) != EOF) {
        if(c == ' ') {          //New blank space
            nblank++ ;
            pos++ ;   
        }     
        else if(c == '\n') {    //New Line
            pos = 0;
            putchar(c);
        }
        else {                  //non-space charecter
            if(nblank >0) {
                if(nblank > 1)
                    pos = replace(nblank, pos);
                else
                    putchar(' ');
            putchar(c);
            nblank = 0;
            }
            else {
                putchar(c);
                pos++ ;
            }
        }       
    }
    return 0;
}

int replace(int blanks, int position)
{
    int nb = 0;     //Number of blank necessary
    int nt = 0;     //Number of tabs necessary

    int nexttab = TABINC - (position-1) % TABINC;
    int newpos = position - blanks;

    nb += nexttab;
    blanks -= nexttab;
    nb += blanks % TABINC;
    nt += blanks / TABINC;

    while(nb > 0) {
        putchar(' ');
        nb--;
        newpos++;
    }
    while(nt > 0) {
        putchar('\t');
        nt--;
        newpos++;
    }
    return newpos;    
}


//Alternate Solution
/*
#include <stdio.h>

#define TABINC 4

int main(){
    int c, last;
    int nb = 0;     //Number of blank necessary
    int nt = 0;         //Number of tabs necessary
    int pos = 1;        //position of charecter in line

    for(pos=1 ; (c = getchar()) != EOF ; ++pos) {
        if(c == ' ') {
            if(pos%TABINC != 0)
                ++nb;
            else {
                nb = 0;
                ++nt;
            }
        }
    //print tabs and blanks once new word starts or EOF encountered
        else {
            for( ; nt >0 ; --nt)
                putchar('\t');
            if(c == '\t')
                nb = 0 ;
            else
                for( ; nb >0 ; --nb)
                    putchar(' ');
            putchar(c);
            if(c == '\n')
                pos = 0;
            else if(c == '\t')
                pos = pos + (TABINC - (pos-1) % TABINC);
        }
    }
    return 0;
}
*/


