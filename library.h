struct library { struct song_node * table[27]; };

struct library* make_lib();

struct library* add_song(struct song_node *, struct library *);

struct song_node * search_song(char *, char *, struct library * );

struct song_node* search_artist(char *, struct library * );

void print_artist(char * , struct library * );

void print_library(struct library *);

void shuffle(struct library * );

void delete_song(struct song_node *, struct library * );

struct library * clear_library(struct library *);
