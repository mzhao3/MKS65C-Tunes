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
    int comparison_name = strcmp(newSong->artist,temp->artist);
    int comparison_artist = strcmp(newSong->name,temp->name);
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

void print_list (struct song_node * front) {
    if (!front){
    printf("|\n");
  }
  else {
    while (front -> next){
      printf("%s: %s | ",front->name, front->artist);
      front = front -> next;
    }
    printf("%s: %s\n",front->name, front-> artist);
  }
}

/*

struct song_node * get_song(char * name, char * artist ) {
  return NULL;
}

struct song_node * first_song(char * artist) {
  return NULL;
}

int remove_node (char * name, char * artist) {
  return 0;
}

struct song_node * free_list (struct song_node * start){
  return NULL;
}

    */
