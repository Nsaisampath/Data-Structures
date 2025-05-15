#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *temp,*head=0,*tail=0,*newnode=0;
int createNode(){
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&newnode->data);
    newnode->prev=0;
    newnode->next=0;
}
void createList()
{
    int choice=1;
    while(choice){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d",&newnode->data);
        newnode->prev=0;
        newnode->next=0;
        if(head==0){
            head=tail=newnode;
        }
        else{
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;
        }
        printf("if u want to continue(0/1):");
        scanf("%d",&choice);
    }
}
void display(){
    temp=head;
    printf("DLL is:");
    while(temp!=0){
        printf("%d ",temp->data);
        temp=temp->next;
    }printf("\n");
}
int InsertAtBegin(){
    createNode();
    if(head==0){
        head=temp=newnode;
    }
    else{
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
    
}
int Count(){
    int count=0;
    temp=head;
    while(temp!=0){
        count++;
        temp=temp->next;
    }return count;
}
    
void freememory(){
    temp=head;
    while(temp!=0){
        struct node *tofree=temp;
        free(tofree);
        temp=temp->next;
    }
}
int main(){
    int option=1,pos,i;
    while(option!=0){
        printf("1.create list\n2.display list\n3.insert at beginning\n4.insert at end\n5.insert at position\n6.insert after position\n7.Delete at beginning\n8.delete at End\n9.Delete at position\n10.Delete after a position\n11.reverse a list\n0.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&option);
        switch(option){
            case 1:
                createList();
                printf("created\n");
                break;
            case 2:
                display();
                break;
            case 3:
               InsertAtBegin();
               printf("Inserted\n");
               break;
            case 4:
                if(head==NULL){
                    InsertAtBegin();
                }
                else{
                    createNode();
                    newnode->prev=tail;
                    tail->next=newnode;
                    tail=newnode;
                }
                printf("Inserted\n");
                break;
            case 5:
                i=1;
                printf("Enter position:");
                scanf("%d",&pos);
                if(pos>Count()||pos<0){
                    printf("Invalid position\n");
                }
                else if(pos==1){
                    InsertAtBegin();
                }
                else{
                    createNode();
                    temp=head;
                    while(i<pos-1){
                        temp=temp->next;
                        i++;
                    }
                    newnode->prev=temp;
                    newnode->next=temp->next;
                    temp->next=newnode;
                    newnode->next->prev=newnode;
                }
                printf("Inserted\n");
                break;
            case 6:
                i=1;
                printf("Enter position:");
                scanf("%d",&pos);
                if(pos>Count()||pos<0){
                    printf("Invalid position\n");
                }
                else if(pos==1){
                    InsertAtBegin();
                }
                else{
                    createNode();
                    temp=head;
                    while(i<pos){
                        temp=temp->next;
                        i++;
                    }
                    newnode->prev=temp;
                    newnode->next=temp->next;
                    temp->next=newnode;
                    newnode->next->prev=newnode;
                }
                break;
            case 7:
                if(head==0){
                    printf("List is empty\n");
                }
                else{
                temp=head;
                head=temp->next;
                head->prev=NULL;
                free(temp);
                }
                break;
            case 8:
                 if(tail==0){
                    printf("List is empty\n");
                }
                else{
                temp=tail;
                tail=tail->prev;
                tail->next=NULL;
                free(temp);
                }
                break;
            case 9:
                struct node *nextnode;
                if(head==0){
                    printf("List is empty\n");
                }
                else{
                    printf("Enter position:");
                    scanf("%d",&pos);
                    printf("\n");
                    if(pos>Count()||pos<0)
                    {
                        printf("Invalid position\n");
                    }
                    else{
                        temp=head;
                        while(i<pos-1){
                            temp=temp->next;
                            i++;
                        }
                        nextnode=temp->next;
                        temp->next=nextnode->next;
                        nextnode->next->prev=temp;
                        free(nextnode);
                    }
                }
                break;
            case 10:
                nextnode;
                if(head==0){
                    printf("List is empty\n");
                }
                else{
                    printf("Enter position:");
                    scanf("%d",&pos);
                    if(pos>Count()||pos<0)
                    {
                        printf("Invalid position\n");
                    }
                    else{
                        temp=head;
                        while(i<pos){
                            temp=temp->next;
                            i++;
                        }
                        nextnode=temp->next;
                        temp->next=nextnode->next;
                        nextnode->next->prev=temp;
                        free(nextnode);
                    }
                }
                break;
            case 11:
                if(tail==0){
                    printf("List is empty\n");
                }
                else{
                struct node *current,*nextnode;
                current=head;
                while(current!=0){
                    nextnode=current->next;
                    current->next=current->prev;
                    current->prev=nextnode;
                    current=nextnode;
                }
                current=head;
                head=tail;
                tail=current;
                }
                break;
            case 0:
                printf("Exit\n");
                break;
            default:
                printf("Invalid option! Enter valid option:\n");
        }
    }
    freememory();
    head=NULL;
    tail=NULL;
    return 0;
    
}