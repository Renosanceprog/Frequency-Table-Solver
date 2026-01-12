#include <stdio.h>
#include <string.h> // For strtok
#include <stdlib.h> // For atoi

int main() {
    // 1. Create a buffer to hold the user's input line
    char inputBuffer[512];
    
    // 2. Create an array to store the parsed numbers
    int frequencies[100]; // Can hold up to 100 numbers
    int count = 0;        // How many numbers we've found
    
    // 3. Prompt the user and read the whole line
    printf("Enter your list of frequencies (e.g., 4 4 19 7 2 1):\n");
    // fgets is safer than scanf; it reads the entire line, including spaces
    fgets(inputBuffer, sizeof(inputBuffer), stdin);

    // 4. Define your "delimiter" (what separates the numbers)
    const char *delimiter = " \n\t"; // Space, newline, or tab

    // 5. Get the FIRST token
    // strtok finds the first chunk of text before a delimiter
    char *token = strtok(inputBuffer, delimiter);

    // 6. Loop while tokens are being found
    while (token != NULL) {
        // Convert the token (which is text) to an integer
        frequencies[count] = atoi(token);
        count++; // Move to the next spot in our array

        // Get the NEXT token
        // Passing NULL tells strtok to keep searching the *same string*
        token = strtok(NULL, delimiter);
    }

    // --- Verification ---
    // Let's print the numbers to prove they were parsed
    printf("\nSuccess! Parsed %d numbers:\n", count);
    for (int i = 0; i < count; i++) {
        printf("frequencies[%d] = %d\n", i, frequencies[i]);
    }

    int *less_cf=0;
    for (int i = 0; i < count; i++) {
        less_cf = less_cf + frequencies[i];
    }
    
    printf("the total is %d", less_cf);
    return 0;
}