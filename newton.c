#include<stdio.h>
void main()
{
	float dt[10][10];
	int i, j, n, fact;
	float x, y, h, u, temp;
    printf("\n------------------------------------------------------------------------\n");
	printf("Enter number of values : ");
	scanf("%d", &n);
	//Input x and y values
	for (i=0; i<n; i++)
	{
		printf("\nEnter x[%d] : ", i+1);
		scanf("%f", &dt[i][0]);
		printf("Enter y[%d] : ", i+1);
		scanf("%f", &dt[i][1]);
	}
	//Difference table
	for(j=2; j<n; j++)
	{
		for(i=0; i<n-1; i++)
			dt[i][j] = dt[i+1][j-1] - dt[i][j-1];
	}
	printf("\n------------------------------------------------------------------------\n");
	//Display 
	printf("\nx\ty=f(x)\td^(1)y\td^(2)y\td^(3)y\td^(4)y\n");	
	for(i=0; i<n; i++)
	{
		for(j=0; j<n+1-i; j++)
		{
			if(dt[i][j]!=0.0)
				printf("%.3f\t", dt[i][j]);
		}
		printf("\n");
	}
    do{
        int choice;
        printf("\n\n------------------------------------------------------------------------\nBy which process you want to find the value of f(x)\n<<1>> Newton\'s Forward Interpolation\n<<2>> Newton\'s Backward Interpolation\n<<3>> Exit\n-->> ");
        scanf("%d",&choice);
        
        if(choice==1){
            printf("\n------------------------------------------------------------------------\n");
            printf("Enter value of x to compute : ");
            scanf("%f", &x);
            h = dt[1][0] - dt[0][0];
            u = (x-dt[0][0])/h;
            y = dt[0][1];
            fact = 1;
            temp = 1;
            for(i=1; i<n; i++)
            {
                temp = temp*(u-(i-1));
                fact = fact*i;
                y = y + (temp*dt[0][i+1])/fact;
            }
            printf("\nBy Newton\'s Forward Interpolation f(x) = %0.4f", y);
        }
        else if (choice==2){
            printf("\n------------------------------------------------------------------------\n");
            printf("Enter value of x to compute : ");
            scanf("%f", &x);
            h = dt[1][0] - dt[0][0];
            u = (x-dt[n-1][0])/h;
            y = dt[n-1][1];
            fact = 1;
            temp = 1;
            for(i=1; i<n; i++)
            {
                temp = temp*(u+(i-1));
                fact = fact*i;
                y = y + (temp*dt[n-1-i][i+1])/fact;
            }
            printf("\nBy Newton\'s Backward Interpolation f(x) = %0.4f", y);
        }
        else if(choice==3) break;
        else printf("\nInvalid option choose one-->");
    }while (1);
}