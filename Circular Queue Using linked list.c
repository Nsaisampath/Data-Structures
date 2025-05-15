#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*front=0,*rear=0,*temp;
void enqueue(){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&newnode->data);
    newnode->next=0;
    if(rear ==0&&front==0){
        rear=front=newnode;
        rear->next=front;
    }
    else{
        rear->next=newnode;
        rear=newnode;
        rear->next=front;
    }
    
}
void dequeue(){
    if(rear==0&&front==0){
        printf("Underflow\n");
    }
    else if(rear==front){
        front=0;
        rear=0;
        free(front);
    }
    else{
        temp=front;
        rear->next=front->next;
        front=front->next;
        free(temp);
    }
    
}
void display(){
    temp=front;
    if(front==0&&rear==0){
        printf("Queue is empty\n");
    }
    else{
        do{
            printf("%d ",temp->data);
            temp=temp->next;
        }while(temp!=front);
    }
}
void peek(){
    if(rear==0&&front==0){
        printf("Queue is empty\n");
    }
    else{
        printf("The element in the peek is %d\n",front->data);
    }
}
void isEmpty(){
    if(rear==0&&front==0){
        printf("TRUE\n");
    }
    else{
        printf("FALSE\n");
    }
}
void main(){
    int choice;
    do{
        printf("1.enqueue 2.dequeue 3.display 4.peek 5.isEmpty 0.Exit\n");
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