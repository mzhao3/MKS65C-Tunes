#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "song.h"
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

void test_remove(struct song_node * head, char * artist_name, char * song_name){

}

int main() {
  srand(time(NULL));
  struct song_node * bar = insert_order(NULL,"Maroon 5","Girls Like You");
  bar = insert_order(bar,"Taylor Swift","Blank Space");
  bar = insert_order(bar,"Taylor Swift","Shake It Off");
  bar = insert_order(bar,"Taylor Swift","Bad Blood");
  bar = insert_order(bar,"Ariana Grande","One Last Time");
  bar = insert_order(bar,"Ariana Grande","God is a women");
  bar = insert_order(bar,"Ariana Grande","One Last Time");
  bar = insert_order(bar,"Marshmello","Alone");
  bar = insert_order(bar,"Lil Pump","Gucci Gang");
  bar = insert_order(bar,"Rick Astley","Never Gonna Give You Up");
  printf("SONG NODE TEST\n======================\n\n");
  printf("Testing print_list:\n");
  print_list(bar);
  printf("\n======================\n\n");

  printf("Testing print_node:\n");
  print_node(bar->next);
  printf("\n");
  printf("\n======================\n\n");

  printf("Testing find_node:\n");
  printf("Looking for [Lil Pump: Gucci Gang]\n");
  test_find(find_node(bar,"Lil Pump","Gucci Gang"));
  printf("\n");
  printf("Looking for [David Holmes: Java Man]\n");
  test_find(find_node(bar,"David Holmes","Java Man"));
  printf("\n======================\n\n");

  printf("Testing find_artist:\n");
  printf("Looking for [Marshmello]\n");
  test_artist(find_artist(bar, "Marshmello"));
  printf("Looking for [Donald Trump]\n");
  test_artist(find_artist(bar, "Donald Trump"));
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
  printf("Removing [Taylor Swift: Shake It Off]");
  test_remove(bar,"Taylor Swift","Shake It Off");
  printf("\n======================\n\n");
  return 0;
}
