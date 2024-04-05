

# include <stdio.h>
# include <string.h>
# include <stdlib.h>

char *removeCharacters(char *s, int index, int *length)
{
    char *result = (char *)malloc(*length);
    int j = 0, i = 0;
    for (; i < *length ; i++)
        if (i != index && i != index + 1)
            result[j++] = s[i];
    result[j] = '\0';
    free(s); 
    *length -= 2; 
    return result;
}
char* makeGood(char* s) 
{
    int size = strlen(s);
    for (int i = 0 ; s[i] != '\0'; i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z' && s[i] - 32 == s[i + 1]) || (s[i] >= 'A' && s[i] <= 'Z' && s[i] + 32 == s[i + 1]))
        {
            s = removeCharacters(s, i, &size);
            i = -1;
        }
    }
    return s;
}
