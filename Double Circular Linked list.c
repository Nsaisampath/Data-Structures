#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *temp,*head,*tail,*newnode;
void create_Node(){
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&newnode->data);
    newnode->next=0;
    newnode->prev=0;
}
void CreateDCLL(){
    int choice=1;
    while(choice){
        create_Node();
        if(head==0){
            head=tail=newnode;
            head->next=head;
            head->prev=head;
        }
        else{
            tail->next=newnode;
            newnode->prev=tail;
            newnode->next=head;
            head->prev=newnode;
            tail=newnode;
        }
        printf("do you want to continue(0/1)?");
        scanf("%d",&choice);
    }
}
void displayDCLL(){
    if(tail==0){
        printf("List is Empty\n");
    }
    else{
        printf("CLL is:");
        temp=head;
            do{
                printf("%d ",temp->data);
                temp=temp->next;
            }while(temp!=head);
        printf("\n");
    }
}
void insertAtBeg(){
    create_Node();
    if(head==0){
            head=tail=newnode;
            head->next=head;
            head->prev=head;
        }
        else{
            newnode->next=head;
            newnode->prev=tail;
            head->prev=newnode;
            tail->next=newnode;
            head=newnode;
        }
}
void insertatEnd(){
    create_Node();
    if(head==0)
        {
            head=tail=newnode;
            head->next=head;
            head->prev=head;
        }
        else{
            tail->next=newnode;
            newnode->prev=tail;
            newnode->next=head;
            head->prev=newnode;
            tail=newnode;
        }
}
int lenOfCLL(){
    int len=0;
    temp=head;
    do{
        len++;
        temp=temp->next;
    }while(temp!=head);
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
                temp=head;
                while(i<pos-1){
                    temp=temp->next;
                    i++;
                }
                newnode->prev=temp;
                newnode->next=temp->next;
                temp->next->prev=newnode;
                temp->next=newnode;
            }
        }
}
void deleteAtBeg(){
    temp=head;
    if(temp==0)
        printf("No elements in list\n");
    else if(temp->next==temp){
        tail=head=0;
        free(temp);
    }
    else{
        tail->next=temp->next;
        temp->next->prev=tail;
        head=head->next;
        free(temp);
    }
        
}
void deleteAtEnd(){
    struct node*prev;
    temp=tail;
    if(temp==0)
        printf("No elements in list\n");
    else if(temp->next==temp){
        head=tail=0;
        free(temp);
    }
    else{
        tail->prev->next=temp->next;
        head->prev=temp->prev;
        tail=temp->prev;
        free(temp);
    }
}
void deleteAtPos(){
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
            temp=head;
            while(i<pos-1){
                temp=temp->next;
                i++;
            }
            temp->next=temp->next->next;
            temp->next->next->prev=temp;
            free(temp);
        }
    }
    
}
void free_memory(){
    if(head!=NULL){
    temp = head;
    do{
        struct node* toFree = temp;
        temp = temp->next;
        free(toFree);
    }while(temp!=head);
}}
int main(){
    int choice,count;
    do{
        printf("1.create DCLL\n2.display DCLL\n3.insert at beggining\n4.insert at end\n5.insert at position\n6.length of list\n7.delete at beggining\n8.delete at end\n9.delete at position\n0.exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            CreateDCLL();
            break;
        case 2:
            displayDCLL();
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
        case 0:
            printf("Exit\n");
            free_memory();
            head=NULL;
            tail=NULL;
            break;
        default:
            printf("Invalid position! please enter valid position\n");
        }
    }while(choice!=0);
    return 0;
}