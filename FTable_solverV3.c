// Output formatting cleaned up by ai
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// --- ANSI Color Codes ---
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_RED     "\x1b[31m"
#define COLOR_RESET   "\x1b[0m"

// --- Table Design Constants ---
#define COLUMN_WIDTH 17
#define NUM_COLUMNS  8

/**
 * @brief Prints a table border line using universal ASCII characters.
 * @param left The left-most character (e.g., "+")
 * @param mid The middle-divider character (e.g., "+")
 * @param right The right-most character (e.g., "+")
 */
void printBorder(const char* left, const char* mid, const char* right) {
    printf(COLOR_YELLOW "%s", left); // The color might still work
    for (int i = 0; i < NUM_COLUMNS; i++) {
        // Print the horizontal line
        for (int j = 0; j < COLUMN_WIDTH; j++) {
            printf("-"); // Use simple dash
        }
        // Print the divider or the end
        if (i < NUM_COLUMNS - 1) {
            printf("%s", mid);
        } else {
            printf("%s\n", right);
        }
    }
    printf(COLOR_RESET); // Reset color
}


int main(){
// --- Input Variables ---
int R_inp, i_inp, f_lowerclass, f_upperclass, frequencies[100], freq_count = 0;
char inputBuffer[512];
const char *delimiter = " \n\t";

// --- Calculated Variables ---
int current_lci, current_uci, less_CF=0, great_CF=0, N_total, sum_fx=0, biggest_f;
float x_midpoint, current_lcb, current_ucb, mean, median_value, median=0, mode=0;
double relative_F;

// --- Output String Buffers ---
char out_ci[30], out_f[30], out_x[30], out_cb[30], out_lcf[30], out_gcf[30], out_rf[30], out_perc[30];

//=====================================================================
// 1. GET USER INPUT
//=====================================================================
    printf(COLOR_CYAN "input data range (R): " COLOR_RESET);
    scanf(" %d", &R_inp);

    printf(COLOR_CYAN "input data class width (i): " COLOR_RESET);
    scanf(" %d", &i_inp);
    
    printf(COLOR_CYAN "input first lower class range: " COLOR_RESET);
    scanf(" %d", &f_lowerclass);

    printf(COLOR_CYAN "input first upper class range: " COLOR_RESET);
    scanf(" %d", &f_upperclass);

    // Clear the input buffer before fgets
    while (getchar() != '\n'); 
    
    printf(COLOR_CYAN "Enter your list of frequencies (e.g., 4 4 19 7 2 1): " COLOR_RESET);
    fgets(inputBuffer, sizeof(inputBuffer), stdin);
    
    // Splits the frequency inputs to individual values
    char *token = strtok(inputBuffer, delimiter);
    while (token != NULL) {
        frequencies[freq_count] = atoi(token);
        freq_count++;
        token = strtok(NULL, delimiter);
    }
    
//=====================================================================
// 2. PRINT TABLE HEADER & FIRST ROW
//=====================================================================
    printf("\n\n"); // Add space before the table
    printBorder("+", "+", "+"); // Top border
    
    // Table Headers
    printf(COLOR_YELLOW "| %-*s", COLUMN_WIDTH - 1, "CLASS INTERVAL");
    printf("| %-*s", COLUMN_WIDTH - 1, "F");
    printf("| %-*s", COLUMN_WIDTH - 1, "X");
    printf("| %-*s", COLUMN_WIDTH - 1, "CLASS BOUNDARY");
    printf("| %-*s", COLUMN_WIDTH - 1, "<CF");
    printf("| %-*s", COLUMN_WIDTH - 1, ">CF");
    printf("| %-*s", COLUMN_WIDTH - 1, "RF");
    printf("| %-*s|\n" COLOR_RESET, COLUMN_WIDTH - 1, "%");
    
    printBorder("+", "+", "+"); // Mid border

    // --- Calculate and Print First Row (Special Case) ---
    
    // Class Interval
    sprintf(out_ci, "%d - %d", f_lowerclass, f_upperclass);
    printf("| %-*s", COLUMN_WIDTH-1, out_ci);
    
    // Frequency
    sprintf(out_f, "%d", frequencies[0]);
    printf("| %-*s", COLUMN_WIDTH-1, out_f);

    // X (Midpoint)
    current_lci = f_lowerclass;
    current_uci = f_upperclass;
    x_midpoint = (current_lci+current_uci) / 2.0;
    sprintf(out_x,"%.1f", x_midpoint);
    printf("| %-*s", COLUMN_WIDTH-1, out_x);

    // Class Boundary
    current_lcb = current_lci - 0.5;
    current_ucb = current_uci + 0.5;
    sprintf(out_cb, "%.1f - %.1f", current_lcb, current_ucb);
    printf("| %-*s", COLUMN_WIDTH-1, out_cb);

    // <CF (Calculate total N first)
    for (int i = 0; i < freq_count; i++){
        less_CF = less_CF + frequencies[i];
    }
    N_total = less_CF; // Total N
    sprintf(out_lcf, "%d", less_CF);
    printf("| %-*s", COLUMN_WIDTH-1, out_lcf);

    // >CF
    great_CF = frequencies[0];
    sprintf(out_gcf, "%d", great_CF);
    printf("| %-*s", COLUMN_WIDTH-1, out_gcf);

    // RF
    relative_F = frequencies[0] / (float)N_total;
    sprintf(out_rf, "%.2f", relative_F);
    printf("| %-*s", COLUMN_WIDTH-1, out_rf);

    // Percentage
    sprintf(out_perc, "%.0f%%", relative_F*100); // Added % sign
    printf("| %-*s|\n", COLUMN_WIDTH-1, out_perc);
    
    // --- Initial calculations for central tendencies ---
    sum_fx = frequencies[0]*x_midpoint;
    median_value = N_total / 2.0;

    // Find biggest frequency for mode
    biggest_f = frequencies[0];
    for (size_t i = 1; i < freq_count; i++) {
        if (frequencies[i] > biggest_f){
            biggest_f = frequencies[i];
        }
    }
    
//=====================================================================
// 3. PRINT & CALCULATE REMAINING ROWS
//=====================================================================

    for (size_t i = 1; i < freq_count; i++){
        printBorder("+", "+", "+"); // Mid border

        // Class Interval
        current_lci = current_lci - i_inp;
        current_uci = current_uci - i_inp;
        sprintf(out_ci, "%d - %d", current_lci, current_uci);
        printf("| %-*s", COLUMN_WIDTH-1, out_ci);

        // Frequency
        sprintf(out_f, "%d", frequencies[i]);
        printf("| %-*s", COLUMN_WIDTH-1, out_f);

        // X (Midpoint)
        x_midpoint = (current_lci+current_uci) / 2.0;
        sprintf(out_x, "%.1f", x_midpoint);
        printf("| %-*s", COLUMN_WIDTH-1, out_x);

        // Class Boundary
        current_lcb = current_lci - 0.5;
        current_ucb = current_uci + 0.5;
        sprintf(out_cb, "%.1f - %.1f", current_lcb, current_ucb);
        printf("| %-*s", COLUMN_WIDTH-1, out_cb);

        // <CF (Descending)
        less_CF = less_CF - frequencies[i-1];
        sprintf(out_lcf, "%d", less_CF);
        printf("| %-*s", COLUMN_WIDTH-1, out_lcf);

        // >CF (Ascending)
        great_CF = great_CF + frequencies[i];
        sprintf(out_gcf, "%d", great_CF);
        printf("| %-*s", COLUMN_WIDTH-1, out_gcf);

        // RF
        relative_F = frequencies[i] / (float)N_total;
        sprintf(out_rf, "%.2f", relative_F);
        printf("| %-*s", COLUMN_WIDTH-1, out_rf);

        // Percentage
        sprintf(out_perc, "%.0f%%", relative_F*100); // Added % sign
        printf("| %-*s|\n", COLUMN_WIDTH-1, out_perc);

        //--- Central Tendencies Calculation (during the loop) ---
        
        // MEAN (Sum of f*X)
        sum_fx = sum_fx + (frequencies[i]*x_midpoint);

        // MEDIAN (Your original logic)
        if (median_value < less_CF){
            median = current_lcb+(((median_value-(less_CF - frequencies[i]))/(frequencies[i]))*i_inp);
        }

        // MODE (Check for biggest f)
        if (biggest_f == frequencies[i]){
            // Ensure we don't go out of bounds
            int f_before = (i == 0) ? 0 : frequencies[i-1];
            int f_after = (i == freq_count - 1) ? 0 : frequencies[i+1];
            
            mode = current_lcb+((float)(frequencies[i]-f_after)/((2*frequencies[i])-f_after-f_before))*i_inp;
        }
    }
    
    printBorder("+", "+", "+"); // Bottom border

//=====================================================================
// 4. PRINT FINAL RESULTS
//=====================================================================
    printf(COLOR_GREEN "\n--- SUMMARY ---\n");
    printf("Classes (k) = %d\n", freq_count); // Fixed to show correct count
    printf("Total Freq (N) = %d\n", N_total);

    printf(COLOR_GREEN "\n--- CENTRAL TENDENCIES ---\n");
    printf(COLOR_YELLOW "Mean:   " COLOR_RESET "%.2f\n", sum_fx/(float)N_total);
    printf(COLOR_YELLOW "Median: " COLOR_RESET "%.2f\n", median);
    printf(COLOR_YELLOW "Mode:   " COLOR_RESET "%.2f\n", mode);
    
    return 0;
}