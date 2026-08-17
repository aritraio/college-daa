#include <stdio.h>
#include <string.h>

void trim(char *s)
{
    s[strcspn(s, "\r\n")] = '\0';
}

int main()
{
    char pattern[1000];
    fgets(pattern, sizeof(pattern), stdin);
    trim(pattern);
    int m = strlen(pattern);
    int lps[1000];
    lps[0] = 0;
    int len = 0, i = 1;
    while (i < m)
    {
        if (pattern[i] == pattern[len])
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
    printf("LPS:");
    for (i = 0; i < m; i++)
        printf(" %d", lps[i]);
    printf("\n");
    return 0;
}
