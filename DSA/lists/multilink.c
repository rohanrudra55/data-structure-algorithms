#include "multilink.h"

// This is an example of multilink lists
// Sparse Matrix

int main(){
    int option;
    system("clear");
    do{
        printf("\n -----ENTER YOUR CHOIUCE-----");
        printf("\n 1. Create Upper Triangular Matrix");
        printf("\n 2. Create Lower Triangular Matrix");
        printf("\n 3. Create Tri-Diagonal  Matrix");
        printf("\n 4. Display Matrix");
        printf("\n 5. Exit");
        printf("\n -----ENTER YOUR CHOICE-----\n");
        printf(">>> ");
        scanf("%d",&option);
        system("clear");
        switch( option ){
            case 1: create_upper_triangular();
            break;
            case 2: create_lower_triangular();
            break;
            case 3: create_tri_diagonal();
            break;
            case 4: display_sparse_mat();
            break;
        }
    }while(option!=5);
    return 0;
}