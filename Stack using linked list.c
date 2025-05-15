#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*link;
};
struct node *top=NULL,*newnode,*temp;
void push(){
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter data:");
    scanf("%d",&newnode->data);
    newnode->link=top;
    top=newnode;
    
}
void pop(){
    if(top==0){
        printf("stack is empty\n");
    }
    else{
        temp=top;
        printf("%d is popped\n",top->data);
        top=top->link;
        free(temp);
    }
}
void peek(){
    if(top==NULL){
        printf("stack is empty\n");
    }
    else{
        printf("The top element is %d\n",top->data);
    }
    
}
void display(){
    if(top==0){
        printf("stack is empty\n");
    }
    else{
        temp=top;
        printf("The elements of stack: ");
        while(temp!=0){
            printf("%d ",temp->data);
            temp=temp->link;
        }
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