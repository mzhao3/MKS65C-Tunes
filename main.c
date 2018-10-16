#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "song.h"

int main() {
  struct song_node * foo = insert_order(NULL,"guy","superman");
  foo = insert_order(foo,"fran","medusa");
  foo = insert_order(foo,"milk","water");
  print_list(foo);

  return 0;
}
