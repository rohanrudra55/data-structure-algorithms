#include "dequeue.h"


int main(){
    int option;
    int value;
    system("clear");
    printf(" *** QUEUE Commands ***\n");
    printf(" 1. Push value -> Front\n");
    printf(" 2. Push value -> Rear\n");
    printf(" 3. Pop value -> Front\n");
    printf(" 4. Pop value -> Rear\n");
    printf(" 5. Peek value\n");
    printf(" 6. Display value\n");
    printf(" 7. Reset queue\n");
    printf(" 8. EXIT\n");
    do{
        printf(" >>> ");
        scanf("%d",&option);
        switch(option){
            case 1:
                scanf("%d",&value);
                push_front(value);
                break;
            case 2:
                scanf("%d",&value);
                push_rear(value);
                break;
            case 3:
                value=pop_front();
                if(value!=-1)
                    printf("Popped: front-> [%d]\n",value);
                break;
            case 4:
                value=pop_rear();
                if(value!=-1)
                    printf("Popped: rear-> [%d]\n",value);
                break;
            case 5:
                value=peek();
                if(value!=-1)
                    printf("Peeking: [%d]\n",value);
                break;
            case 6:
                display();
                break;
            case 7:
                reset();
                break;
        }
        // printf("Front-> %d Rear-> %d\n",front,rear);
    }while(option!=8);
    return 0;
}