#include<stdio.h>
#include<math.h>
int main()
    {
    int n;
    printf("n= ");
    scanf("%d",&n);
    if(n<1 || n>=256){
        printf("Enter a number less than 2^8 and greater than or equal to 1");
    }

    if(n>=1 && n<256){ // condition
    int count=0;
    int array[100];

    while(n>=100){      // breaking down n into least possible number of earth coins and storing it in an array
    
        n=n-100;
        array[count]=100;
        count=count+1;
    }
      
    while(n<100 && n>=50){
        n=n-50;
        array[count]=50;
        count=count+1;
    }


    while(n<50 && n>=20){
        n=n-20;
        array[count]=20;
        count=count+1;
    }

    while(n<20 && n>=10){
        n=n-10;
        array[count]=10;
        count=count+1;
    }


    while(n<10 && n>=5){
        n=n-5;
        array[count]=5;
        count=count+1;
    }

    
     while(n<5 && n>=2){
        n=n-2;
        array[count]=2;
        count=count+1;
        }
    
    
    while(n<2 && n>=1){
        n=n-1;
        array[count]=1;
        count=count+1;
        }
    int array2[8][100];
        for(int i=0;i<count;i=i+1){   // converting the stored numbers into 8 bit binary numbers column wise
            for(int j=7;j>=0;j=j-1){
                    array2[j][i]=0;
                    array2[j][i]=array[i]%2;
                    array[i]=array[i]/2;
                }

            }
        int binary,m;
        int array3[100];
        int count3=0;
     for(int k=0;k<8;k=k+1){  // converting the binary numbers into decimal form row wise
         binary=0;
         m=0;
         int count2=0;
         for(int e=count-1;e>=0;e=e-1){
             m=pow(2,count2);
             binary=binary+(array2[k][e]*m);
             count2=count2+1;
         }
         if(binary!=0){
             array3[count3]=binary;
              count3=count3+1;
         }
     }
     int t;
     for(int w=0;w<count3;w=w+1){     // displaying it in decreasing form
         for(int x=w+1;x<count3;x=x+1){
             if(array3[w]<array3[x]){
                 t=array3[w];
                 array3[w]=array3[x];
                 array3[x]=t;
             }
         }
     }
    for(int a=0;a<count3;a=a+1){
        printf("%d ",array3[a]);
    }
}

    

    return 0;
}