#include <stdio.h>
#include <math.h>

int deci_bin(int x);

void main()
{
    int earth_currency[7]={100,50,20,10,5,2,1};

    int n; 
    input:
    printf("Enter the value of sum of money in earth's denomination in range [1,256): ");
    scanf(" %d",&n);

    if (n>=256)
    {
        printf("Wrong input: Please enter a correct value.\n");
        goto input;
    }
    else
    {

        int earth_coins[(int) pow(2,8)];
        int rem; //While loop condition checker
        rem=n;
        int ind_ec=0,ind_c=0;

        //Finding least number of coins for sum of money.
        while (rem)
        {
            if (rem>=earth_currency[ind_ec])
            {
                rem-=earth_currency[ind_ec];
                earth_coins[ind_c]=earth_currency[ind_ec];  
                ind_c++;
            }
            else
                ind_ec++;
        }

        //dry run for earth_coins array
        /*
        int i;
        for (i=0;i<ind_c;i++)
        {
            printf("%d ",earth_coins[i]);
        }
        */
    
        //converting int binary equivalent
        int i,j;
        int viltrum_coins[8][ind_c];
        int bin[8];
        int num,d;
        
        for (i=0;i<8;i++)
        {
            for (j=0;j<ind_c;j++)
                viltrum_coins[i][j]=0;
        }
        /*
        for (i=0;i<8;i++)
        {
            for (j=0;j<ind_c;j++)
                printf("%d ",viltrum_coins[i][j]);
            printf("\n");
        }
        */
        
        //printf("\n%d\n",num);
        for (j=0;j<ind_c;j++)
        {
            num=deci_bin(earth_coins[j]);
            for (i=7;i>=0;i--)
            {
                if (num)
                {
                    d=num%10;
                    num/=10;
                    //printf("\t%d\n",d);
                        if(d>0)
                            viltrum_coins[i][j]=d;
                }
            }
        }

        printf("The binary equivalent of least number of earth coins are: \n");
        for (i=0;i<8;i++)
        {
            for (j=0;j<ind_c;j++)
                printf("%d ",viltrum_coins[i][j]);
            printf("\n");
        }    

        // deci_bin(earth_coins[0]);
        /*
        int t;
        int i;
        for (i=0;i<8;i++)
        {
            bin[i]=deci_bin(earth_coins[0]);
            printf("\t%d ",bin[i]);
        }
        t=deci_bin(earth_coins[0]); 
        printf("\n%d",t);   
        */
    /*
        int t;
        t=deci_bin(earth_coins[0]);
        */
        
        int viltrum_currency[8];
        for (j=0;j<8;j++)
        {
            int sum=0;
            int b=(int) pow(2,ind_c-1);
            for (i=0;i<ind_c;i++)
            {
                sum+=viltrum_coins[j][i]*b;
                b/=2;
            }
            //printf("\n%d",sum);
            viltrum_currency[j]=sum;
        }
        
        /*
        for (i=0;i<8;i++)
        {
            printf("%d ",viltrum_currency[i]);
        }
        */

        //sorting(desc)
        for (i=0;i<8;i++)
        {
            for (j=i+1;j<8;j++)
            {
                if (viltrum_currency[i]<=viltrum_currency[j])
                {
                    viltrum_currency[i]=viltrum_currency[i]+viltrum_currency[j];
                    viltrum_currency[j]=viltrum_currency[i]-viltrum_currency[j];
                    viltrum_currency[i]=viltrum_currency[i]-viltrum_currency[j];
                }
            }
        }
        /*
        for (i=0;i<8;i++)
        {
            printf("%d ",viltrum_currency[i]);
        }
        */
        printf("\nThe output: \n");
        for (i=0;i<8;i++)
        {
            if (viltrum_currency[i]>0)
                printf("%d ",viltrum_currency[i]);
        }
    }

}

/*
int deci_bin_1(int num)
{
    int bin_num=0;
    int i,r;
    //int bin[8];

    for(i=0;i<8;i++)
    {
        r=num%2;
        num/=2;
        bin_num+=r*((int)pow(10,i));
        //printf("%ld\t",bin_num);
        //bin[i]=r;
    }

    //Dry run 
    
    for (i=0;i<8;i++)
        printf("%d ",bin[i]);
    
    
    printf("%d",bin_num);
    //return bin_num;
}
*/

//useful
int deci_bin(int num)
{
    int i=0;
    int bin_num=0;
    int r;
    int b=1;
    while(num!=0)
    {
        r=num%2;
        //printf("%d\n",r);
        num/=2;
        
        bin_num+=r*b;
        //printf("%d\n",bin_num);
        b*=10;
    }
    //printf("%d\n",bin_num);
    return bin_num;
}

