#include "circular.h"

int main(){
    node *start = NULL;
    int option;
    do{
        system("clear");
        printf("\n *****MAIN MENU *****");
        printf("\n 1: Create a list");
        printf("\n 2: Display the list");
        printf("\n 3: Add a node at the beginning");
        printf("\n 4: Add a node at the end");
        printf("\n 5: Delete a node from the beginning");
        printf("\n 6: Delete a node from the end");
        printf("\n 7: Delete a node after a given node");
        printf("\n 8: Delete the entire list");
        printf("\n 9: EXIT");
        printf("\n\n Enter your option : ");
        scanf("%d", &option);
        switch(option){
            case 1: start = create_circular_list();
            break;
            case 2: display_circualr_list(start);
            break;
            case 3: start=insert_beg(start);
            break;
            case 4: start=insert_end(start);
            break;
            case 5: start=delete_beg(start);
            break;
            case 6: start=delete_end(start);
            break;
            case 7: start=delete_after(start);
            break;
        }
    }while(option!=9);
    return 0;
}