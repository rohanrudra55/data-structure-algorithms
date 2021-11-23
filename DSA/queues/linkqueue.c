#include "linkqueue.h"

// Issue create_queue not working 
// Giving Segmentation fault

int main(){
    int option;
    int value;
    struct queue *new_q;
    create_queue(new_q);
    if(new_q->front==NULL)
        printf("AA");
    exit(0);
    // system("clear");
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
                new_q=push(new_q,value);
                break;
            case 2:
                new_q=delete_ele(new_q);
                break;
            case 3:
                value=peek(new_q);
                if(!abs(value))
                    printf(" First: %d",value);
                break;
            case 4:
                display(new_q);
                break;
            case 5:
                reset(new_q);
                break;
        }
    }while(option!=6);
    return 0;
}