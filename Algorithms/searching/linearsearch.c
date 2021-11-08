#include<stdio.h>
#include<stdlib.h>
void display(int *list,int indx){
    printf("List: ");
    for(int i=0;i<indx;i++)
        printf("%d at index %d\n",list[i],i);
}
int search(int *list,int indx);

int main(int inputs, char *filepath[]){
    // char buffer[255];
    int buffer;
    int  *list;
    int count=0;
    if(inputs == 1){
        printf("Pass the text file for values");
        exit(0);
    }
    else{
        FILE *file;
        file=fopen(filepath[1],"r");
        list = (int*)calloc(1, sizeof(int));
        while(fscanf(file, "%d", &buffer) != EOF){

            list = realloc(list, 1 * sizeof(int));
            list[count++]=buffer;
            // printf("Value: %2d Address: %p\n",list[count-1],&list[count-1]);

            if (list == NULL) {
                printf("Memory not allocated\n");
                exit(0);
            }
        }
        fclose(file);
        display(list,count);
    }


return 0;
}