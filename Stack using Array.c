#include<stdio.h>
#define N 5
int stack[N];
int top=-1;
void push(){
    int x;
    if(top==N-1){
        printf("Overflow\n");
    }
    else{
        top++;
        printf("Enter data:");
        scanf("%d",&x);
        stack[top]=x;
    }
}
void pop(){
    int item;
    if(top==-1){
        printf("Overflow\n");
    }
    else{
        item=stack[top];
        top--;
        printf("%d",item);
    }
}
void peek(){
    int item;
    if(top==-1){
        printf("stack is empty\n");
    }
    else{
        item=stack[top];
        printf("%d\n",item);
    }
}
void display(){
    int i;
    if(top==-1){
        printf("stack is empty\n");
    }
    else{
        for(i=top;i>=0;i--){
            printf("%d ",stack[i]);
        }
        printf("\n");
    }
}
void main(){
    int choice;
    do{
        printf("1.push\n2.pop\n3.peek\n4.display\n0.Exit\n");
        printf("Enter choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 0:
                printf("Exit\n");
                break;
            default:
                printf("Invalid option,Enter correct option\n");
        }
    }while(choice!=0);
}