struct song_node {
  char name[100];
  char artist[100];
  struct song_node *next;
};

struct song_node * insert_front (struct song_node *, char *, char *);

struct song_node * insert_order (struct song_node *, char *, char *);

void print_list(struct song_node *);

void print_node(struct song_node *);

struct song_node * find_node (struct song_node *, char *, char *);

struct song_node * find_artist (struct song_node *, char *);

struct song_node * random_node(struct song_node *);

int list_length(struct song_node *);

int remove_node(char *, char *);

struct song_node * free_list (struct song_node *);
