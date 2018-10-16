struct song_node {
  char name[100];
  char artist[100];
  struct song_node *next;
};

struct song_node * insert_front (struct song_node * head, char* new_name, char* new_artist);

struct song_node * insert_order (struct song_node * head, char * name, char * artist);

void print_list (struct song_node * front);

struct song_node * get_song(struct song_node * head, char * artist_name, char * song_name );

struct song_node * first_song(char * artist);

int remove_node (char * name, char * artist);

struct song_node * free_list (struct song_node * start);
