#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "song.h"

int main() {
  printf("Testing print_list\n");
  struct song_node * foo = insert_order(NULL,"guy","superman");
  foo = insert_order(foo,"fran","medusa");
  foo = insert_order(foo,"milk","water");
  foo = insert_order(foo,"milk","bread");
  foo = insert_order(foo,"milk","wechat");
  print_list(foo);
  printf("\nTesting find_node\n");
  struct song_node * find = find_node(foo,"fran","medusa");
  if (find) {
    printf("Song found: %s : %s\n",find->artist,find->name);
  }
  struct song_node * find2 = find_node(foo,"milk","bred");
  if (find2) {
    printf("Song found: %s : %s\n",find2->artist,find2->name);
  }
  printf("Testing find_artist\n");
  struct song_node * find_artist1 = find_artist(foo,"fra");
  if (find_artist1) {
    printf("Arist found: ");
    print_list(find_artist1);
    printf("\n");
  }

  return 0;
}
