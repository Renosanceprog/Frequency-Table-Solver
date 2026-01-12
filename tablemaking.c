//
#include <stdio.h>
#define MAXTABLEWIDTH 18
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
void int_range(int *lcb, int *ucb, int i){
    *lcb = *lcb - i;
    *ucb = *ucb - i;
}

int main(){
    int i_inp=3, k=6, f_lowerclass, f_upperclass;

    printf("input first lower class range: ");
    scanf("%d", &f_lowerclass);

    printf("input first upper class range: ");
    scanf("%d", &f_upperclass);

    rowline();
    printf("| %-*s", MAXTABLEWIDTH - 1, "CLASS INTERVAL");
    printf("| %-*s", MAXTABLEWIDTH - 1, "F");
    printf("| %-*s", MAXTABLEWIDTH - 1, "X");
    printf("| %-*s", MAXTABLEWIDTH - 1, "CLASS BOUNDARY");
    printf("| %-*s", MAXTABLEWIDTH - 1, "<CF");
    printf("| %-*s", MAXTABLEWIDTH - 1, ">CF");
    printf("| %-*s", MAXTABLEWIDTH - 1, "RF");
    printf("| %-*s|\n", MAXTABLEWIDTH - 1, "%"); // Note the final "|\n"
    rowline();
    printf("| %-*s", MAXTABLEWIDTH - 1, "%d and %d", f_lowerclass, f_upperclass);
    for (size_t i = 0; i < k; i++){
        int_range(&f_lowerclass, &f_upperclass, i_inp);
        printf("%d and %d\n", f_lowerclass, f_upperclass);
    }

    return 0;
}
