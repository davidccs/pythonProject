#include <stdio.h>
#include <stdlib.h>
#include <graph.h>

// array of edges representation
typedef struct GraphRep {
	int   nV;    // #vertices
	int   nE;    // #edges
	int   n;     // size of edge array
	Edge *edges; // array of edges
} GraphRep;

// make a graph first

Graph newGraph(int nV){
    Graph g = malloc(sizeof(struct GraphRep));

    int *e = malloc(sizeof(int *)* nV);
    g->nV = nV;
    g->nE = 0;
    g->edges = e;
}



int main (){

    return 0;
}
