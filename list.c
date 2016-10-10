#include <stdio.h>
#include <stdlib.h>

struct node {int i; struct node *next;};

void print_list( struct node *list){
  printf("[");
  while(list){
    if(list->next){
      printf("%d->", list->i);
    }
    else
      printf("%d", list->i);
    list= list->next;
  }
  printf("]\n");
}

struct node *insert_front(struct node *list, int x){
  struct node *new= (struct node *) malloc(sizeof(struct node));
  new->i = x;
  new->next = list;
  return new;
}

struct node *free_list(struct node *list){
  struct node *temp, *holder;
  holder = list;
  while(list){
    temp=list->next;
    free(list);
    list=temp;
  }
  return holder;
}

void main(){
  struct node *same;
  printf("Creating same:\n");
  same=(struct node *) malloc(sizeof(struct node));
  same->i =0;
  same->next = NULL;
  printf("Here is same: (Should be 0)\n");
  print_list(same);
  printf("inserting 1 into same\n");
  same=insert_front(same, 1);
  printf("printing same:");
  print_list(same);
  printf("inserting 99 into same\n");
  same = insert_front(same, 99);
  print_list(same);
  printf("freeing same:\n");
  free_list(same);
  print_list(same);
}
