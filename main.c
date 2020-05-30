#include<stdio.h>
int minArr(int arr[],int size){
    int minElement = arr[0],c;

    for (c = 1; c < size; c++)
    {
        if (arr[c] < minElement)
        {
           minElement = arr[c];
        }
    }
    return minElement;
}
int minTwoElement(int a,int b){
    int min=a;
    if (a>b){
        min = b;
    }
    return min;
}
int maxTwoElement(int a,int b){
    int max = a;
    if(a<b){
        max = b;
    }
    return max;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        //printf("i'm here\n");
        
        int N,M,i,j;
        char temp;       
        scanf("%d%c%d",&N,&temp,&M);
        int itemsPrice[N][M],discountPrice[N][M];
        for(i=0;i<N;i++){
            for(j=0;j<M;j++){
                scanf("%d%c",&itemsPrice[i][j],&temp);
            }
        }
        for(i=0;i<N;i++){
            for(j=0;j<M;j++){
                scanf("%d%c",&discountPrice[i][j],&temp);
            }
        }
        
        int minPrev,dp;
        for(i=1;i<N;i++){
            minPrev = minArr(itemsPrice[i-1],sizeof(itemsPrice[i-1])/sizeof(itemsPrice[i-1][0]));
            for(j=0;j<M;j++){
                dp = maxTwoElement(0,itemsPrice[i][j]-discountPrice[i-1][j]);
                itemsPrice[i][j] = minTwoElement(itemsPrice[i-1][j]+dp , itemsPrice[i][j]+minPrev);
            }
        }
        printf("%d",minArr(itemsPrice[N-1],sizeof(itemsPrice[N-1])/sizeof(itemsPrice[N-1][0])));


    }
}