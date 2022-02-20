#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct data {
	int key;
	int value;
};
 
struct hashtable_item{
	int flag;
	/*
	 * flag = 0 : data not present
	 * flag = 1 : some data already present
	 * flag = 2 : data was present,but deleted
	*/
	struct data *item;
};
 
int get_prime();
void init_array();
int size_of_hashtable();
void display();
void insert(int,int);
void remove_element(int);
struct hashtable_item *array;
int max = 7, size = 0, prime = 3;
 
int hashcode1(int key){
	return (key % max);
}
 
int hashcode2(int key){
	return (prime - (key % prime));
}
 
void insert(int key, int value){
	int hash1 = hashcode1(key);
	int hash2 = hashcode2(key);
	int index = hash1;
	
	struct data *new_item = (struct data*) malloc(sizeof(struct data));
	new_item->key = key;
	new_item->value = value;
	if (size == max) {
		printf("\n Hash Table is full, cannot insert more items \n");
		return;
	}
	while (array[index].flag == 1) {
		if (array[index].item->key == key)
                {
			printf("\n Key already present, hence updating its value \n");
			array[index].item->value = value;
			return;
		}
		index = (index + hash2) % max; 
		if (index == hash1){
			printf("\n Add is failed \n");
			return;
		}
		printf("\n probing \n");
	}
	array[index].item = new_item;
	array[index].flag = 1;
	size++;
	printf("\n Key (%d) has been inserted \n", key);
}

void remove_element(int key){
	int hash1 = hashcode1(key);
	int hash2 = hashcode2(key);
	int index = hash1;
 
	if (size == 0){
		printf("\n Hash Table is empty \n");
		return;
	}
 
	while (array[index].flag != 0){
		if (array[index].flag == 1  &&  array[index].item->key == key){
			array[index].item = NULL;
			array[index].flag = 2;
			size--;
			printf("\n Key (%d) has been removed \n", key);
			return;
		}
		index = (index + hash2) % max;
		if (index == hash1){
			break;
		}
	}
	printf("\n Key (%d) does not exist \n", key);
}
 
int size_of_hashtable(){
	return size;
}

void display(){
	int i;
	for (i = 0; i < max; i++){
		if (array[i].flag != 1)
			printf("\n Array[%d] has no elements \n", i);
		else
			printf("\n Array[%d] has elements \n Key (%d) and Value (%d) \n", i, array[i].item->key, array[i].item->value);
	}
}
void init_array(){
	for(int i = 0; i < max; i++){
		array[i].item = NULL;
		array[i].flag = 0;
	}
	prime = get_prime();
}
 
int get_prime(){
	int i,j; 
	for (i = max - 1; i >= 1; i--){
		int flag = 0;
		for (j = 2; j <= (int)sqrt(i); j++){
			if (i % j == 0)
				flag++;
		}
		if (flag == 0)
			return i;
	}
	return 3;
}