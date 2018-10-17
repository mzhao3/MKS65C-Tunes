#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "song.h"

/* JUST FOR REFERENCE
   struct song_node {
   char name[100];
   char artist[100];
   struct song_node *next;
   };
*/

struct song_node * insert_front (struct song_node * head, char* new_artist, char* new_name) {
  struct song_node * newSong = (struct song_node *)malloc(sizeof(struct song_node));
  strcpy(newSong->name, new_name);
  strcpy(newSong->artist, new_artist);
  newSong->next = head;
  return newSong;
}

struct song_node * insert_order (struct song_node * head, char * new_artist, char * new_name) {
  if (!head) {
    return insert_front(head,new_artist,new_name);
  }
  struct song_node * newSong = (struct song_node *)malloc(sizeof(struct song_node));
  strcpy(newSong->name, new_name);
  strcpy(newSong->artist, new_artist);
  struct song_node * temp = head;
  struct song_node * temp_prev = NULL;
  while(temp){
    printf("artistname: %s < %s\n",newSong->artist,temp->artist);
    int comparison_artist = strcmp(newSong->artist,temp->artist);
    int comparison_name = strcmp(newSong->name,temp->name);
    if (comparison_artist < 0 || (comparison_artist == 0 && comparison_name < 0)) {
      if (head == temp) {
        newSong->next = temp;
        return newSong;
      }
      else {
        temp_prev->next = newSong;
        newSong->next = temp;
        return head;
      }
    }
    else {
      temp_prev = temp;
      temp = temp->next;
    }
  }
  temp_prev->next = newSong;
  newSong->next = NULL;
  return head;
}

void print_node (struct song_node * node) {
  if (!node){
    return;
  }
  printf(" %s: %s ",node->artist,node->name);
}

void print_list (struct song_node * front) {
  if (!front){
    printf("|\n");
  }
  else {
    while (front -> next){
      print_node(front);
      printf("|");
      front = front -> next;
    }
    print_node(front);
  }
}

struct song_node * find_node(struct song_node * head, char * artist_name, char * song_name ) {
  while (head) {
    if (strcmp(head->artist,artist_name) == 0 &&
        strcmp(head->name,song_name) == 0) {
      return head;
    }
    else {
      head = head->next;
    }
  }
  return NULL;
}

struct song_node * find_artist(struct song_node * head, char * artist_name) {
  while(head) {
    if (strcmp(head->artist,artist_name) == 0){
      return head;
    }
    else {
      head = head->next;
    }
  }
  return NULL;
}

struct song_node * random_node(struct song_node * head){
  int randomIndex = rand() % list_length(head);
  while(randomIndex){
    head = head->next;
    randomIndex--;
  }
  return head;
}

int list_length(struct song_node * head) {
  int length = 0;
  while(head){
    length++;
    head = head->next;
  }
  return length;
}

struct song_node * remove_node(struct song_node * head, char * artist_name, char * song_name) {
  struct song_node * prev_node = NULL;
  while(head){
    if (strcmp(head->artist,artist_name) == 0 &&
        strcmp(head->name,song_name) == 0) {
      if (prev_node){
        prev_node->next = head->next;
        free(head);
      }
      else {
        struct song_node * next_node = head->next;
        free(head);
        return next_node;
      }
      return head;
    }
    else {
      prev_node = head;
      head = head->next;
    }
  }
  return head;
}

struct song_node * free_list (struct song_node * head){
  while(head) {
    struct song_node * original = head;
    head = head->next;
    original->next = NULL;
    free(original);
  }
  return head;
}
