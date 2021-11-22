#include "linkqueue.h"

int main(){
    int option;
    int value;
    system("clear");
    printf(" *** QUEUE Commands ***\n");
    printf(" 1. Push value\n");
    printf(" 2. Pop value\n");
    printf(" 3. Peek value\n");
    printf(" 4. Display value\n");
    printf(" 5. Reset queue\n");
    printf(" 6. EXIT\n");
    do{
        printf(" >>> ");
        scanf("%d",&option);
        switch(option){
            case 1:
                scanf("%d",&value);
                push(value);
                break;
            case 2:
                value=pop();
                if(value!=-1)
                    printf("Poped [%d]\n",value);
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                reset();
                break;
        }
    }while(option!=6);
    return 0;
}