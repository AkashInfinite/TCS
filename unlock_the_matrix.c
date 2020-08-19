#include<stdio.h>
int main(){
    int m,n;
    scanf("%d%d",&m,&n);
    int a[m][n],b[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
        scanf("%d",&a[i][j]);
    }
    if(m==2 || n==2){
        int r;
        scanf("%d",&r);
        int ar[m*n];
        int z=0;
        for(int i=0;i<n;i++)
        ar[z++]=a[0][i];
        for(int j=1;j<m;j++)
        ar[z++]=a[j][n-1];
        for(int k=n-2;k>=0;k--)
        ar[z++]=a[m-1][k];
        for(int l=m-2;l>=1;l--)
        ar[z++]=a[l][0];

        int x[r],y[z],c=0;
        for(int i=0;i<z;i++)
        {
            if(i<r)
            x[i]=ar[i];
            else
            y[c++]=ar[i];
        }
        for(int i=0;i<r;i++)
        y[c++]=x[i];
        c=0;
        /*for(int i=0;i<z;i++)
        printf("%d ",ar[i]);
        */for(int i=0;i<n;i++)
        b[0][i]=y[c++];
        for(int j=1;j<m;j++)
        b[j][n-1]=y[c++];
        for(int k=n-2;k>=0;k--)
        b[m-1][k]=y[c++];
        for(int l=m-2;l>=1;l--)
        b[l][0]=y[c++];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            printf("%d ",b[i][j]);
            printf("\n");
        }
        return 0;
    }
    int level[n];
    int le=(m<n)?m/2:n/2;
    for(int i=0;i<le;i++)
    scanf("%d",&level[i]);
    for(int i=0;i<le;i++){
        int ar[m*n];
        int z=0;
        for(int ii=i;ii<n-i;ii++)
        ar[z++]=a[i][ii];
        for(int j=1+i;j<m-i;j++)
        ar[z++]=a[j][n-1-i];
        for(int k=n-2-i;k>=i;k--)
        ar[z++]=a[m-1-i][k];
        for(int l=m-2-i;l>=i+1;l--)
        ar[z++]=a[l][i];

        /*for(int ak=0;ak<z;ak++)
        printf("%d ",ar[ak]);
        printf("\n");*/
        level[i]=level[i]%z;
        int x[z],y[z],c=0;
        if(i%2==0){
            for(int ii=0;ii<z;ii++)
            {
                if(ii<level[i])
                x[ii]=ar[ii];
                else
                y[c++]=ar[ii];
            }
            for(int ii=0;ii<level[i];ii++)
            y[c++]=x[ii];
            c=0;
        }
        else{
            for(int ii=0;ii<z;ii++)
            {
                if(ii<z-level[i])
                x[ii]=ar[ii];
                else
                y[c++]=ar[ii];
            }
            for(int ii=0;ii<z-level[i];ii++)
            y[c++]=x[ii];
            c=0;
        }
        for(int ii=i;ii<n-i;ii++)
        b[i][ii]=y[c++];
        for(int j=i+1;j<m-i;j++)
        b[j][n-1-i]=y[c++];
        for(int k=n-2-i;k>=i;k--)
        b[m-1-i][k]=y[c++];
        for(int l=m-2-i;l>=1+i;l--)
        b[l][i]=y[c++];
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        printf("%d ",b[i][j]);
        printf("\n");
    }
}