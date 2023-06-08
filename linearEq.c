#include<stdio.h>
#include<math.h>

double fx(double x, double y, double z){ return(20+(3*y)-(2*z))/8; }
double fy(double x, double y, double z){ return(33+z-(4*x))/11; }
double fz(double x, double y, double z){ return(9-x-y)/4; }

void gaussJacobi(){
  double x0,y0,z0,x1,y1,z1,e1,e2,e3;
  x0=y0=z0=x1=y1=z1=e1=e2=e3=0.00;
  printf("\n\t    x\t\t    y\t\t    z\n------------------------------------------------------------\n");
  printf("\n\t%lf\t%lf\t%lf",x1,y1,z1);
  do
  {
    /* code */
    x1=fx(x0,y0,z0);
    y1=fy(x0,y0,z0);
    z1=fz(x0,y0,z0);

    e1=fabs(x0-x1);
    e2=fabs(y0-y1);
    e3=fabs(z0-z1);

    x0=x1;
    y0=y1;
    z0=z1;
    
    printf("\n\t%lf\t%lf\t%lf",x1,y1,z1);
  } while (e1>0.0001 && e2>0.0001 && e3>0.0001);
  printf("\n------------------------------------------------------------\n\nRoots are %lf, %lf, %lf solved by Gauss-Jacobi Method\n",x0,y0,z0);
}

void gaussSeidal(){
  double x0,y0,z0;
  x0=y0=z0=0.00;
  printf("\n\t    x\t\t    y\t\t    z\n------------------------------------------------------------\n");
  printf("\n\t%lf\t%lf\t%lf",x0,y0,z0);
  do
  {
    x0=fx(x0,y0,z0);
    y0=fy(x0,y0,z0);
    z0=fz(x0,y0,z0);
    printf("\n\t%lf\t%lf\t%lf",x0,y0,z0);
  } while (fabs(round(x0)-x0)>0.0001 && fabs(round(y0)-y0)>0.0001 && fabs(round(z0)-z0)>0.0001);
  printf("\n------------------------------------------------------------\n\nRoots are %lf, %lf, %lf solved by Gauss-Jacobi Method\n",x0,y0,z0);
}

int main(){
  do{
  int choice;
  printf("\n------------------------------------------------------------\nEnter 1 for Gauss-Seidal Method\nEnter 2 for Gauss-Jacobi Method\nEnter 3 to exit\n-->");
  scanf("%d",&choice);
  if(choice==1) gaussSeidal();
  else if (choice==2) gaussJacobi();
  else if(choice==3) break;
  else printf("\nInvalid option choose one-->");
  }while (1);
  return 0; 
}