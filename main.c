#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "song.h"
#include "library.h"
#include <time.h>

void test_find(struct song_node * head){
  if (head) {
    printf("Node Found: ");
    print_node(head);
  }
  else {
    printf("Node Not Found.\n");
  }
}

void test_artist(struct song_node * head){
  if (head) {
    printf("Artist Found: ");
    print_list(head);
  }
  else {
    printf("Artist Not Found.\n");
  }
}

void test_search_song(struct library * lib, char * artist, char * name){
  struct song_node * song = search_song(artist,name,lib);
  if (song){
    printf("song found! ");
    print_list(song);
  }
  else {
    printf("song not found\n");
  }
}

void test_search_artist(struct library * lib, char * artist) {
  struct song_node * song = search_artist(artist,lib);
  if (song) {
    printf("artist found! ");
    print_list(song);
  }
  else {
    printf("song not found\n");
  }
}

int main() {
  srand(time(NULL));
  struct song_node * bar = insert_order(NULL,"maroon 5","girls like you");
  bar = insert_order(bar,"taylor swift","blank space");
  bar = insert_order(bar,"taylor swift","shake it off");
  bar = insert_order(bar,"taylor swift","bad blood");
  bar = insert_order(bar,"ariana grande","one last time");
  bar = insert_order(bar,"ariana grande","god is a women");
  bar = insert_order(bar,"marshmello","alone");
  bar = insert_order(bar,"lil pump","gucci gang");
  bar = insert_order(bar,"rick astley","never gonna give you up");
  printf("SONG NODE TEST\n======================\n\n");
  printf("Testing print_list:\n");
  print_list(bar);
  printf("\n======================\n\n");

  printf("Testing print_node:\n");
  print_node(bar->next);
  printf("\n");
  printf("\n======================\n\n");

  printf("Testing find_node:\n");
  printf("Looking for [lil pump: gucci gang]\n");
  test_find(find_node(bar,"lil pump","gucci gang"));
  printf("\n");
  printf("Looking for [david holmes: java man]\n");
  test_find(find_node(bar,"david holmes","java man"));
  printf("\n======================\n\n");

  printf("Testing find_artist:\n");
  printf("Looking for [marshmello]\n");
  test_artist(find_artist(bar, "marshmello"));
  printf("Looking for [donald trump]\n");
  test_artist(find_artist(bar, "donald trump"));
  printf("\n======================\n\n");

  printf("Testing random_node:\n");
  print_node(random_node(bar));
  printf("\n");
  print_node(random_node(bar));
  printf("\n");
  print_node(random_node(bar));
  printf("\n");
  print_node(random_node(bar));
  printf("\n======================\n\n");

  printf("Testing remove_node:\n");
  printf("Removing [taylor swift: shake it off]\n");
  bar = remove_node(bar,"taylor swift","shake it off");
  print_list(bar);
  printf("\n======================\n\n");

  printf("Testing free_list:\n");
  bar = free_list(bar);
  printf("List after free_list:\n");
  print_list(bar);
  printf("======================\n\n");

  printf("====================================\n\nMUSIC LIBRARY TESTS\n\n====================================\n\n");

  struct song_node * bar2 = insert_order(NULL,"maroon 5","girls like you");
  bar2 = insert_order(bar2,"taylor swift","blank space");
  bar2 = insert_order(bar2,"taylor swift","shake it off");
  bar2 = insert_order(bar2,"taylor swift","bad blood");
  bar2 = insert_order(bar2,"ariana grande","one last time");
  bar2 = insert_order(bar2,"ariana grande","god is a women");
  bar2 = insert_order(bar2,"adele","hello");
  bar2 = insert_order(bar2,"marshmello","alone");
  bar2 = insert_order(bar2,"lil pump","gucci gang");
  bar2 = insert_order(bar2,"rick astley","never gonna give you up");
  struct library * foo = make_lib();
  while(bar2){
    foo = add_song(bar2,foo);
    bar2 = bar2->next;
  }

  printf("Testing print_library:\n");
  print_library(foo);
  printf("\n======================\n\n");

  printf("Testing print_letter:\n");
  print_letter(foo,'t');
  printf("\n======================\n\n");

  printf("Testing print_letter:\n");
  print_letter(foo,'t');
  printf("\n======================\n\n");

  printf("Testing search_song:\n");
  printf("Looking for [marshmello: alone]\n");
  test_search_song(foo,"marshmello","alone");
  printf("Looking for [ariana grande: god is a women]\n");
  test_search_song(foo,"ariana grande","god is a women");
  printf("Looking for [ariana grande: sing a lot]\n");
  test_search_song(foo,"ariana grande","sing a lot");
  printf("Looking for [donald trump: sing not enough]\n");
  test_search_song(foo,"donald trump","sing not enough");
  printf("\n======================\n\n");

  printf("Testing search_artist:\n");
  printf("Looking for [taylor swift]\n");
  test_search_artist(foo,"taylor swift");
  printf("Looking for [maroon 5]\n");
  test_search_artist(foo,"maroon 5");
  printf("Looking for [harry styles]\n");
  test_search_artist(foo,"harry styles");
  printf("\n======================\n\n");

  return 0;
}
