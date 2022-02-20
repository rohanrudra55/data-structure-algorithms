#include "hash.h"

int main(){
	int choice, key, value, n, c;
	array = (struct hashtable_item*) malloc(max * sizeof(struct hashtable_item));
	init_array();
	do {
        system("clear");
		printf("Implementation of Hash Table in C with Double Hashing.\n\n");
		printf("MENU-: \n1. Inserting item in the Hash Table");
        printf("\n2. Removing item from the Hash Table");
        printf("\n3. Check the size of Hash Table");
        printf("\n4. Display Hash Table");
        printf("\n5. To exit\n\n Please enter your choice-:");
		scanf("%d", &choice);
		switch(choice){
		case 1:printf("Inserting element in Hash Table\nEnter key and value-:\t");
		      scanf("%d %d", &key, &value);
		      insert(key, value);
		      break;
   		case 2:printf("Deleting in Hash Table \n Enter the key to delete-:");
		      scanf("%d", &key);
		      remove_element(key);
		      break;
		case 3:n = size_of_hashtable();
		      printf("Size of Hash Table is-:%d\n", n);
		      break;
		case 4:display();
		      break;
		default:printf("Wrong Input\n");
		}
	}while(c != 5);
    return 0;
}