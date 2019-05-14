#include "mvec.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

void print_number(int num, size_t i) {
    printf("int[%lu]: %d\n", i, num);
}

void fill_in(MVECP_TYPE(int) numbers) {
   for(int i = 0; i < SIZE; i++) {
        MVECP_PUSH(numbers, i + 10);
    }
}

void fill_in_double(MVECP_TYPE(double) numbers)
{
    for(double i = 0; i < (double) SIZE; i++) {
        MVECP_PUSH(numbers, i + 10);
    }
}

int main(void) {
    MVEC_TYPE(int) numbers;
    MVEC_TYPE(double) dnums;
    MVEC_TYPE(char*) strs;
    
    MVEC_INIT(numbers);
    MVEC_INIT(dnums);
    MVEC_INIT(strs);

    MVEC_PUSH(strs, "Ahoj");
    MVEC_PUSH(strs, "svet");
    MVEC_PUSH(strs, "ako");
    MVEC_PUSH(strs, "sa");
    MVEC_PUSH(strs, "mas!");

    fill_in(&numbers);
    fill_in_double(&dnums);    

    MVEC_EACH_FUNC(numbers, print_number);
    printf("------\n");

    MVEC_EACH(int, numbers, number, {
        printf("This is proc: %d\n", *number);
    });

    puts("------");

    for(int i = 0; i < (int) MVEC_SIZE(dnums); i++ ) {
        printf( "double: %d : %06.2lf\n",i , MVEC_GET(dnums, i));
    }

    printf("------\n");


    for(int i = 0; i < (int) MVEC_SIZE(strs); i++ ) {
        printf( "string: %d : %s\n",i , MVEC_GET(strs, i));
    }

    MVEC_FREE(numbers);
    MVEC_FREE(dnums);
    MVEC_FREE(strs);

    return 0;
}
