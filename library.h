#ifndef __library__
#define __library__
struct library { struct song_node * table[27]; };

struct library* make_lib();

struct library* add_song(struct song_node *, struct library *);

struct song_node * find(char *, char *, struct library * );

struct song_node * search_artist(char *, struct library * );

void print_artist(char * , struct library * );

void print_library(struct library *);

void print_letter(struct library *, char);

void shuffle(struct library * );

void remove_song(struct library *, char *, char *);

struct library * clear_library(struct library *);
#endif
