#include <stdio.h>
#include <string.h>

void trim(char *s)
{
    s[strcspn(s, "\r\n")] = '\0';
}

int main()
{
    char text[1000], pattern[1000];
    fgets(text, sizeof(text), stdin);
    fgets(pattern, sizeof(pattern), stdin);
    trim(text);
    trim(pattern);
    int n = strlen(text), m = strlen(pattern);
    int found = 0;
    // Naive string matching: slide pattern over text
    for (int i = 0; i <= n - m; i++)
    {
        int j = 0;
        while (j < m && text[i + j] == pattern[j])
            j++;
        if (j == m)
        {
            printf("Pattern found at index %d\n", i);
            found = 1;
        }
    }
    if (!found)
        printf("not found\n");
    return 0;
}