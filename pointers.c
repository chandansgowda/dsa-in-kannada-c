#include <stdio.h>

void swapWithAddress(int* n1, int* n2)
{
    int temp;
    temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void swapWithoutAddress(int n1, int n2)
{
    int temp;
    temp = n1;
    n1 = n2;
    n2 = temp;
}

int main()
{
    int num1 = 5, num2 = 10;

    // num1 and num2 are passed
    swapWithoutAddress( num1, num2);
    printf("After Swap without Address\n");
    printf("num1 = %d\n", num1);
    printf("num2 = %d\n\n", num2);

    // address of num1 and num2 is passed
    swapWithAddress( &num1, &num2);
    printf("After Swap With Address\n");
    printf("num1 = %d\n", num1);
    printf("num2 = %d", num2);


    return 0;
}

