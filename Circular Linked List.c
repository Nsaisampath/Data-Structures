#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *temp,*tail,*newnode;
void create_Node(){
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&newnode->data);
    newnode->next=0;
}
void CreateCLL(){
    int choice=1;
    while(choice){
        create_Node();
        if(tail==0){
            tail=newnode;
            tail->next=newnode;
        }
        else{
            newnode->next=tail->next;
            tail->next=newnode;
            tail=newnode;
        }
        printf("do you want to continue(0/1)?");
        scanf("%d",&choice);
    }
}
void displayCLL(){
    if(tail==0){
        printf("List is Empty\n");
    }
    else{
        printf("CLL is:");
        temp=tail->next;
            do{
                printf("%d ",temp->data);
                temp=temp->next;
            }while(temp!=tail->next);
        printf("\n");
    }
}
void insertAtBeg(){
    create_Node();
    if(tail==0){
            tail=newnode;
            tail->next=newnode;
        }
        else{
            newnode->next=tail->next;
            tail->next=newnode;
        }
}
void insertatEnd(){
    create_Node();
    if(tail==0)
        {
            tail=newnode;
            tail->next=newnode;
        }
        else{
            newnode->next=tail->next;
            tail->next=newnode;
            tail=newnode;
        }
}
int lenOfCLL(){
    int len=0;
    temp=tail->next;
    do{
        temp=temp->next;
        len++;
    }while(temp!=tail->next);
    return len;
}
void  insertAtPos(){
    int pos,i=1;
        printf("Enter position:");
        scanf("%d",&pos);
        if(pos<0||pos>lenOfCLL()){
            printf("Invalid position\n");
        }
        else{
            if(pos==1){
                insertAtBeg();
            }
            else if(pos==lenOfCLL()){
                insertatEnd();
            }
            else{
                create_Node();
                temp=tail->next;
                while(i<pos-1){
                    temp=temp->next;
                    i++;
                }
                newnode->next=temp->next;
                temp->next=newnode;
            }
        }
}
void deleteAtBeg(){
    temp=tail->next;
    if(temp==0)
        printf("No elements in list\n");
    else if(temp->next==temp){
        tail=0;
        free(temp);
    }
    else{
        tail->next=temp->next;
        free(temp);
    }
        
}
void deleteAtEnd(){
    struct node*prev;
    temp=tail->next;
    if(temp==0)
        printf("No elements in list\n");
    else if(temp->next==temp){
        tail=0;
        free(temp);
    }
    else{
        while(temp->next!=tail->next){
            prev=temp;
            temp=temp->next;
        }
        prev->next=tail->next;
        tail=prev;
        free(temp);
    }
}
void deleteAtPos(){
    struct node *prev;
    int pos,i=1;
    printf("Enter position:");
    scanf("%d",&pos);
    if(pos<0||pos>lenOfCLL()){
        printf("Invalid position\n");
    }
    else{
        if(pos==1){
            deleteAtBeg();
        }
        else if(pos==lenOfCLL()){
            deleteAtEnd();
        }
        else{
            temp=tail->next;
            while(i<pos){
                prev=temp;
                temp=temp->next;
                i++;
            }
            prev->next=temp->next;
            free(temp);
        }
    }
    
}
void reverse_CLL(){
    struct node *prev,*nextnode,*current;
    if(tail==NULL||tail->next==tail){
        printf("cannot reverse\n");
    }
    current=tail->next;
    nextnode=current->next;
    while(current!=tail){
        prev=current;
        current=nextnode;
        nextnode=current->next;
        current->next=prev;
    }
    nextnode->next=tail;
    tail=nextnode;
}
void free_memory(){
    if(tail!=NULL){
    temp = tail->next;
    do{
        struct node* toFree = temp;
        temp = temp->next;
        free(toFree);
    }while(temp!=tail->next);
}}
int main(){
    int choice,count;
    do{
        printf("1.create CLL\n2.display CLL\n3.insert at beggining\n4.insert at end\n5.insert at position\n6.length of list\n7.delete at beggining\n8.delete at end\n9.delete at position\n10.Reverse a CLL\n0.exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            CreateCLL();
            break;
        case 2:
            displayCLL();
            break;
        case 3:
            insertAtBeg();
            break;
        case 4:
            insertatEnd();
            break;
        case 5:
            insertAtPos();
            break;
        case 6:
            count=lenOfCLL();
            printf("%d\n",count);
            break;
        case 7:
            deleteAtBeg();
            break;
        case 8:
            deleteAtEnd();
            break;
        case 9:
            deleteAtPos();
            break;
        case 10:
            reverse_CLL();
            break;
        case 0:
            printf("Exit\n");
            free_memory();
            tail=NULL;
            break;
        default:
            printf("Invalid position! please enter valid position\n");
        }
    }while(choice!=0);
    return 0;
}