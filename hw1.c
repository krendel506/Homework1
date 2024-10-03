#include <stdio.h>
#include <math.h>

void inputingVariables(float *a, float *h, float *c, int *n);
void functionCalculation(float a, float c, float h, int n);

int main(){
    float a=0;
    float h=0;
    float c=0;
    int n=0;
    
    
    //Inputing variables
   inputingVariables(&a,&h,&c,&n);
   //printing blueprint for table
    printf("X           Y\n");
   //calculating the value
    functionCalculation(a,c,h,n);
}

void inputingVariables(float *a, float *h, float *c,int *n){
     printf("Enter x value: ");
     scanf("%f",a);
    do{
        printf("Enter a value for H (H>0): ");
        scanf("%f",h);
    }while(h<=0);

    do{
        printf("Enter value for C (C=>1): ");
        scanf("%f",c);
    }while(c<=1);
     
    do{
        printf("Enter N: ");
        scanf("%d",n);
    }while(n<0);
}

void functionCalculation(float a, float c, float h, int n)
{
    for (int i = 0; i < n; i++) {
        float x,y;
        x= a + pow(c,i)*h;
        y= sqrt(pow(x,2) + x - 20) / (pow(x,2) + x - 10);
        
       if (isnan(y)) {
            printf("%-10.2f  missing \n",x);
        }
        else {
            printf("%-10.2f  %-10.6f \n",x,y);
            }
    } 
}