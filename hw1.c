#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main(){
    float a=0;  
    int h=0; //step
    int c=0;
    int n=0;
    float y ;

    int temporaryStorage = 0;

    printf("Enter x value: ");
    scanf("%f",&a);

    while(true){
        printf("Enter H: ");
        scanf("%d",&temporaryStorage);
     if(temporaryStorage > 0){
        h= temporaryStorage;
        break;          
     }
    }

    while(true){
        printf("Enter C: ");
        scanf("%d",&temporaryStorage);
     if(temporaryStorage >= 0){
        c= temporaryStorage;
        break;
     }
    }
     
    while(true){
        printf("Enter N: ");
        scanf("%d",&temporaryStorage);
     if(temporaryStorage > 0){
        n = temporaryStorage;
        break;
     }
    }

    printf("X           Y\n");
     // Variables to store current power of C and sSide for the loop
     float currentPower = 1.0f;  // C^0 = 1 for the first iteration

    for (int i = 0; i < n; i++) {
        float aCurrentValue = 0;

        if (i == 0) {
            aCurrentValue = 0;  // First iteration, sSide is 0
        } else if (i == 1) {
            aCurrentValue = h;  // Second iteration, sSide is h
        } else {
            currentPower *= c;  // Iteratively calculate c^(i-1)
            aCurrentValue = currentPower * h;
        }

        a += aCurrentValue;  // Update value of 'a'
        float a_square = powf(a,2);
        float bottomSide = a_square + a - 10;
        float squareRootExpression = a_square + a - 20;
    
    /*only checking if squareroot is positive
    because x<-5 and x>4
    while for bottomSide x<3.7 and x>2.7*/
      if(squareRootExpression < 0){
         printf("%-10.2f  missing \n",a);
      }
      else{
        float squareRoot = sqrt(squareRootExpression);
        y = squareRoot / bottomSide;    
        printf("%-10.2f  %-10.6f \n",a,y);
      }  
    } 
    
}