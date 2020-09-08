#include <stdio.h>
#include <stdlib.h>
#include "nets.h"

void add_dep(node *source, node *target){
  if (source -> deps == NULL) {
    node *node_mem_ptr = malloc(sizeof(node));
    node **mem_arr = malloc(sizeof(node_mem_ptr));
    *mem_arr = node_mem_ptr;
    *node_mem_ptr = *target;
    source -> deps = mem_arr;
    target -> num_deps = 0;
    source -> num_targs = 0;
  } else {
    node *node_mem_ptr = malloc(sizeof(node));
    node **mem_arr = realloc(source -> deps,
      sizeof(node) * (source -> num_targs + 1));
    *node_mem_ptr = *target;
    mem_arr[source -> num_targs + 1] = node_mem_ptr;
    source -> deps = mem_arr;
    target -> num_deps++;
    source -> num_targs++;
  }
}

void print_node(node *n) {
  if (n -> deps == NULL) return;

  printf("node %d is connected to nodes [", n -> id);
  for (int i=0; i <= n -> num_targs; i++) {
    printf(" %d ", n -> deps[i] -> id);
  }
  printf("] \n");
}

node create_node(void) {
  static int id = 0; id++;
  node n;
  n.id = id;
  n.num_deps = 0;
  n.deps = NULL;
  return n;
}
