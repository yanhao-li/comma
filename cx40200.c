#include <stdio.h>
#include <ctype.h>
#include <math.h>

double atof(char s[]);

int main()
{
    printf("%.15lf\n", atof("123.45123123123123"));
    printf("%.15lf\n", atof("123.45e-6"));
    printf("%.15lf\n", atof("123.45e6"));
    printf("%.15lf\n", atof("123.45e+6"));
    printf("%.15lf\n", atof("-123.45e-6"));
    return 0;
}

double atof(char s[])
{
    double val, power, expo;
    int i, sign, exposign;

    // skip white spaces
    for (i = 0; isspace(s[i]); i++)
        ;

    // get the sign
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = val * 10.0 + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = val * 10.0 + (s[i] - '0');
        power *= 10;
    }

    if (s[i] == 'e' || s[i] == 'E')
        i++;

    exposign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;

    for (expo = 0.0; isdigit(s[i]); i++)
        expo = expo * 10.0 + (s[i] - '0');

    printf("%lf\n", expo);

    return (sign * val / power) * pow(10, exposign * expo); 
}
