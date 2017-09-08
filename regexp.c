/*
 * C Program to Implements Regular Expression Matching
 */
#include <stdio.h>
#include <string.h>
#define MATCH printf("\nThe Text Matches The Regular Expression");
#define NOTMATCH printf("\nThe Text Doesn't match the Regular Expression");
 
char reg[20], text[20];
 
int main()
{
    int i, rlen, tlen, f = 0;
    char ans;
 
    do {
            printf("\nEnter the Regular Expression\n");    
            scanf(" %[^\n]s", reg);
            for (rlen = 0; reg[rlen] != '\0';rlen++);
            printf("\nEnter the text\n");
            scanf(" %[^\n]s", text);
            for (tlen = 0;text[tlen] != '\0' ; tlen++);
            if (reg[0] == '*')
            {
                printf("\nInvalid regular expression");
            }
            /*
             *If the regular expression starts with Alphabet
             */
            if ((reg[0] >= 65 && reg[0] <= 90) || (reg[0] >= 97 && reg[0] <=122))
            {
                if (reg[0] == text [0])
                {
                    switch (reg[1]) 
                    {
                    case '.' :
                        switch (reg[2])
                        {
                        case '*':
                            if (tlen != 1)
                            {
                                if (reg[3] == text[tlen-1])
                                {
                                    MATCH;
                                }
                                else
                                {
                                    NOTMATCH;
                                }
                            }
                            else
                            {
                                NOTMATCH;
                            }
                            break;
                        case '+':
                            if (text[1] != reg[3])
                            {
                                if (reg[3] == text[tlen - 1])
                                {
                                    MATCH;
                                }
                                else
                                {
                                    NOTMATCH;
                                }
                            }
                            break;
                        case '?':
                            if (text[1] == reg[3] || text[2] == reg[3])
                            {
                                if (text[1] == reg[3] || text[2] == reg[3])
                                {
                                    MATCH;
                                }
                                else
                                {
                                    NOTMATCH;
                                }
                            }
                            else
                            {
                                NOTMATCH;
                            }
                             break;
                            }
                            break;
                        case '*':
                            if (reg[rlen-1] == text[tlen-1])
                            {
                                for (i = 0;i <= tlen-2;i++)
                                {
                                    if(text[i] == reg[0])
                                    {
                                        f = 1;        
                                    }
                                    else 
                                    {
                                        f = 0;
                                    }
                                }
                                if ( f == 1)
                                {
                                    MATCH;
                                }
                                else
                                {
                                    NOTMATCH;
                                }
                            }
                            else
                            {
                                NOTMATCH;
                            }
                            break;
                    case '+' :
                        if (tlen <= 2)
                        {    
                            NOTMATCH;
                        }
                        else if (reg[rlen-1] == text[tlen-1])
                        {
                            for (i = 0;i < tlen-2;i++)
                            {
                                if (text[i] == reg[0])
                                {
                                    f = 1;
                                }
                                else
                                {
                                    f = 0;
                                }
                            }
 
                            if (f == 1)
                            {
                                MATCH;
                            }
                            else 
                            {
                                NOTMATCH;
                            }
                        }
                            break;
                    case '?':
                        if (reg[rlen -1] == text[tlen-1])
                        {
                            MATCH;
                        }
                        else
                        {
                            NOTMATCH;
                        }
                    break;
                } 
 
            }
            else
                printf("Does not match");             
        }
        /*
         *If Regular Expression starts with '^'
         */
        else if (reg[0] == '^')
        {
            if (reg[1] == text[0])
            {
                MATCH;
            }
            else
            {
                NOTMATCH;
            }
        }
        /*
         *If Regular Expression Ends with '$'
         */
        else if (reg[rlen-1] == '$')
        {
            if (reg[rlen-2] == text[rlen-1])
            {
                MATCH;
            }
            else
            { 
                NOTMATCH;
            }
        }
 
        else
            printf("Not Implemented");
        printf("\nDo you want to continue?(Y/N)");
        scanf(" %c", &ans);
    } while (ans == 'Y' || ans == 'y');
}