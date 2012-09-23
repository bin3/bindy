/*
 * Copyright (c) 2012 Binson Zhang. All rights reserved.
 *
 * @author	Binson Zhang <bin183cs@gmail.com>
 * @date		2012-9-23
 */

#include <iostream>

void test_fseek_set() {
  const char* FILE_NAME = "data.dat";
  size_t TIMES = 10000;
  size_t MAX_FILE = (1 << 30) - 1;
  long offset;
  FILE*fp = NULL;
  long i;

  fp = fopen(FILE_NAME, "r");
  if (!fp) {
    printf("Open file fail.\n");
    exit(-1);
  }

  for (i = 0; i < TIMES; i++) {
    //Because random max is 1<<30 - 1
    offset = random() * 10 % MAX_FILE;
    if (fseek(fp, offset, SEEK_SET)) {
      printf("fseek error.\n");
      printf("%ld", offset);
    }
  }

  fclose(fp);
}

int main(int argc, char **argv) {
  test_fseek_set();
  return 0;
}
