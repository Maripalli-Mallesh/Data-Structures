#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int temp=0;
int a[MAX];
int f=-1;
int r=-1;

int enqueue(int val){
    if((r+1)%MAX==f){
        printf("Overflow\n");
    }
    else{
        if(r==4){
            r=-1;
        }
        a[++r]=val;
        if(f==-1){
        f=0;}
    printf("EnQueue Successfull\n");
    }
}
int dequeue(){
    if(f!=-1 && r!=-1){

        if(f==r){
        f=-1;
        r=-1;
        for(int i=0;i<MAX;i++){
            a[i]=0;
        }
        printf("DeQueue Successfull\n");
        return 0;
        }
        if(f==MAX){
                f=-1;
            }
        else{
            f=f+1;
        }

    printf("DeQueue Successfull\n");
    }

    else{
        printf("underflow\n");
    }

}

int display(){
    if (f<r){
            for(int i=f;i<=r;i++){
             printf("%d ",a[i]);
            }printf("\n");
    }
    else{
        for(int i=f;i<MAX;i++){
        printf("%d ",a[i]);
    }   for(int i=0;i<=r && f!=r;i++){
        printf("%d ",a[i]);
    }printf("\n");
    }

}

int main(){
    int opt=0;
    int tem=0;
    while(1){
    printf("\n1: EnQueue\n2: DeQueue\n3: Display\n4: Clear_Screen\n5: f and r Values\n6: Exit\n --> Choose Option:");
    scanf("%d",&opt);
    switch(opt){
    case 1:
        printf("Enter number:");
        scanf("%d",&tem);
        printf("\nResult: ");
        enqueue(tem);
        break;
    case 2:
        printf("\nResult: ");
        dequeue();
        break;
    case 3:
        printf("\nResult: ");
        display();
        break;
    case 4:
        system("cls");
        break;
    case 5:
        printf("\nf: %d,r: %d\n",f,r);
        break;
    case 6:
        exit(EXIT_SUCCESS);
    }

}
return 0;
}
