#include <stdio.h>
#include <math.h>

int main() {
    int temp=0,n, a = 0, i, j,d=0;
    int ar1[100], ar[100][8], su[8] = {0},fi[6]={0}; // Initialize su array to 0
    printf("Enter the number: \n");
    scanf("%d", &n);

    while (n != 0) {
         if(n>=100)
        {
            n=n-100;
            ar1[a]=100;
            a++;
        }
        if(n<100 && n>=50)
        {
            n=n-50;
            ar1[a]=50;
            a++;
        }
        if(n<50 && n>=20)
        {
            n=n-20;
            ar1[a]=20;
            a++;
        }
        if(n<20 && n>=10)
        {
            n=n-10;
            ar1[a]=10;
            a++;
        }
        if(n<10 && n>=5)
        {
            n=n-5;
            ar1[a]=5;
            a++;
        }
        if(n<5 && n>=2)
        {
            n=n-2;
            ar1[a]=2;
            a++;
        }
        if(n<2 && n>=1)
        {
            n=n-1;
            ar1[a]=1;
            a++;
        }// your existing code for breaking down the number
    }

    for (i = 0; i < a; i++) {
        // Loop to convert decimal to binary
        for (j = 7; j >= 0; j--) {
            ar[i][j] = ar1[i] % 2;
            ar1[i] /= 2;
        }
    }

    for (j = 0; j < 8; j++) {
        for (i = 0; i < a; i++) {
            su[j] = su[j] + (ar[i][j] * pow(2, a - 1 - i));
        }
        printf("%03d ", su[j]);  // Print with leading zeros and fixed width
    }
     for (i = 0; i < 8 - 1; i++)
      {
        for (j = 0; j < 8- i - 1; j++)
         {
            if (su[j] < su[j + 1])
             { temp=su[j];
               su[j]=su[j+1];
               su[j+1]=temp;
             }
         }
      }         
    for(i = 0; i < 8; i++)
{
    if(su[i] != 0)
        printf("%d ", su[i]);
}
    return 0;
}
