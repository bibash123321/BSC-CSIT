#include<stdio.h>
#include<string.h>

struct node{
    int data;
    struct node *link;

};
int main(){
    // node create
    struct node* first=(struct node*)malloc(sizeof (struct node));
    struct node* second=(struct node*)malloc(sizeof (struct node));
    struct node* third=(struct node*)malloc(sizeof (struct node));

    // initalize data
    first->data = 2;
    second->data = 9;
    third->data = 5;

    // linking the pointer
    first->link = second;
    second->link = third;
    third->link = NULL;

    while(first!=NULL){
        printf("\n %d", first->data);
        first = first->link;
    }
}
