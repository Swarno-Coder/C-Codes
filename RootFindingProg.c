/*Numerical Assignment 1:
Write a menu driven Program in C to implement the Bisection Method and Newton Raphson Method to find the real roots of the following equation : 4x-sinx-1=0*/
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>


float func(float x) 
{
    return 4*x-sin(x)-1;
}
float f(float x)
{
    return 4*x-sin(x)-1;
}
float g(float y)
{
    return 4-cos(y);
}
void bisection_method()
{
    float a,b,c;
    int n=0;
    printf("\nEnter a value for a:");
    scanf("%f",&a);
    printf("\nEnter a value for b:");
    scanf("%f",&b);
    if(func(a)*func(b)<=0)
    {
        printf("n\ta\t\tb\t\tc\t\tfunc(c)\n");
        printf("\n--\t--------\t--------\t--------\t--------\n");
        while(fabs(b-a)>0.0001)
        {
            c=(a+b)/2;
            printf("%d\t%f\t%f\t%f\t%f\n",n,a,b,c,func(c));
            if(func(c)==0)
            {
                printf("Root=%f",c);\
                exit(0);
            }
            else if(func(c)>0)
            {
                b=c;
            }
            else if(func(c)<0)
            {
                a=c;
            }
            n++;
        }
        printf("Approximated root:%0.3f",c);
    }
    else
    {
        printf("\n Wrong input");
    }
}
void newton_raphson_method()
{
    float x,prev;
    int n=0;
    printf("\nEnter value for x:");
    scanf("%f",&x);
    float h=-(f(x)/g(x));
    prev=x;
    printf("n\tX\t\tf(x)\t\tf\'(x)\t\th\t\tXn+1\n");
    printf("%d\t%f\t%f\t%f\t%f\t%f\t\n",n++,prev,f(x),g(x),h,x=x+h);
    while(fabs(x-prev)>0.0001)
    {
        h=-(f(x)/g(x));
        prev=x;
        printf("%d\t%f\t%f\t%f\t%f\t%f\t\n",n++,prev,f(x),g(x),h,x=x+h);
    }
    printf("Aprroximate root:%0.3f",x);
}
int main()
{
    int ch;
    do{
    printf("\nPress 1 for solving the problem using Bisection Method\nPress 2 for solving the problem using Newton Raphson Method");
    printf("\n-->>");
    scanf("%d", &ch);
    switch (ch)
    {
        case 1:printf("\nBisection Method-->>");
               bisection_method();
               break;
        case 2 :printf("\nNewton Raphson Method-->>");
                newton_raphson_method();
                break;
        default:printf("\nPlease enter correct choice: ");
    }
    printf("\nIf you want to continue the process press Y or y.\n-->>");
    char c=getch();
    if(c!='y' || c!='Y') break;
    }while (1); 
    return 0;
}


/*
PS D:\College Assignment\Sem-3> gcc .\17.10.2022.c
PS D:\College Assignment\Sem-3> .\a.exe

Press 1 for solving the problem using Bisection Method
Press 2 for solving the problem using Newton Raphson Method
-->>1

Bisection Method-->>
Enter a value for a:0

Enter a value for b:1
n       a               b               c               func(c)

--      --------        --------        --------        --------
0       0.000000        1.000000        0.500000        0.520574
1       0.000000        0.500000        0.250000        -0.247404
2       0.250000        0.500000        0.375000        0.133727
3       0.250000        0.375000        0.312500        -0.057439
4       0.312500        0.375000        0.343750        0.037980
5       0.312500        0.343750        0.328125        -0.009769
6       0.328125        0.343750        0.335938        0.014096
7       0.328125        0.335938        0.332031        0.002161
8       0.328125        0.332031        0.330078        -0.003804
9       0.330078        0.332031        0.331055        -0.000822
10      0.331055        0.332031        0.331543        0.000670
11      0.331055        0.331543        0.331299        -0.000076
12      0.331299        0.331543        0.331421        0.000297
13      0.331299        0.331421        0.331360        0.000110
Approximated root:0.331
If you want to continue the process press Y or y.
-->>
Press 1 for solving the problem using Bisection Method
Press 2 for solving the problem using Newton Raphson Method
-->>1

Bisection Method-->>
Enter a value for a:-1

Enter a value for b:1
n       a               b               c               func(c)

--      --------        --------        --------        --------
0       -1.000000       1.000000        0.000000        -1.000000
1       0.000000        1.000000        0.500000        0.520574
2       0.000000        0.500000        0.250000        -0.247404
3       0.250000        0.500000        0.375000        0.133727
4       0.250000        0.375000        0.312500        -0.057439
5       0.312500        0.375000        0.343750        0.037980
6       0.312500        0.343750        0.328125        -0.009769
7       0.328125        0.343750        0.335938        0.014096
8       0.328125        0.335938        0.332031        0.002161
9       0.328125        0.332031        0.330078        -0.003804
10      0.330078        0.332031        0.331055        -0.000822
11      0.331055        0.332031        0.331543        0.000670
12      0.331055        0.331543        0.331299        -0.000076
13      0.331299        0.331543        0.331421        0.000297
14      0.331299        0.331421        0.331360        0.000110
Approximated root:0.331
If you want to continue the process press Y or y.
-->>
Press 1 for solving the problem using Bisection Method
Press 2 for solving the problem using Newton Raphson Method
-->>2

Newton Raphson Method-->>
Enter value for x:0
n       X               f(x)            f*(x)           h               Xn+1
0       0.000000        0.006139        3.055043        0.333333        0.333333
1       0.333333        0.000001        3.054388        -0.002009       0.331324
2       0.331324        0.000000        3.054387        -0.000000       0.331324
Aprroximate root:0.331
If you want to continue the process press Y or y.
-->>
Press 1 for solving the problem using Bisection Method
Press 2 for solving the problem using Newton Raphson Method
-->>2

Newton Raphson Method-->>
Enter value for x:-1
n       X               f(x)            f*(x)           h               Xn+1
0       -1.000000       -0.392653       3.020331        1.201992        0.201992
1       0.201992        0.002051        3.054606        0.130003        0.331995
2       0.331995        0.000000        3.054388        -0.000672       0.331324
3       0.331324        0.000000        3.054387        -0.000000       0.331324
Aprroximate root:0.331
If you want to continue the process press Y or y.
-->>


An assignment project by Swarnodip Nag
NAC CMSA 2021892
*/