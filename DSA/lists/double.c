#include "double.h"

int main(){
    node *start = NULL;
    int option;
    do{
        system("clear");
        printf("\n *****MAIN MENU *****");
        printf("\n 01: Create a list");
        printf("\n 02: Display the list");
        printf("\n 03: Add a node at the beginning");
        printf("\n 04: Add a node at the end");
        printf("\n 05: Add a node before a given node");
        printf("\n 06: Add a node after a given node");
        printf("\n 07: Delete a node from the beginning");
        printf("\n 08: Delete a node from the end");
        printf("\n 09: Delete a node before a given node");
        printf("\n 10: Delete a node after a given node");
        printf("\n 11: Delete the entire list");
        printf("\n 13: EXIT");
        printf("\n Enter your option : ");
        scanf("%d", &option);
        switch(option){
            case 1: start=create_ll();
            break;
            case 2: display(start);
            break;
            case 3: start=insert_beg(start);
            break;
            case 4: start=insert_end(start);
            break;
            case 5: start=insert_before(start);
            break;
            case 6: start=insert_after(start);
            break;
            case 7: start=delete_beg(start);
            break;
            case 8: start=delete_end(start);
            break;
            case 9: start=delete_before(start);
            break;
            case 10: start=delete_after(start);
            break;
            case 11: start=delete_list(start);
        }
    }while(option !=13);
    return 0;
}