#include "feed.h"

int main(int argc, const char *argv[]) {
  struct feed *feed = create_feed();
  populate_feed(feed);
  write_feed(feed);
  delete_feed(feed);

  return 0;
}
