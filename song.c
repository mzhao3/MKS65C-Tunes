#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct song_node {
  char name[100];
  char artist[100];
  struct song_node *next;
}

struct song_node * insert_front (struct song_node * head, char[] new_name, char[] new_artist) {
  struct song_node * newSong = (struct song_node *)malloc(sizeof(struct song_node));
  newSong->name = new_name;
  newSong->artist = new_artist;
  newSong->next = head;
  return newSong;
}

struct song_node * insert_orderA (struct song_node * head, char * name, char * artist);

struct song_node * insert_orderS (struct song_node * head, char * name, char * artist);


void print_list (struct song_node * front) {
    if (!front){
    printf("|\n");
  }
  else {
    while (front -> next){
      printf("%s : %s|",front->name, front->artist);
      front = front -> next;
    }
    printf("\n",front->name, front-> artist);
  }

struct song_node * get_song(char * name; char * artist );

struct song_node * first_song(char * artist);

int remove_node (char * name, char * artist);

struct song_node * free_list (struct song_node * start);
