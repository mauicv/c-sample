#ifndef _NETS_H_
#define _NETS_H_

typedef struct node_tag {
  int id;
  int num_deps;
  int num_targs;
  struct node_tag** deps;
} node;

void add_dep(node *source, node *target);
void print_node(node *n);
node create_node(void);

#endif
