#include<stdio.h>
int n;
int ones_zeros[20][2];
int total=0;
void combinationUtil(int arr[], int data[], int start, int end,
                     int index, int r)
{
    if (index == r)
    {
        int x=0,y=0;
        for (int j=0; j<r; j++){
            x+=ones_zeros[data[j]][0];
            y+=ones_zeros[data[j]][1];
        }
        if(x==y)total++;
        return;
    }
    for (int i=start; i<=end && end-i+1 >= r-index; i++)
    {
        data[index] = arr[i];
        combinationUtil(arr, data, i+1, end, index+1, r);
    }
}
void printCombination(int arr[], int n, int r)
{
    int data[r];
    combinationUtil(arr, data, 0, n-1, 0, r);
}
int main(){
    scanf("%d",&n);
    int a[n];int max=0;
    int b[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(a[i]>max)
        max=a[i];
        b[i]=i;
    }
    int max_digit = 0;
    int binaryNum[32];
    int k=max;
	while (k > 0) {
		binaryNum[max_digit] = k % 2;
		k = k / 2;
		max_digit++;
	}
    for(int j=0;j<n;j++){
        int o=0,z=0;
        int temp=a[j];
        for (int i = max_digit-1; i >= 0; i--) {
            int x = temp >> i;
            if (x & 1)
                o++;
            else
                z++;
        }
        ones_zeros[j][0]=z;
        ones_zeros[j][1]=o;
        if(z==o)total++;
    }
    for(int i=2;i<=n;i++)
    printCombination(b,n,i);
    for (int i = max_digit-1; i >= 0; i--) {
        int x = total >> i;
        (x & 1)?printf("1"):printf("0");
    }
}