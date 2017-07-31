// BSTree.h ... interface to binary search tree ADT
// Written by John Shepherd, March 2013

#ifndef BSTREE_H
#define BSTREE_H

typedef struct BSTNode *BSTree;



typedef void (*Visit)(struct BSTNode *);

typedef struct _url * Url;

typedef struct _list * List;


List newList();
Url newURL(char *s);
List getUrl(FILE *fp);
void addUrl (List l, char * s);
void printList(List l);

void BSTreeInfix (BSTree tree);

BSTree getWord(FILE *fp, BSTree tree, char *url);
BSTree scanWord(BSTree tree, List l);

// create an empty BSTree
BSTree newBSTree();
// free memory associated with BSTree
void dropBSTree(BSTree);



// display a BSTree (sideways)
void showBSTree(BSTree);

// insert a new value into a BSTree
BSTree BSTreeInsert(BSTree, char *s, char *url);
BSTree BSTreeInsertI(BSTree, int);

// check whether a value is in a BSTree
int BSTreeFind(BSTree, int);
// check whether a value is in a BSTree
int BSTreeFindI(BSTree, int);
// compute depth of BSTree
int BSTreeDepth(BSTree);
// count #nodes in BSTree
int BSTreeNumNodes(BSTree);

// generic traversal
void BSTreeTraverse(BSTree, Visit, char *);

//typedef struct _root * RootTree;
//RootTree newTree();

#endif
