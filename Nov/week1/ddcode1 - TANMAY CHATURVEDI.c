#include <stdio.h>
#include <math.h>
int binaryconvert(int x){
    int i,j;
    for(i=7;i>=0;i--){
        return x%2;
        x/=2;
    }
}

int decimalconvert(int x[], int y){
    int i,j,sum=0;
    for(i=0;i<y;i++){
      sum+=x[i]*(pow(2,y-i-1));
    }
    return sum;
}

int main(){
int n,i,j;
scanf("%d", &n);

int Ecoins[7]={100,50,20,10,5,2,1};

int monay[256]={};
int wow[256][8];
int sum=0;
for(i=0;i<7;i++){
    int count=0;
    count=n/Ecoins[i];
    n=n-(count*Ecoins[i]);
    if(count!=0){
    for(j=0;j<count;j++){
        monay[j+sum]=Ecoins[i];
    }    
}
    sum+=count;
    }
    
for(i=0;i<sum;i++){
    int unga = monay[i];
    
    for(j=7;j>=0;j--){
        wow[j][i]=binaryconvert(unga);
        unga /= 2;
    }
}
int damn[8];

for (i=0; i<8; i++){
    damn[i]=decimalconvert(wow[i], sum);
}

for(i=0;i<7;i++){
    for(j=0;j<7-i;j++){
        if(damn[j+1]>damn[j]){
            int temp = damn[j];
            damn[j]=damn[j+1];
            damn[j+1]=temp;
        }
    }
}

printf("\n");
for(i=0;i<8;i++){
    if(damn[i]){
    printf("%d ", damn[i]);
    }
}

return 0;
}