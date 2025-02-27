/*
 * Name: Colton Owenby
 * Date Submitted: 10/23/2023
 * Lab Section: 001
 * Assignment Name: Lab 7
 * Email: coltono@clemson.edu
 */
#include <stdio.h>

struct NODE{
    int a;
    struct NODE *b;
    struct NODE *c;
}nodes[5] = {
                {15,    nodes + 2,  nodes + 1},
                {30,    nodes + 3,  NULL},
                {46,    nodes + 1,  nodes + 4},
                {95,    nodes + 4,  nodes},
                {123,    NULL, nodes + 2}
    };
struct NODE* np = nodes + 4;
struct NODE** npp = &nodes[2].b;

int main()
{
  printf("nodes \t\t %p\n", nodes);
  //printf("nodes.a \t %d\n", nodes.a);
  printf("nodes[3].a \t %d\n", nodes[3].a);
  printf("nodes[3].c \t %p\n", nodes[3].c);
  printf("nodes[3].c->a \t %d\n", nodes[3].c->a);
  //printf("*nodes.a \t Error\n");
  printf("(*nodes).a \t %d\n", (*nodes).a);
  printf("nodes->a \t %d\n", nodes->a);
  printf("nodes[3].b->b \t %p\n", nodes[3].b->b);
  printf("&nodes[3].a \t %p\n", &nodes[3].a);
  printf("&nodes[3].c \t %p\n", &nodes[3].c);
  printf("&nodes[3].c->a \t %d\n", nodes[3].c->a);
  printf("&nodes->a \t %p\n", &nodes->a);

  printf("np \t\t %p\n", np);
  printf("np->a \t\t %d\n", np->a);
  printf("np->c->c->a \t %d\n", np->c->c->a);

  printf("npp \t\t %p\n", npp);
  //printf("npp->a \t\t %d\n", npp->a);
  printf("*npp \t\t %p\n", *npp);
  //printf("*npp->a \t %d\n", *npp->a);
  printf("(*npp)->a \t %d\n", (*npp)->a);

  printf("&np \t\t %p\n", &np);
  printf("&np->a \t\t %p\n", &np->a);
  printf("&np->c->c->a \t %p\n", &np->c->c->a);
  return 0;

}
