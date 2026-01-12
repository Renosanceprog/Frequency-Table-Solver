#include <stdio.h>
#include <string.h>

int main() {
    
    // 1. FIND YOUR MAX WIDTHS
    // You MUST calculate these by looping through your data first.
    // These are *examples* based on your headers and common data.
    // I've added space for padding (e.g., "| Column ")
    
    int maxIntervalWidth = 20; // e.g., "10-19"
    int maxFWidth = 20;                     // e.g., "19"
    int maxXWidth = 20;                     // e.g., "14.5"
    int maxBoundaryWidth = 20; // e.g., "9.5 - 19.5"
    int maxLTCFWidth = 20;                // e.g., "37"
    int maxGTCFWidth = 20;                // e.g., "37"
    int maxRFWidth = 20;                   // e.g., "0.51"
    int maxPercentWidth = 20;              // e.g., "51%"

    // --- You MUST update the widths above based on your data! ---
    // Example: if your longest boundary is "19.5 - 29.5" (13 chars),
    // you would set maxBoundaryWidth = 13 + 2;


    // --- PRINT THE HEADER ---

    // 2. Print the top border
    printf("+");
    for(int i = 0; i < maxIntervalWidth; i++) printf("-");
    printf("+");
    for(int i = 0; i < maxFWidth; i++) printf("-");
    printf("+");
    for(int i = 0; i < maxXWidth; i++) printf("-");
    printf("+");
    for(int i = 0; i < maxBoundaryWidth; i++) printf("-");
    printf("+");
    for(int i = 0; i < maxLTCFWidth; i++) printf("-");
    printf("+");
    for(int i = 0; i < maxGTCFWidth; i++) printf("-");
    printf("+");
    for(int i = 0; i < maxRFWidth; i++) printf("-");
    printf("+");
    for(int i = 0; i < maxPercentWidth; i++) printf("-");
    printf("+\n");

    // 3. Print the Header Titles
    // We print a space, then pad to (width - 1)
    printf("| %-*s", maxIntervalWidth - 1, "CLASS INTERVAL");
    printf("| %-*s", maxFWidth - 1, "F");
    printf("| %-*s", maxXWidth - 1, "X");
    printf("| %-*s", maxBoundaryWidth - 1, "CLASS BOUNDARY");
    printf("| %-*s", maxLTCFWidth - 1, "<CF");
    printf("| %-*s", maxGTCFWidth - 1, ">CF");
    printf("| %-*s", maxRFWidth - 1, "RF");
    printf("| %-*s|\n", maxPercentWidth - 1, "%"); // Note the final "|\n"

    // 4. Print the dividing border
    printf("+");
    for(int i = 0; i < maxIntervalWidth; i++) printf("-");
    printf("+");
    for(int i = 0; i < maxFWidth; i++) printf("-");
    printf("+");
    for(int i = 0; i < maxXWidth; i++) printf("-");
    printf("+");
    for(int i = 0; i < maxBoundaryWidth; i++) printf("-");
    printf("+");
    for(int i = 0; i < maxLTCFWidth; i++) printf("-");
    printf("+");
    for(int i = 0; i < maxGTCFWidth; i++) printf("-");
    printf("+");
    for(int i = 0; i < maxRFWidth; i++) printf("-");
    printf("+");
    for(int i = 0; i < maxPercentWidth; i++) printf("-");
    printf("+\n");

    // Now you can loop through your data and print the rows
    // using the same `%-*s` formatters.

    return 0;
}