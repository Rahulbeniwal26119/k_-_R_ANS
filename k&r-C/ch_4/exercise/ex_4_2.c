#include <stdio.h>
#include <ctype.h>
double atof(char s[])
{
    int i;
    int exp_sign;
    int exp_power = 0;
    double val = 0.0, power=0;
    int sign;
    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (sign == '-' || sign == '+')
        i++;
    for (; isdigit(s[i]); i++)
    {
        val = val * 10 + s[i] - '0';
    }
    if (s[i] == '.')
    {
        ++i;
        for (power = 0.0; s[i] != 'e' && s[i] != 'E' && s[i] != '\0'; i++)
        {
            val = val * 10 + s[i] - '0';
            power+=1;
        }
        if (s[i] == '\0')
        {
            while (power-- != 0)
                val /= 10.0;
            return sign * val;
        }
        if (s[i] == 'e' || s[i] == 'E')
        {
            ++i;
            exp_sign = (s[i] == '+') ? 1 : -1;
            ++i;
            while (s[i])
            {
                exp_power = exp_power * 10 + s[i++] - '0';
            }
            power = exp_sign * exp_power - power;
            if (power == 0)
                return val;
            else if (power > 0)
            {
                while (power-- != 0)
                    val *= 10;
                return val;
            }
            else
            {
                while (power++ != 0)
                    val /= 10.0;
                return val;
            }
        }
        else if (s[i] == '\0')
        {
            while (power-- != 0)
                val /= 10.0;
            return val;
        }
    }
    else if (s[i] == '\0')
    {
        return sign * val;
    }
}
int main()
{
    char s[] = "123.555545E+2";
    printf("%g", atof(s));
}