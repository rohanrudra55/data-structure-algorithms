#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int queue[MAX];
int rear_a=-1,front_a=-1,rear_b=MAX,front_b=MAX;

void insert_a(int val){
    // Inserting elements from left to right 
     if(rear_a==rear_b-1) 
        printf("Overflow !!\n");

     else{
          if(front_a == -1 & rear_a == -1) 
            front_a=0;
          queue[++rear_a]=val;
     }
}


void insert_b(int val){
    // Inserting elements from left to right 
     if(rear_a==rear_b-1) 
        printf("Overflow !!\n");

     else{
          if(front_b == MAX & rear_b == MAX) 
            front_b = MAX-1;
          queue[ --rear_b ]=val;
     }
}



int delete_a(){
    // Deleting elemnts from the front in the left
     int val=-1;
     if(front_a==-1) 
        printf("UNDERFLOW !!! \n");

     else{
          val=queue[front_a++];
          if(front_a>rear_a) 
            front_a=rear_a-1;
     }
     return val;
}


int delete_b(){
    // Deleting elemnts from the front in the left
     int val=-1;
     if(front_b==MAX) 
        printf("UNDERFLOW !!! \n");

     else{
          val=queue[front_b--];
          if(front_b<rear_b) 
            front_b=rear_b+1;
     }
     return val;
}


void display_a(){
     if(front_a==-1) 
        printf("EMPTY !!!\n");
     for(int i=front_a;i<=rear_a;i++)
        printf("\t%d",queue[i]);
}

void display_b(){
     if(front_b==-1) 
        printf("EMPTY !!!\n");
     for(int i=front_b;i>=rear_b;i--)
        printf("\t%d",queue[i]);
}

int main(){
    int option, val;
    do{
            printf("\n *******MENU******");
            printf("\n 1. INSERT IN QUEUE A");
            printf("\n 2. INSERT IN QUEUE B");
            printf("\n 3. DELETE FROM QUEUE A");
            printf("\n 4. DELETE FROM QUEUE B");
            printf("\n 5. DISPLAY QUEUE A");
            printf("\n 6. DISPLAY QUEUE B");
            printf("\n 7. EXIT");
            printf("\n Enter your option : ");
            scanf("%d",&option);
            switch(option){
            
            case 1: 
                printf("\nEnter the value to be inserted in Queue A:"); 
                scanf("%d",&val);
                insert_a(val);
                break;

            case 2: 
                printf("\nEnter the value to be inserted in Queue B:"); 
                scanf("%d",&val);
                insert_b(val);
                break;

            case 3: 
                val=delete_a(); 
                if(val != -1)
                printf("\n The value deleted from Queue A = %d",val); 
                break;

            case 4: 
                val=delete_b(); 
                if(val != -1)
                printf("\n The value deleted from Queue B = %d",val); 
                break;
            
            case 5:
                printf("\n The contents of Queue A are : \n");
                display_a();
                break;

            case 6:
                printf("\n The contents of Queue B are : \n");
                display_b();
                break;
            }
        }while(option !=7);
    return 0;
}