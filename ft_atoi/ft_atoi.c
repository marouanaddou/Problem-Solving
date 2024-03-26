
# include <stdio.h>
# include <string.h>
# include <limits.h>

int myAtoi(char* s) 
{
    long long int result = 0;
    int sign = 1;
    int i = 0;
    for (; s[i] == ' ' && s[i] != '\0'; i++);
    if (s[i] == '-')
    {
        sign *= -1;
        i++;
    }
    else if(s[i] == '+')
        i++;
    for (;s[i] != '\0';)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            result = result * 10 + s[i] - 48;
            if (result * sign > INT_MAX)
                return INT_MAX;
            else if (result * sign < INT_MIN)
                return INT_MIN;
            i++;
        }
        else 
            return result * sign;
    }
    return result * sign;
}

int main()
{
    printf("%d",myAtoi("21474836460"));
}