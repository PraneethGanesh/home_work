#include<stdio.h>
int v[20][20];
int max_val(int a,int b){
    return (a>b?a:b);
}
int main(){
    int i,j,p[20],w[20],max,n;
    printf("Enter the number of items\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        printf("Enter the profit and weight of item %d:",i);
        scanf("%d%d",&p[i],&w[i]);
    }
    printf("Enter the maximun value\n");
    scanf("%d",&max);
    for(i=0;i<=n;i++){
        v[i][0]=0;
    }
    for(i=0;i<=max;i++){
        v[0][i]=0;
    }
    for(i=1;i<=n;i++){
        for(j=0;j<=max;j++)
        {
            if(w[i]>j){
                v[i][j]=v[i-1][j];
            }
            else{
                v[i][j]=max(v[i-1][j],v[i-1][j-w[i]]+p[i]);
            }
        }
    }
    printf("The table is\n");
    for(i=0;i<n;i++){
        for(j=0;j<max;j++){
            printf("%d",v[i][j]);
        }
        printf("\n");
    }
    printf("The maximum profit is %d\n",v[n][max]);
    printf("The possible subset is {\t");
    j=max;
    for(i=n;i>=1;i++){
        if(v[i][j]!=v[i-1][j]){
            printf("item %d:1\t",i);
            j=j-w[i];
        }
        else{
            printf("item %d:0\t",i);
        }
    }
    return 0;
}