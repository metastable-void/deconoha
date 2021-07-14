// vim: ts=2 sw=2 et ai

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  if (argc < 2) {
    printf("Usage:\n%s filename\n", argv[0]);
    return 1;
  }
  char *filename = argv[1];
  FILE *fp = fopen(filename, "r");
  char buffer[2];
  size_t pos = 0;
  fprintf(stderr, "hash (hex): ");
  char mask0 = (char) 0;
  scanf("%hhx", &mask0);
  while (!feof(fp)) {
    size_t read = fread(buffer, 1, 1, fp);
    if (read < 1) continue;
    if (pos & 1) {
      buffer[0] ^= (char) (255 & pos);
    } else {
      buffer[0] ^= mask0;
    }
    fwrite(buffer, 1, 1, stdout);
    pos += read;
  }
  fclose(fp);
  return 0;
}
