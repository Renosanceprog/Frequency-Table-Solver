//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void int_range(int *lcb, int *ucb, int i);

int main(){
int R_inp, i_inp, k, f_lowerclass, f_upperclass;
    
    printf("input data range (R): ");
    scanf("%d", &R_inp);

    printf("input data class width (i): ");
    scanf("%d", &i_inp);
    
    printf("input first lower class range: ");
    scanf("%d", &f_lowerclass);

    printf("input first upper class range: ");
    scanf("%d", &f_upperclass);

    k = R_inp / i_inp;

    printf("%d and %d\n", f_lowerclass, f_upperclass);
    for (size_t i = 0; i < k; i++){
        int_range(&f_lowerclass, &f_upperclass, i_inp);
        printf("%d and %d\n", f_lowerclass, f_upperclass);
    }
    
    
    int_range(&f_lowerclass, &f_upperclass, i_inp);
    return 0;
}

void int_range(int *lcb, int *ucb, int i){
    *lcb = *lcb - i;
    *ucb = *ucb - i;
}