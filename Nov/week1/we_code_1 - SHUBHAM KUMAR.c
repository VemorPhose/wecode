#include <stdio.h>

int number_of_coins(int total_money){   // count total number of coins
    int m=total_money;
    int coins=0;
     while (m > 0)
    {
        if (m / 100 > 0)
        {
            coins += m / 100;
            m %= 100;
        }
        if (m / 50 > 0)
        {
            coins += m / 50;
            m %= 50;
        }
        if (m / 20 > 0)
        {
            coins += m / 20;
            m %= 20;
        }
        if (m / 10 > 0)
        {
            coins += m / 10;
            m %= 10;
        }
        if (m / 5 > 0)
        {
            coins += m / 5;
            m %= 5;
        }
        if (m / 2)
        {
            coins += m / 2;
            m %= 2;
        }
        if (m > 0)
        {
            coins += m;
            m %= m;
        }
    }
    return coins;
}

int number_to_binary(int number_to_convert) // convert any number to binary
{
    int binary = 0;
    int base = 1;

    while (number_to_convert > 0)
    {
        int remainder = number_to_convert % 2;
        binary += remainder * base;
        base *= 10;
        number_to_convert /= 2;
    }

    return binary;
}

int current_currency(int amount) 
{
    int m = amount;
    if (m / 100 > 0)
        return 100;
    if (m / 50 > 0)
        return 50;
    if (m / 20 > 0)
        return 20;
    if (m / 10 > 0)
        return 10;
    if (m / 5 > 0)
        return 5;
    if (m / 2 > 0)
        return 2;
    return 1;
}

int main()
{
    int total_money;
    printf("Enter total money : ");
    scanf("%d", &total_money);
    int m = 8; // as size of binary must be 8
    int n=number_of_coins(total_money);

    int arr[m][n];

    for (int i = 0; i < m; i++) // make each value of 2-D array equal to zero
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }

    int binary, count = 0;
    int number;
    while (total_money > 0)  // storing binary value of value of coin column wise
    {
        number = current_currency(total_money);
        binary = number_to_binary(number);
        total_money -= number;
        for (int i = m - 1; i >= 0; i--)
        {
            arr[i][count] = binary % 10;
            binary /= 10;
        }
        count++;
    }

    for (int i = 0; i < m; i++)  // printing 2-D array formed
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    int array[8]; // array of numbers formed by row wise values in 2-D array
    int mul_2 = 1;
    number = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            number += arr[i][j] * mul_2;
            mul_2 *= 2;
            array[i] = number;
        }
        number = 0;
        mul_2 = 1;
    }

    for (int i = 1; i < 8; i++)  // bubble sorting descending wise
    {
        for (int j = 0; j < 8 - i; j++)
        {
            if (array[j] < array[j + 1])
            {
                int temp;
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    printf("OUTPUT--");
    for (int i = 0; i < 8; i++)
    {
        if (array[i] != 0)
            printf("%d ", array[i]);
    }
    return 0;
}
