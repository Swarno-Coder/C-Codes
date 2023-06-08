#include<stdio.h>
#include<math.h>
double func(double x){
	return (x*x*x - x - 0.1);
}

void regula(){
	double a=1, b=2;
	double x;
	double h = (fabs(func(a))*(b-a))/(fabs(func(a))+fabs(func(b)));
    printf("\nSolving by Regula-Falsi Method\n------------------------------------------------------------------------\n");
	printf("    a        b         f(a)      f(b)       h         x       f(x)\n\n------------------------------------------------------------------------\n")  ;
	while(fabs(h)>=0.000001){
		x=a+h;
		printf("%f  %f  %f  %f  %f  %f  %f\n",a,b,func(a),func(b),h,x,func(x));
		if(func(x)<0){
			a=x;
		}else{
			b=x;
		}
		h = (fabs(func(a))*(b-a))/(fabs(func(a))+fabs(func(b)));	
	}	
    printf("\n------------------------------------------------------------------------\n\nRoot is %lf",x);
}

void secant(){
    double x1=1, x2=2, xm, x0, c;
    if (func(x1) * func(x2) < 0) {
            printf("\nSolving by Secant Method\n------------------------------------------------------------------------\n");
	        printf("    X1       X2       f(X1)      f(X2)      X0        c       Xm\n\n------------------------------------------------------------------------\n")  ;
        do {
		    printf("%f  %f  %f  %f  %f  %f  %f\n",x1,x2,func(x1),func(x2),x0,c,xm);
            // calculate the intermediate value
            x0 = (x1 * func(x2) - x2 * func(x1)) / (func(x2) - func(x1));
            c = func(x1) * func(x0);
            x1 = x2;
            x2 = x0;
            if (c == 0)
                break;
            xm = (x1 * func(x2) - x2 * func(x1)) / (func(x2) - func(x1));
        } while (fabs(xm - x0) >= 0.0001); // repeat the loop

        printf("\n\n------------------------------------------------------------------------\n\nRoot of the given equation= %lf\n",x0);
    } else
        printf("Can not find a root in the given interval");
}

int main(){
  do{
  int choice;
  printf("\n\n------------------------------------------------------------------------\nEnter 1 for Regula-falsi Method\nEnter 2 for Secant Method\nEnter 3 to exit\n--> ");
  scanf("%d",&choice);
  if(choice==1) regula();
  else if (choice==2) secant();
  else if(choice==3) break;
  else printf("\nInvalid option choose one-->");
  }while (1);
  return 0; 
}