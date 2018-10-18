#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "library.h"
#include "song.h"


struct library * make_lib() {
  struct library * lib = calloc(sizeof(struct song_node), 27);

  int i = 0;
  while (i++ < 27) {
    (lib->table)[i] = NULL;
  }
  return lib;
}

struct library * add_song(struct song_node * new_song, struct library * lib) {
  int letter = (new_song->artist)[0];

  if (97 <= letter && letter <= 122) {
    (lib->table)[letter - 97] = insert_order( (lib->table)[letter - 97], new_song->artist, new_song->name );
  }
  else
    (lib->table)[26] = insert_order( (lib->table)[26], new_song->artist, new_song->name);

  return lib;
}

struct song_node * search_artist(char * artist, struct library * lib) {
  int letter = artist[0];
  if (97 <= letter && letter <= 122) {
    letter -= 97;
  }
  else {
    letter = 26;
  }

  struct song_node * p = lib->table[letter];
  while (p) {
    if (strcmp(p->artist, artist) == 0){
      return p;
    }
    p = p->next;
  }
  return NULL;

}

struct song_node * search_song(char * artist, char * name, struct library * lib) {
  struct song_node * p = search_artist(artist, lib);
  if (!p) {
    return NULL;
  }
  if (strcmp(p->name, name) == 0){
    return p;
  }
  p = p->next;
  return NULL;
}

void print_artist(char * artist, struct library * lib) {
  int letter = artist[0];
  if (97 <= letter && letter <= 122) {
    letter -= 97;
  }
  else {
    letter = 26;
  }

  struct song_node * p = (lib->table)[letter];
  print_list(p);
  while (p) {
    //should print smthing if nothing is found?
    if (strcmp(p->artist, artist) == 0) {
      print_node(p);
      printf("|");
    }
    p = p->next;

  }
}

void print_library(struct library * lib) {
  if (lib != NULL) {
    int i = 0;
    while (i < 26) {
      if (lib->table[i]!=NULL) {
        printf("%c list\n", 97 + i);
        print_list( (lib-> table)[i] );
      }
      i++;
    }
    if ((lib->table)[26] != NULL)
      print_list( (lib->table)[26]);
  }
}

void print_letter(struct library * lib, char c){
  print_list(lib->table[c-97]);
}

void shuffle(struct library * lib){
  int random_length = rand() % 10 + 3;
  int current_length = 0;
  while (random_length != current_length) {
    struct song_node * random_song = (lib->table)[rand()%27];
    if (random_song){
      print_node(random_node(random_song));
      printf("\n");
      current_length++;
    }
  }

}

void delete_song(struct library * lib, char * artist, char * name) {
  int letter = artist[0];
  if (97 <= letter && letter <= 122) {
    letter -= 97;
  }
  else {
    letter = 26;
  }

  lib->table[letter] = remove_node((lib->table)[letter], artist, name);

}

struct library * clear_library(struct library * lib) {
  int i = 0 ;

  while (i < 27) {
    lib->table[i] = free_list((lib->table)[i]);
    i++;
  }
  lib = NULL;
  free(lib);
  return lib;
}
