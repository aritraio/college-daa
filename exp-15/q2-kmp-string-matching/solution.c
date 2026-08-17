#include <stdio.h>
#include <string.h>

void trim(char *s)
{
    s[strcspn(s, "\r\n")] = '\0';
}

void computeLPS(char *p, int m, int lps[])
{
    lps[0] = 0;
    int len = 0, i = 1;
    while (i < m)
    {
        if (p[i] == p[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else if (len != 0)
        {
            len = lps[len - 1];
        }
        else
        {
            lps[i] = 0;
            i++;
        }
    }
}

int main()
{
    char text[1000], pattern[1000];
    fgets(text, sizeof(text), stdin);
    fgets(pattern, sizeof(pattern), stdin);
    trim(text);
    trim(pattern);
    int n = strlen(text), m = strlen(pattern);
    int lps[1000];
    computeLPS(pattern, m, lps);
    int i = 0, j = 0, found = 0;
    while (i < n)
    {
        if (pattern[j] == text[i])
        {
            i++;
            j++;
        }
        if (j == m)
        {
            printf("Pattern found at index %d\n", i - j);
            found = 1;
            j = lps[j - 1];
        }
        else if (i < n && pattern[j] != text[i])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    if (!found)
        printf("not found\n");
    return 0;
}
