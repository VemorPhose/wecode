#include<stdio.h>
#include<math.h>
void sort_array(int k,int array[])
{
    //This function is for sorting array
    int temp;
     for (int i = 0; i < k; i++) 
     {     
        for (int j = i+1; j < k; j++) 
        {     
           if(array[i] > array[j])
            {    
               temp = array[i];    
               array[i] = array[j];    
               array[j] = temp;    
            }     
        }     
     }    
    for(int i=k-1;i>=0;i--)
        if(array[i]!=0)
            printf("%d  ",array[i]);
}
void decimalToBinary(int n,int arr[])
{
    //this function is for converting to binary
    int k=8;
    // k is 8 as for mentioning 8 bit number digit 
    int array[n][k];
    int arr2[k];
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<k;j++)
        {
            if(arr[i]>0)
            {
                array[i][j]=arr[i]%2;
                arr[i]=arr[i]/2;
            }
            else
                array[i][j]=0;
        }
    }
    int arr_number[k];
    for(int j=0;j<k;j++)
    {
        arr2[j]=0;
        for(int i=0;i<n;i++)
        {
            arr2[j]+=array[i][j]*pow(2,n-1-i);
        }
    }
   sort_array(k,arr2);
}
int combination(int num)
{
    if(num/100>0)
    {
        return 100;

    }
    if(num/50>0)
    {
        return 50;
    }
    if(num/20>0)
    {
        return 20;
    }
    if(num/10>0)
    {
        return 10;
    }
    if(num/5>0)
    {
        return 5;
    }
    if(num/2>0)
    {
        return 2;
    }
    return 1;
}
void possible_number(int num)
{
    //This is to find the number of possible combination of each currency
    int arr[10];//there can be max of combination of currency because of constrain
    int i;
    for( i=0;i<7;i++)
    {
        arr[i]=combination(num);
        //storing in array which  possible combination  of currency
        num=num-arr[i];
        //printf("%d  ",arr[i]);
        //This is to for possible combination of currency
        if(num==0)
        {
            i++;//If condition is true then increse one 
            break;
        }
    }
     decimalToBinary(i,arr);
}
int main()
{
    //main function
    int num;
    printf("Enter the number to check");
    scanf("%d",&num);
    possible_number(num);
}
   