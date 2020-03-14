#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXVAL 100 /* maxmium depth of val stack */
#define MAXOP 100 /* maxmium operand */
#define NUMBER '0'
#define BUFSIZE 100

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

int sp = 0;
double val[MAXVAL];
char buf[BUFSIZE];
int bufp = 0;

int main()
{
    int type;
    double op2;
    char s[MAXOP];

    while((type = getop(s)) != EOF) {
        printf("\nnext type: %c ", type);
        switch (type) {
            case NUMBER:
                printf(" number: %f\n", atof(s));
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push((int)pop() % (int)op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '\n':
                printf("reading newline\n");
                printf("\n\nresult: \t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }

    return 0;
}

void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
    printf("pushing %f, sp: %d => %d\n", f, sp-1, sp);

    printf("current stack: [");
    for (int i = 0; i < sp; i++) {
        printf("%f ", val[i]);
    }
    printf("]\n");
}

double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

int getop(char s[])
{
    int i, c;
    
    //remove prefix spaces
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';

    if (!isdigit(c) && c != '.' && c != '-') {
        return c; /* not a number */
    }

    i = 0;

    if (c == '-') {
        if ((c = getch()) == ' ') {
            return '-';
        } else {
            ungetch(c);
            while(isdigit(s[++i] = c = getch()))
                ;
        }
    }
        

    if (isdigit(c))
        while(isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);

    return NUMBER;
}

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
