//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXTABLEWIDTH 17
void rowline(){
    printf("+");
    for(int i = 0; i < MAXTABLEWIDTH; i++) printf("-");
    printf("+");
    for(int i = 0; i < MAXTABLEWIDTH; i++) printf("-");
    printf("+");
    for(int i = 0; i < MAXTABLEWIDTH; i++) printf("-");
    printf("+");
    for(int i = 0; i < MAXTABLEWIDTH; i++) printf("-");
    printf("+");
    for(int i = 0; i < MAXTABLEWIDTH; i++) printf("-");
    printf("+");
    for(int i = 0; i < MAXTABLEWIDTH; i++) printf("-");
    printf("+");
    for(int i = 0; i < MAXTABLEWIDTH; i++) printf("-");
    printf("+");
    for(int i = 0; i < MAXTABLEWIDTH; i++) printf("-");
    printf("+\n");
}

int main(){
//input variables
int R_inp=17, i_inp=3, f_lowerclass=23, f_upperclass=25, frequencies[100], freq_count = 0;
char inputBuffer[512];
const char *delimiter = " \n\t";
    
    printf("input data range (R): ");
    scanf(" %d", &R_inp);

    printf("input data class width (i): ");
    scanf(" %d", &i_inp);
    
    printf("input first lower class range: ");
    scanf(" %d", &f_lowerclass);

    printf("input first upper class range: ");
    scanf(" %d", &f_upperclass);

    while (getchar() != '\n');
    printf("Enter your list of frequencies (e.g., 4 4 19 7 2 1): ");
    fgets(inputBuffer, sizeof(inputBuffer), stdin);
    
    //splits the frequency inputs to individual values
    char *token = strtok(inputBuffer, delimiter);
    while (token != NULL) {
        frequencies[freq_count] = atoi(token);
        freq_count++;
        token = strtok(NULL, delimiter);
    }
//calculated variables
int k, current_lci, current_uci, less_CF=0, great_CF=0, N_total;
float x_midpoint, current_lcb, current_ucb;
double relative_F;

//output strings
char out_ci[30], out_f[30], out_x[30], out_cb[30], out_lcf[30], out_gcf[30], out_rf[30], out_perc[30];
    
//calculations
    k = R_inp / i_inp; // calculates k
//=====================================================================
// initial values print
//=====================================================================
    // table headers
    rowline();
    printf("| %-*s", MAXTABLEWIDTH - 1, "CLASS INTERVAL");
    printf("| %-*s", MAXTABLEWIDTH - 1, "F");
    printf("| %-*s", MAXTABLEWIDTH - 1, "X");
    printf("| %-*s", MAXTABLEWIDTH - 1, "CLASS BOUNDARY");
    printf("| %-*s", MAXTABLEWIDTH - 1, "<CF");
    printf("| %-*s", MAXTABLEWIDTH - 1, ">CF");
    printf("| %-*s", MAXTABLEWIDTH - 1, "RF");
    printf("| %-*s|\n", MAXTABLEWIDTH - 1, "%");
    rowline();

    sprintf(out_ci, "%d - %d", f_lowerclass, f_upperclass); // prints class interval to string
    printf("| %-*s", MAXTABLEWIDTH-1, out_ci); // prints class interval

    sprintf(out_f, "%d", frequencies[0]); // prints f to string
    printf("| %-*s", MAXTABLEWIDTH-1, out_f); // prints f

    //make sures the original class intervals isn't touched
    current_lci = f_lowerclass;
    current_uci = f_upperclass;

    //calculates x
    x_midpoint = (current_lci+current_uci) / 2.0;
    sprintf(out_x,"%.1f", x_midpoint); // prints to string
    printf("| %-*s", MAXTABLEWIDTH-1, out_x); //prints x

    //calculates class boundary
    current_lcb = current_lci - 0.5;
    current_ucb = current_uci + 0.5;
    sprintf(out_cb, "%.1f - %.1f", current_lcb, current_ucb); // prints to string
    printf("| %-*s", MAXTABLEWIDTH-1, out_cb); //prints class boundary

    //calculates <CF
    for (int i = 0; i < freq_count; i++){
        less_CF = less_CF + frequencies[i];
    }
    sprintf(out_lcf, "%d", less_CF); // prints to string
    printf("| %-*s", MAXTABLEWIDTH-1, out_lcf); //prints <CF

    //calculates >CF
    great_CF = frequencies[0];
    sprintf(out_gcf, "%d", great_CF); // prints to string
    printf("| %-*s", MAXTABLEWIDTH-1, out_gcf); //prints <CF

    //calculates RF
    N_total = less_CF;
    relative_F = frequencies[0] / (float)N_total;
    sprintf(out_rf, "%.2f", relative_F); // prints to string
    printf("| %-*s", MAXTABLEWIDTH-1, out_rf); // prints RF

    sprintf(out_perc, "%.0f", relative_F*100); //calculates percentage inside function and prints to string
    printf("| %-*s|\n", MAXTABLEWIDTH-1, out_perc); // prints percentage
    
    for (size_t i = 1; i <= k; i++){
        rowline();
        //calculates rest of the intervals
        current_lci = current_lci - i_inp;
        current_uci = current_uci - i_inp;
        sprintf(out_ci, "%d - %d", current_lci, current_uci); // prints class interval to string
        printf("| %-*s", MAXTABLEWIDTH-1, out_ci); // prints class interval

        sprintf(out_f, "%d", frequencies[i]); // prints f to string
        printf("| %-*s", MAXTABLEWIDTH-1, out_f); // prints f

        x_midpoint = (current_lci+current_uci) / 2.0; //calculates x
        sprintf(out_x, "%.1f", x_midpoint); //prints x to string
        printf("| %-*s", MAXTABLEWIDTH-1, out_x); //prints x

        //calculates class boundary
        current_lcb = current_lci - 0.5;
        current_ucb = current_uci + 0.5;
        sprintf(out_cb, "%.1f - %.1f", current_lcb, current_ucb); //prints class boundary to string
        printf("| %-*s", MAXTABLEWIDTH-1, out_cb); //prints class boundary

        //calculates <CF
        less_CF = less_CF - frequencies[i-1];
        sprintf(out_lcf, "%d", less_CF); //prints <CF to string
        printf("| %-*s", MAXTABLEWIDTH-1, out_lcf); //prints <CF

        //calculates >CF
        great_CF = great_CF + frequencies[i];
        sprintf(out_gcf, "%d", great_CF); //prints <CF to string
        printf("| %-*s", MAXTABLEWIDTH-1, out_gcf); // prints RF

        relative_F = frequencies[i] / (float)N_total;
        sprintf(out_rf, "%.2f", relative_F); // prints RF to string
        printf("| %-*s", MAXTABLEWIDTH-1, out_rf); // prints RF

        sprintf(out_perc, "%.0f%%", relative_F*100); // prints percentage to string
        printf("| %-*s|\n", MAXTABLEWIDTH-1, out_perc); // prints percentage
    }
    rowline();
    return 0;
}