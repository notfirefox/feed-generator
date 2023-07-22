#include "feed.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

enum { MAX_LEN = 65536 };

struct entry {
  const char *const title;
  const char *const updated;
  const char *const id;
  const char *const summary;
};

struct feed {
  const char *const title;
  const char *const author;
  const char *const updated;
  const char *const link;
  struct entry *entries;
  int size;
};

struct feed *const create_feed() {
  struct feed *feed = malloc(sizeof(struct feed));
  if (feed == NULL) {
    printf("Memory allocation failed.\n");
    exit(EXIT_FAILURE);
    return NULL;
  }
  const struct feed temp = {"TITLE_PLACEHOLDER",
                            "AUTHOR_PLACEHOLDER",
                            "UPDATED_PLACEHOLDER",
                            "LINK_PLACEHOLDER",
                            NULL,
                            0};
  memcpy(feed, &temp, sizeof(struct feed));
  return feed;
}

void populate_feed(struct feed *const feed) {
  char input[MAX_LEN];
  if (isatty(fileno(stdin))) {
    printf("Usage: find content/ -print | feedgen\n");
    exit(EXIT_SUCCESS);
    return;
  }
  int i = 0;
  while (-1 != (input[i++] = getchar()))
    ;
  input[i - 1] = '\0';

  const char delimiter[] = "\n";
  char *word = strtok(input, delimiter);
  while (word != NULL) {
    // printf("%s\n", word);
    // TODO: Implement populate_feed (priority: high)
    ;

    word = strtok(NULL, delimiter);
  }
}

void write_feed(const struct feed *const feed) {
  printf("<?xml version=\"1.0\" encoding=\"utf-8\"?>\n");
  printf("<feed xmlns=\"http://www.w3.org/2005/Atom\">\n");

  printf("  <title>%s</title>\n", feed->title);
  printf("  <author>\n");
  printf("    <name>%s</name>\n", feed->author);
  printf("  </author>\n");
  printf("  <updated>%s</updated>\n", feed->updated);
  printf("  <link>%s</link>\n", feed->link);

  for (int i = 0; i < feed->size; i++) {
    printf("  <entry>\n");
    printf("    <title>ENTRY_TITLE</title>\n");
    printf("    <updated>ENTRY_UPDATED</updated>\n");
    printf("    <id>ENTRY_ID</id>\n");
    printf("    <summary>ENTRY_SUMMARY</summary>\n");
    printf("  </entry>\n");
  }

  printf("</feed>\n");
}

void delete_feed(struct feed *feed) {
  if (feed != NULL) {
    free(feed);
  }
}
