#include<stdio.h>
#include<math.h>
#include<stdlib.h>

float f(float x){
    return(1+exp(-(x*x)/2));
}

void trapizoidal(){
    float a, b, h, i, sum=0.0, I;
	int n;
	printf("\n------------------------------------------------------------------------\n");
	
	printf("Enter Lower limit : ");
	scanf("%f", &a);
	printf("Enter Upper limit : ");
	scanf("%f", &b);
	printf("Enter Interval : ");
	scanf("%d", &n);
	
	h = (b-a)/n;
	printf("\n------------------------------------------------------------------------\n");
	printf("  x\t\ty = f(x)\t    A\t           B\n");
	printf("\n------------------------------------------------------------------------\n");
	printf("%f\t%f\t%f\n", a, f(a),f(a));
	
	for(i=a+h; i<b; i=i+h)
	{
		printf("%f\t%f\t\t\t%f", i, f(i),f(i));
		sum = sum + f(i);
        printf("\n");
	}
	printf("%f\t%f\t%f\n", b, f(b),f(b));
	
	printf("\n------------------------------------------------------------------------\n");
	I = (h/2) * ( f(a) + f(b) + 2*sum);
	printf("Required Integration value value of given equation is: %.4f\n", I);
}

void simpson(){
    float a, b, h, i, I;
	float oddsum = 0.0, evensum = 0.0;
	int n, terms;
	printf("\n------------------------------------------------------------------------\n");
	
	printf("Enter Lower limit : ");
	scanf("%f", &a);
	printf("Enter Upper limit : ");
	scanf("%f", &b);
	printf("Enter Interval : ");
	scanf("%d", &n);
	
	h = (b-a)/n;
	
	printf("\n------------------------------------------------------------------------\n");
	printf("  x\t\ty = f(x)\t    A\t            B\t \t   C\n");
	printf("\n------------------------------------------------------------------------\n");
    printf("%f\t%f\t%f\n", a, f(a),f(a));
	terms = 1;
	for(i=a+h; i<b; i=i+h)
	{
		printf("%f\t%f", i, f(i));
		if(terms%2==0){
            printf("\t\t\t\t\t%f",f(i));
			evensum = evensum + f(i);
        }
		else{
            printf("\t\t\t%f",f(i));
			oddsum = oddsum + f(i);
        }
		terms++;
        printf("\n");
	}
	printf("%f\t%f\t%f\n", b, f(b),f(b));
	
	printf("\n------------------------------------------------------------------------\n");
	I = (h/3) * (f(a) + f(b) + 4*oddsum + 2*evensum);
	
	printf("Required Integration value of given equation is: %f\n", I);

}

int main(){
  do{
  int choice;
  printf("\n------------------------------------------------------------------------\nEnter 1 for Trapizoidal Method\nEnter 2 for Simpson Method\nEnter 3 to exit\n--> ");
  scanf("%d",&choice);
  if(choice==1) trapizoidal();
  else if (choice==2) simpson();
  else if(choice==3) break;
  else printf("\nInvalid option choose one-->");
  }while (1);
  return 0;
}