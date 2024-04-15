#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>



int m,n,k,a[20][20];

void recu(int i,int j){
    if(i-1 >=0 && a[i-1][j]==1){
        a[i-1][j]=k;
        recu(i-1,j);
    }

    if(i+1< m && a[i+1][j]==1){
        a[i+1][j]=k;
        recu(i+1,j);

    }

    if(j-1 >=0 && a[i][j-1]==1){
        a[i][j-1]=k;
        recu(i,j+1);
    }

    if(j+1 <n && i+1 < m && a[i+1][j+1] ==1){
        a[i+1][j+1]=k;
        recu(i+1,j+1);
    }

    if(j-1>=0 && i+1<m && a[i+1][j-1]==1){
        a[i+1][j-1]=k;
        recu(i+1,j-1);
    }

    if(j-1>=0 && i-1 > 0 && a[i-1][j-1]==1){
        a[i-1][j-1]=k;
        recu(i-1,j-1);
    }

    if(j+1 <n && i -1 >0 && a[i-1][j+1]==1){
        a[i-1][j+1]=k;
        recu(i-1,j+1);
    }

}

int main(){
    int i,j,*arr;
    int m,n;
    scanf("%d%d",&m,&n);
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }

    k=2;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(a[i][j]==1){
                a[i][j]==k;
                recu(i,j);
                k++;
            }
        }
    }

    arr = (int *)calloc(1,k * sizeof(int));
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){

            if(a[i][j]!=0){
                arr[a[i][j]] ++;
            }
            printf("%d ",a[i][j]);

        }
        printf("\n");
    }

    int max = -1;
    for(i=0;i<k;i++){
        if(max < arr[i]){
            if(max < arr[i])
            max = arr[i];
        }
    }

    free(arr);
    printf("%d\n",max);
    return 0;

}
