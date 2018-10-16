#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "song.h"

int main() {
  struct song_node * foo = insert_order(NULL,"guy","superman");
  foo = insert_order(foo,"fran","medusa");
  foo = insert_order(foo,"milk","water");
  foo = insert_order(foo,"milk","bread");
  foo = insert_order(foo,"milk","wechat");
  print_list(foo);
  struct song_node * find = get_song(foo,"fran","medusa");
  if (find) {
    printf("Song found: %s : %s\n",find->artist,find->name);
  }
  struct song_node * find2 = get_song(foo,"milk","bred");
  if (find2) {
    printf("Song found: %s : %s\n",find2->artist,find2->name);
  }


  return 0;
}
