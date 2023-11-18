#include<stdio.h>
#include<math.h>
int binaryToDecimal(int a)
{
    int temp=a, c=0;
    int dec=0;
    while(a!=0)
    {
        dec = dec+((int)(pow(2, c)))*(a%10);
        a=a/10;  
        c++;
    }
    return dec;
}
void decimalToBinary(int d, int bA[8]) {
    int i = 7;
    while(d>0&&i>=0)
    {
        bA[i]=d%2;
        d=d/2;
        i--;
    }
    while(i>=0)
    {
        bA[i]=0;
        i--;
    }
}//decimal2binary function to fill up the array
int main()
{
    int n,a,count=0,opd=0;
    int k=99999;
    scanf("%d", &n);
    a = n;
    int viltrumMK[20];
    int least[7];
    least[6]=n/100;
    if(least[6]!=0) n=(n%100);
    least[5]=n/50;
    if(least[5]!=0) n=(n%50);
    least[4]=n/20;
    if(least[4]!= 0) n=(n%20);
    least[3]=n/10;
    if(least[3]!=0) n=(n%10);
    least[2]=n/5;
    if(least[2]!=0) n=(n%5);
    least[1]=n/2;
    if(least[1]!=0) n=(n%2);
    least[0]=n/1;//counting least number of earth coins
    for(int i=0;i<7;i++)
    {
        if(least[i]!=0)
        {
            count+=least[i];
        }
    }//calculating count
    for(int i=0;i<7;i++)
    {
        switch(i){
            case 6:
                k=100;
                break;
            case 5:
                k=50;
                break;
            case 4:
                k=20;
                break;
            case 3:
                k=10;
                break;
            case 2:
                k=5;
                break;
            case 1:
                k=2;
                break;
            case 0:
                k=1;
                break;
        }
        if(least[i]!=0){
            viltrumMK[opd]=k;
            if(least[i]>1)
            {
                while(1)
                {
                    least[i]--;
                    opd++;
                    viltrumMK[opd]=k;
                    if (least[i]<=1)
                        break;
                }
            }
            opd++;
        }
    }//filling up the viltrumMK[]
    int HalfViltrumiteProcess[count][8];
    int numBinary[8];//array to contain the binary bits
    for (int i=0; i<count;i++)
    {
        decimalToBinary(viltrumMK[i], numBinary);//filling up the numBinary array
        for (int j=0; j<8;j++){
            HalfViltrumiteProcess[i][j]=numBinary[j];
        }//filling up the HalfViltrumiteProcess[]
    }
    int ViltrumCurrency[8] = {0};
    int vC=0;
    for(int j=0; j<8;j++)
    {
        for(int i=count-1;i>=0;i--)
        {
            ViltrumCurrency[vC] =10*ViltrumCurrency[vC]+HalfViltrumiteProcess[i][j];
        }
        vC++;
    }
    for(int i=0;i<8;i++)
    {
        ViltrumCurrency[i] = binaryToDecimal(ViltrumCurrency[i]);
    }
    int key;
    for(int i=1;i<8;i++)
    {
        key=ViltrumCurrency[i];
        k=i-1;
        while(ViltrumCurrency[k]>key && k>=0)
        {
            ViltrumCurrency[k+1]=ViltrumCurrency[k];
            k--;
        }
        ViltrumCurrency[k+1]=key;
    }
    for(int i=7;i>=0;i--)
    {
        if(ViltrumCurrency[i]!=0)
        printf("%d ", ViltrumCurrency[i]);
    }
    return 0;
}