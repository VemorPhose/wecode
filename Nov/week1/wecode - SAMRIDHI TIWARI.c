//name
#include<stdio.h>
#include<math.h>

int decimalToBinary(int n,int num[]) 
{  
    int i=0; 
    if (n == 0)
    {
        printf("0");
        return 0;
    }
   
   
   while(n>0)
   {
      num[i++] = n % 2;
      n /= 2;
   }
      for(int j = 7;j > i-1;j--)
      {
        num[j]=0;
      }
    return 0;
}

int fun(int n,int arr[10])
{
    int i=0;
    while(n>0)
    {
        if(n>=100)
    {
        arr[i++]=100;
        n=n-100;
    }
    

    else if(n>=50 && n<100)
    {
        arr[i++]=50;
        n=n-50;
    }

    else if(n>=20 && n<50)
    {
        arr[i++]=20;
        n=n-20;
    }

    else if(n>=10 && n<20)
    {
        arr[i++]=10;
        n=n-10;
    }

    else if(n>=5 && n<10)
    {
        arr[i++]=5;
        n=n-5;
    }

    else if(n>=2 && n<5)
    {
        arr[i++]=2;
        n=n-2;
    }

    else if(n>=1 && n<2)
    {
        arr[i++]=1;
        n=n-1;
    }
    
    }
    return i;

}

int main()
{
  int n,arr[10],ary[10][10],num[8];
  printf("Enter n:");
  scanf("%d",&n);
  
  if(n<1 || n>=pow(2,8))
  printf("Invalid input");
 
   printf("Processing steps: \n");
   int a=fun(n,arr);
    for(int j=0;j<a;j++)
    {
    printf("%d ",arr[j]);
    
    }
    printf("\n");
    for(int j=0;j<a;j++)
    {
        decimalToBinary(arr[j],num);
      for(int k=0;k<8;k++)
      {
        ary[j][k]=num[k];
      }
    }

    int trans[10][10];
    for(int i=7;i>=0;i--)
    {
        for(int j=0;j<a;j++)
        {
            trans[7-i][j]=ary[j][i];
            printf("%d ",trans[7-i][j]);
        }
        printf("\n");
    }

    int viltnum[8]={0,0,0,0,0,0,0,0};
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<a;j++)
        {
            viltnum[i]=viltnum[i]*2+trans[i][j];
        }
        printf("%d ",viltnum[i]);
    }
    
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<7;j++)
        {
            if(viltnum[j]<viltnum[j+1])
            {
                int temp=viltnum[j];
                viltnum[j]=viltnum[j+1];
                viltnum[j+1]=temp;
            }
        }
    }
    printf("\n");
    printf("Output: \n");
        for(int i=0;i<8;i++)
    {
        if(viltnum[i]!=0)
            printf("%d ",viltnum[i]);
    }
   return 0;
}