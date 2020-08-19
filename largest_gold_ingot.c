#include<stdio.h>
int main(){
    long int n;
    scanf("%ld",&n);
    int b,h;
    scanf("%d%d",&b,&h);
    int a[n];
    long long int value=0;
    long long int sum=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    sum=sum*b*h;
    for(int i=0;i<n;i++){
        int k=a[i];
        int z=i;
        long int len=0;
        if(i==0){
            z+=1;
            while(a[z]>=k && z<n)
            z++;
            len=z-1;
        }
        else if(i==n-1){
            z-=1;
            while(a[z]>=k && z>=0)
            z--;
            len=i-z;
        }
        else{
            int left=z-1;
            int right=z+1;
            while(a[left]>=k && left>=0)
            left--;
            while(a[right]>=k && right<n)
            right++;
            len=right-left-1;
        }
        long long int temp=a[i]*len*b;
        if(temp>value)
        value=temp;
    }
    value=(sum-value*h)%1000000007;
    printf("%lld",value);
}