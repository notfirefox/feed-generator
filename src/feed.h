#include <stdbool.h>

// forward declaration
struct feed;

// create a new feed
struct feed *const create_feed();

// populate an existing feed with data
void populate_feed(struct feed *const);

// write an existing feed
void write_feed(const struct feed *const);

// delete an existing feed
void delete_feed(struct feed *);
