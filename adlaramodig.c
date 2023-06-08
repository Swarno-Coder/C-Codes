#include<stdio.h>

int findlargest(int num){
        int r,l;
        l=num%10;
        num=num/10;
    while(num>0){
        r=num%10;
        num=num/10;
        if(r>l) l=r;
    }
    return l;
}

int main(){
    int n,i,a[20],sum=0;
    printf("\nEnter the number of elements you want to compare & add: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("\nEnter element %d: ",i+1);
        scanf("%d",&a[i]);
        a[i]=findlargest(a[i]);
        //printf("\n%d",a[i]);
    }
    for(i=0;i<n;i++){sum+=a[i];}
    printf("\nAddition of the largest digit among the elements is %d",sum);
    return 0;
}