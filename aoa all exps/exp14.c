#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000 // Maximum length of input strings

void computeLPSArray(char *pattern, int m, int *lps) {
    int len = 0; // Length of the previous longest prefix suffix

    lps[0] = 0; // lps[0] is always 0

    int i = 1;
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPStringMatch(char *text, char *pattern) {
    int m = strlen(pattern);
    int n = strlen(text);

    int *lps = (int *)malloc(sizeof(int) * m);
    if (lps == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    computeLPSArray(pattern, m, lps);

    int i = 0; // Index for text[]
    int j = 0; // Index for pattern[]

    while (i < n) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }

        if (j == m) {
            printf("Pattern found at index %d\n", i - j);
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    free(lps);
}

int main() {
    char text[MAX_LENGTH];
    char pattern[MAX_LENGTH];

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; // Remove newline character

    printf("Enter pattern: ");
    fgets(pattern, sizeof(pattern), stdin);
    pattern[strcspn(pattern, "\n")] = '\0'; // Remove newline character

    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pattern);
    
    printf("Pattern occurrences:\n");
    KMPStringMatch(text, pattern);

    return 0;
}
