#include <stdio.h>
#include <math.h>
int bin_to_dec(int a[],int x)
{
        int i,sum=0;
        for (i=0;i<x;++i){
                sum += a[i]*pow(2,x-1-i);}
        if (sum) return sum;
        else return -1;
}

int main()
{
        int n,ts=0,i,j;
        printf("Enter amount of money in earth currency: \n");
        scanf("%d",&n);
        int money[14];
        money[0] = n/100;
        n = n%100;
        money[1] = n/50;
        n = n%50;
        money[2] = n/20;
        n = n%20;
        money[3] = n/10;
        n = n%10;
        money[4] = n/5;
        n = n%5;
        money[5] = n/2;
        n = n%2;
        money[6] = n/1;
        for (i=7;i<14;++i){
                ts += money[i-7];
                money[i] = ts;}
        int bin[8][256];
        for (i=0;i<money[0];++i){
                for (j=0;j<8;++j){
                        if (j==1 || j==2 || j==5)
                                bin[j][i] = 1;
                        else
                                bin[j][i] = 0;}}
        for (i=0;i<money[1];++i){
                for (j=0;j<8;++j){
                        if (j==2 || j==3 || j==6)
                                bin[j][i+money[7]] = 1;
                        else
                                bin[j][i+money[7]] = 0;}}
        for (i=0;i<money[2];++i){
                for (j=0;j<8;++j){
                        if (j==3 || j==5)
                               bin[j][i+money[8]] = 1;
                        else
                               bin[j][i+money[8]] = 0;}}
        for (i=0;i<money[3];++i){
                for (j=0;j<8;++j){
                        if (j==4 || j==6)
                                bin[j][i+money[9]] = 1;
                        else
                                bin[j][i+money[9]] = 0;}}
        for (i=0;i<money[4];++i){
                 for (j=0;j<8;++j){
                        if (j==5 || j==7)
                                bin[j][i+money[10]] = 1;
                        else
                                bin[j][i+money[10]] = 0;}}
        for (i=0;i<money[5];++i){
                 for (j=0;j<8;++j){
                        if (j==6)
                                bin[j][i+money[11]] = 1;
                        else
                                bin[j][i+money[11]] = 0;}}
        for (i=0;i<money[6];++i){
                for (j=0;j<8;++j){
                        if (j==7)
                                bin[j][i+money[12]] = 1;
                        else
                                bin[j][i+money[12]] = 0;}}
        int v[8],t,c=0;
        for (i=0;i<8;++i){
                v[i] = bin_to_dec(bin[i],money[13]);
                if (v[i] == -1)
                       c++;}
       for (i=0;i<8;++i){
               for (j=0;j<7-i;++j){
                       if (v[j+1]>v[j]){
                                t = v[j];
                                v[j] = v[j+1];
                                v[j+1] = t;}}}
       for (i=0;i<8-c;++i)
               printf("%d ",v[i]);
       printf("\n");
       return 0;
 }