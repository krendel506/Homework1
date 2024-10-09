#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void inputingVariables(float *a, float *h, float *c, int *n);
float* dynamicAllocation(int size);
void functionCalculation(float a, int i, float c, float h, float *y_value, float*x_value);
void output(float y[], float x[], int size);
int main(){
    float a=0, h=0, c=0;
    int n=0;
    float y_value, x_value;
    
    //Inputing variables
    inputingVariables(&a,&h,&c,&n);
    
    //defining array sizes
    float *y = dynamicAllocation(n);
    float *x = dynamicAllocation(n);
    
    //printing blueprint for table
    printf("X           Y\n");
    
    //calculating function values
    for(int i=0; i<n; i++){
        functionCalculation(a,i,c,h, &y_value, &x_value);
        y[i]= y_value;
        x[i]= x_value;
    }
    //output
    output(y,x, n);

    free(y);
    free(x);
}
float *dynamicAllocation(int size){
    float *array = (float *)malloc(size * sizeof(float));
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed for array of size %d\n", size);
        return NULL;  // Return NULL if allocation fails
    }
    return array; 
}
void inputingVariables(float *a, float *h, float *c,int *n){
     printf("Enter x value: ");
     scanf("%f",a);
    do{
        printf("Enter a value for H (H>0): ");
        scanf("%f",h);
    }while(*h<=0);

    do{
        printf("Enter value for C (C=>1): ");
        scanf("%f",c);
    }while(*c<= 1);
     
    do{
        printf("Enter N: ");
        scanf("%d",n);
    }while(n<0);
}
void functionCalculation(float a, int i, float c, float h, float *y_value, float *x_value)
{
        float x, sum;
        x= a + pow(c,i)*h;
        sum= (sqrt(pow(x,2) + x - 20) / (pow(x,2) + x - 10));
       if (isnan(sum)) {
            *y_value =  nan("");
            *x_value = x;
        }
        else {
            *y_value = sum;
            *x_value = x;
            }
}

void output(float y[], float x[], int size){
    for(int f= 0; f<size;f++){
        if(isnan(y[f])){
        printf("%-10.2f  missing\n",x[f]);
        }
        else{
            printf("%-10.2f  %-10.6f\n",x[f],y[f]);
        }
    }
}