//Decimal to binary wihtout stack
#include <stdio.h>
int find(int decimal_number)
{
    if (decimal_number == 0) 
        return 0; 
    else
        return (decimal_number % 2 + 10 * 
                find(decimal_number / 2));
}
int main()
{
    int decimal_number;
    printf("Enter Decimal Number : ");
    scanf("%d",&decimal_number);
    printf("Binary Equivalent is : %d", find(decimal_number));
    return 0;
}