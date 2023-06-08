#include<stdio.h>
void main()
{
	float x[10], y[10];
	float xp, yp=0, temp;
	int i, j, n;
	 
    printf("------------------------------------------------------------------------\n");
	printf("Enter number of records : ");
	scanf("%d", &n);
    printf("------------------------------------------------------------------------\n\n");
	printf("Enter records of x and f(x)\n");
	for(i=0; i<n; i++)
	{
		printf("\nx%d : ",i+1);
		scanf("%f", &x[i]);
		printf("f(x%d) : ",i+1);
		scanf("%f", &y[i]);
	}
    printf("\n------------------------------------------------------------------------");
	printf("\nYou\'ve entered -->\nx:");
	for(i=0;i<n;i++) printf("\t%.2f",x[i]);
	printf("\nf(x):");
	for(i=0;i<n;i++) printf("\t%.2f",y[i]);
		
	printf("\n\nEnter value of x to find f(x) : ");
	scanf("%f", &xp);
	
	//Finding value of yp
	for(i=0; i<n; i++)
	{
		temp = 1.0;
		//Finding value of each wi
		for(j=0; j<n; j++)
		{
			if(i!=j)
			{
				temp = temp * (xp-x[j])/(x[i]-x[j]);
			}
		}
		//Calculating sum of all wi*f(i) 
		yp = yp + temp*y[i];
	}
	 
    printf("------------------------------------------------------------------------");
	printf("\nValue of f(%.1f) is: %.2f", xp, yp);
    printf("\n------------------------------------------------------------------------\n\n");
}