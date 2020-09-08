#include <stdio.h>
#include "nets.h"

int main(void) {
  node nodes[3];
  for (int i=0; i<3; i++) {
    nodes[i] = create_node();
  }

  add_dep(&nodes[0], &nodes[1]);
  add_dep(&nodes[0], &nodes[2]);
  add_dep(&nodes[1], &nodes[2]);

  printf("---------------------------------------\n");
  for (int i=0; i<3; i++) {
    print_node(&nodes[i]);
  }

  printf("---------------------------------------\n");
  return 0;
}
