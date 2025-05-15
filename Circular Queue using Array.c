#include <stdio.h>
#define N 5
int x;
int rear=-1,front=-1,queue[N];
void enqueue(){
    printf("Enter data:");
    scanf("%d",&x);
    if(rear==-1&&front==-1){
        rear=front=0;
        queue[rear]=x;
    }
    else if(front==(rear+1)%N){
        printf("Queue is full\n");
    }
    else{
        rear=(rear+1)%N;
        queue[rear]=x;
    }
}
void dequeue(){
    if(rear==-1&&front==-1){
        printf("Underflow\n");
    }
    else if(rear==front){
        rear=front=-1;
    }
    else{
        front=(front+1)%N;
    }
}
void display(){
    int i=front;
    if(rear==-1&&front==-1){
        printf("List is empty\n");
    }
    else{
        printf("The elements in the queue are:");
        while(i!=rear){
            printf("%d ",queue[i]);
            i=(i+1)%N;
        }printf("%d",queue[rear]);
        printf("\n");
        }
    }

void peek(){
    if(rear==-1&&front==-1){
        printf("Queue is empty\n");
    }
    else{
        printf("The element in the peek is %d\n",queue[rear]);
    }
}
void isEmpty(){
    if(rear==-1&&front==-1){
        printf("TRUE\n");
    }
    else{
        printf("FALSE\n");
    }
}
void isFull(){
    if(rear==N-1){
        printf("TRUE\n");
    }
    else{
        printf("FALSE\n");
    }
}
void main(){
    int choice;
    do{
        printf("1.enqueue 2.dequeue 3.display 4.peek 5.isFull 6.isEmpty\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            case 5:
                isFull();
                break;
            case 6:
                isEmpty();
                break;
            case 0:
                printf("Exit\n");
                break;
            default:
                printf("Invalid option ,Enter valid option\n");
        }
    }while(choice!=0);
    
}