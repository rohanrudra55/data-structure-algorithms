#include "polynomial.h"

// This is an example of multilink lists
// Polinomial operations

int main(){
            int option;
            node *start1;
            node *start2;
            node *result1;
            node *result2;
            do{
                system("clear");
                printf("\n******* MAIN MENU *******");
                printf("\n 1. Enter the first polynomial");
                printf("\n 2. Enter the second polynomial");
                printf("\n 3. Display the first polynomial");
                printf("\n 4. Display the second polynomial");
                printf("\n 5. Add the polynomials");
                printf("\n 6. Subtract the polynomials");
                printf("\n 7. Show addition result");
                printf("\n 8. Show subtraction result");
                printf("\n 9. EXIT");
                printf("\n\n Enter your option : ");
                scanf("%d", &option);
                    switch(option){
                        case 1: start1=create_poly(start1);
                        break;
                        case 2: start2=create_poly(start2);
                        break;
                        case 3: display_poly(start1);
                        break;
                        case 4: display_poly(start2);
                        break;
                        case 5: result1=add_poly(start1,start2);
                        break;
                        case 6: result2=sub_poly(start1,start2);
                        break;
                        case 7: display_poly(result1);
                        break;
                        case 8: display_poly(result2);
                        break;
                    }
        }while(option!=9);
        return 0;
}