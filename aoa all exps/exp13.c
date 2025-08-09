#include <stdio.h>
#include <string.h>

void naiveStringMatch(char *text, char *pattern) {
    int m = strlen(text);
    int n = strlen(pattern);

    for (int i = 0; i <= m - n; i++) {
        int j;
        // Check if pattern matches the substring of text starting at index i
        for (j = 0; j < n; j++) {
            if (text[i + j] != pattern[j])
                break;
        }
        // If the loop ended without breaking, it means pattern matches the substring
        if (j == n)
            printf("Pattern found at index %d\n", i);
    }
}

int main() {
    char text[] = "AABAACAADAABAABA";
    char pattern[] = "AABA";
    
    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pattern);
    
    printf("Pattern occurrences:\n");
    naiveStringMatch(text, pattern);

    return 0;
}
