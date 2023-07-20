#include "feed.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// ------------------------- CONSTANTS ---------------------------------

enum { MAX_LEN = 65536 };

// ------------------- PRIVATE IMPLEMENTATION --------------------------

// if the unix stdout is being redirected into a file
// we return true otherwise false. `file` is the result
static bool find_feed(char *const file, const int size) {
  if (isatty(1)) {
    return false;
  }
  char path[32];
  sprintf(path, "/proc/%d/fd/1", getpid());
  size_t _ = readlink(path, file, size);
  return access(file, R_OK) == 0;
}

// ------------------- PUBLIC IMPLEMENTATION ----------------------------

struct entry {
  // TODO: Implement feed_entry data structure (priority: high)
};

struct feed {
  struct entry *entries;
  // TODO: Implement feed data structure (priority: high)
  ;
};

// create a new feed object or exit if malloc failed
struct feed *const create_feed() {
  struct feed *feed = malloc(sizeof(struct feed));
  if (feed == NULL) {
    printf("Memory allocation failed.\n");
    exit(EXIT_FAILURE);
    return NULL;
  }
  char file[MAX_LEN];
  if (find_feed(file, MAX_LEN)) {
    // TODO: Initialize feed using existing feed file (priority: low)
    // NOTE: This may initialize everything except for the entries itself
    ;
  }
  return feed;
}

// read information from unix stdin
// process that information and then
// and write it into the feed data structure
void populate_feed(struct feed *const feed) {
  char input[MAX_LEN];
  if (isatty(fileno(stdin))) {
    printf("Usage: find content/ -print | feedgen\n");
    return;
  }
  int i = 0;
  while (-1 != (input[i++] = getchar()))
    ;
  input[i - 1] = '\0';

  const char delimiter[] = "\n";
  char *word = strtok(input, delimiter);
  while (word != NULL) {
    printf("%s\n", word);
    // TODO: Implement populate_feed (priority: high)
    ;

    word = strtok(NULL, delimiter);
  }
}

// write data from feed struct into output stream
void write_feed(const struct feed *const feed) {
  // TODO: Implement write_feed function (priority: high)
  ;
}

// delete an existing feed object
void delete_feed(struct feed *feed) {
  if (feed != NULL) {
    // TODO: Update the implementation of delete_feed (priority: moderate)
    ;
    free(feed);
  }
}
