#include<stdio.h>
#include<stdlib.h>

void hanoi0(int n,char ,char , char);
int main(){
    system("clear");
    int disks=0;
    printf("Enetr the number of disks: ");
    scanf("%d",&disks);
    hanoi0(disks,'A','C','B');
    return 0;
}

void hanoi0(int n, char source, char destination, char spare){
    if(n==1)
        printf(" Moved from %c -> %c\n",source,destination);
    else{                                                               // In each call this three is creating its own branch
        hanoi0(n-1, source, spare, destination);
        hanoi0(1, source, destination, spare);
        hanoi0(n-1, spare, destination, source);
    }
}