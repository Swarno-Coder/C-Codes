#include<stdio.h>
#include<stdlib.h>

double findarea(float a[],float b[],int n){
    double sum;
    for(int i=0;i<n;i++){
        if(i+1>=n) sum+=(a[i]*b[0] - a[0]*b[i]);
        else sum+=(a[i]*b[i+1] - a[i+1]*b[i]);
    }
    return abs(sum/2);
}

int main(){
    int n,i;
    float x[10],y[10];
    printf("\nEnter the number of points you want to insert to find the area: ");
    scanf("%d",&n);

    printf("Enter points of x and y -->\n");
	for(i=0; i<n; i++)
	{
		printf("\nx%d : ",i+1);
		scanf("%f", &x[i]);
		printf("y%d : ",i+1);
		scanf("%f", &y[i]);
	}

    printf("\nArea between the given points is: %.4lf",findarea(x,y,n));
    return 0;
}