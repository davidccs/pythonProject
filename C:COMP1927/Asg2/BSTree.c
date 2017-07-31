// BSTree.h ... implementation of binary search tree ADT
// Written by John Shepherd, March 2013

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include "BSTree.h"

#define size 20

typedef struct BSTNode *Link;

typedef struct BSTNode {

	char word[size];
	Link left, right;
	struct _url * urlList;

} BSTNode;

struct _url {
	char url[size];
	struct _url * next;
};

struct _list {
	struct _url * head;
};

//LOCAL FUNCTION
Link newBSTNode(char *s, char *url);

//------END LOCAL FUNCTION

List newList() {

	//Create a new list
	List l = malloc(sizeof(struct _list));
	l->head = NULL;
	return l;
}

//create url
Url newURL(char *s) {
    
    //in case s is url## already
    if (s[0] == 'u') {
    	Url new = malloc(sizeof(struct _url));
    	strcpy(new->url,s);
    	new->next = NULL;
    	return new;
    }

	Url new = malloc(sizeof(struct _url));

	char t[size];
	strcpy(t,"url");
	strcat(t,s);
	strcpy(new->url,t);

	new->next = NULL;

	int i;

    //this loop delete space or new line int the string of URL
    for (i = 0; i < size; i++) {
        if(isdigit(new->url[i]) || isalpha(new->url[i] )) {
        	continue;
        }
        else {
        	new->url[i] = '\0';
        	break;
        }
        
    }
    return new;

}

// scan URL return list
List getUrl(FILE *fp) {

	List list = newList();

	char line[1024];

	char s[size];

	char *token;

	while (!feof(fp)) {

		fgets(line,1024,fp);
		token = strtok(line,"url");

		while (token != NULL) {

			//printf("%s\n",token);

			int val = atoi(token);

			if (val != 0) {
				printf("%s===================\n",token);
				strcpy(s,token);
				addUrl(list,s);
			}

			token = strtok(NULL, "url");
		}

	}
	return list;
}

void addUrl (List l, char * s) {

	Url new = newURL(s);

	if ( l->head == NULL) {
		l->head = new;
		
	}
	else {
		Url curr = l->head;
		while ( curr->next != NULL) {
			curr = curr->next;
		}
		if (curr->next == NULL) {
			curr->next = new;
			
		}
	}

}

void printList(List l) {
	Url curr = l->head;
	while ( curr != NULL) {
		printf("%s\n",curr->url);
		curr = curr->next;
	}
}
BSTree getWord(FILE *fp, BSTree tree, char *url) {

	char line[1024];

	char *token;

	//count 'hastag' # encountered in a file.
	int sectionCount = 0;

	while (!feof(fp)) {

		fgets(line,1024,fp);

		if (line[0] == '#') {
			sectionCount++;
		}

		//Meaning: only start string token when 3rd # reached
		if (sectionCount < 3) continue;

		//when the 4th # reach, can stop scanning
		if (sectionCount == 4) break;

		//printf("%s",line);

		//dont scan: #start Section
		if (line[0] == '#') continue;
		token = strtok(line," ");

		while (token != NULL) {

			if (strlen(token) > 1) {
				Link newL = newBSTNode(token,url);
				//assert(newL!= NULL);
				tree = BSTreeInsert(tree, newL->word, url);
			}

			token = strtok(NULL, " ");
		}
		

	}
	//assert (tree != NULL);
	return tree;
	
}
BSTree scanWord(BSTree newT, List l) {

	Url curr = l->head;

	FILE *fp;

	while ( curr != NULL) {

		//the next few lines of code is to make: temp = url##.txt
		char temp[size];
		strcpy(temp,curr->url);
		strcat(temp,".txt");

		//printf("%s---------------------------------\n",curr->url);

		if ( (fp = fopen(temp,"r")) != NULL) {
			newT = getWord(fp, newT, curr->url);
		}

		curr = curr->next;
	}

	return newT;
}

// make a new node containing a value
Link newBSTNode(char *s, char *url)
{
	Link new = malloc(sizeof(BSTNode));
	assert(new != NULL);

	strcpy(new->word,s);

	int i; 

	for (i = 0; i < size; i++) {
		if (isalpha(new->word[i])) continue;
		new->word[i] = '\0';
		break;
	}

	for ( i = 0; new->word[i] != '\0'; i++) {
		new->word[i] = tolower(new->word[i]);
	}

	printf("%s\n",new->word);

	Url newLink = newURL(url);

	new->left = NULL;
	new->right = NULL;
	new->urlList = newLink;
	
	return new;
}

// create a new empty BSTree
BSTree newBSTree()
{
	return NULL;
}

// free memory associated with BSTree
void dropBSTree(BSTree t)
{
	if (t == NULL)
		/* do nothing */;
	else {
		dropBSTree(t->left);
		dropBSTree(t->right);
		free(t);
	}
}

void BSTreeInfix (BSTree t) {
	
	if ( t == NULL) {
		return;
	}

	//explore left subtree
	BSTreeInfix(t->left);

	//print node and its url
	printf("%s:  ", t->word);

	Url curr = t->urlList;

	while ( curr != NULL) {
		printf(" %s ->",curr->url);
		curr = curr->next;
	}

	printf("\n");

	//explore right subtree
	BSTreeInfix(t->right);

}


void showBSTree(BSTree t)
{
	if (t == NULL) {
		return;
	}
	printf("%s: ",t->word);
	Url curr = t->urlList;
	while ( curr != NULL) {
		printf("%s -> ", curr->url);
		curr = curr->next;
	}
	printf("\n");
}

// compute depth of BSTree
int BSTreeDepth(BSTree t)
{
	if (t == NULL)
		return 0;
	else {
		int ldepth = BSTreeDepth(t->left);
		int rdepth = BSTreeDepth(t->right);
		//return 1 + (ldepth > rdepth)?ldepth:rdepth;
		if (ldepth > rdepth)
			return 1+ldepth;
		else
			return 1+rdepth;
	}
}

// count #nodes in BSTree
int BSTreeNumNodes(BSTree t)
{
	if (t == NULL)
		return 0;
	else
		return 1 + BSTreeNumNodes(t->left)
		         + BSTreeNumNodes(t->right);
}

// check whether a value is in a BSTree
int BSTreeFind(BSTree t, int v)
{	
	/*
	if (t == NULL)
		return 0;
	else if (v < t->value)
		return BSTreeFind(t->left, v);
	else if (v > t->value)
		return BSTreeFind(t->right, v);
	else // (v == t->value)
	*/
		return 1;
}

int BSTreeFindI(BSTree t, int v)
{
	/*
	Link cur;
	cur = t;
	while (cur != NULL) {
		if (v < cur->value)
			cur = cur->left;
		else if (v > cur->value)
			cur = cur->right;
		else // (v == cur->value)
			return 1;
	}
	*/
	return 0;
}

// insert a new value into a BSTree
BSTree BSTreeInsert(BSTree t, char *s, char *url)
{

	if ( t == NULL) {
		
		t = newBSTNode(s,url);
	}
	else if ( strcmp(t->word,s) < 0 ) {
		//right subtree
		t->right = BSTreeInsert(t->right, s, url);
	}
	else if (strcmp(t->word,s) > 0) {
		//left subtree
		t->left = BSTreeInsert(t->left, s, url);
	}
	
	else if (strcmp(t->word,s) == 0 ) {
		
		Url curr = t->urlList;
		Url new = newURL(url);
		assert(curr != NULL);
		assert(new!=NULL);
		
		while(curr->next != NULL && strcmp(curr->url,url) != 0) {
			curr = curr->next;
		}
		if (curr->next == NULL) {
			curr->next = new;
		}
		
	
	}
	
	return t;

	/*
	if (t == NULL)
		t = newBSTNode(v);
	else if (v < t->value)
		t->left = BSTreeInsert(t->left, v);
	else if (v > t->value)
		t->right = BSTreeInsert(t->right, v);
	*/
}

BSTree BSTreeInsertI(BSTree t, int v)
{
	/*
	Link cur, parent;
	if (t == NULL) return newBSTNode(v);
	cur = t; parent = NULL;
	while (cur != NULL) {
		parent = cur;
		if (v < cur->value)
			cur = cur->left;
		else if (v > cur->value)
			cur = cur->right;
		else
			return t;
	}
	Link new = newBSTNode(v);
	if (v < parent->value)
		parent->left = new;
	else
		parent->right = new;
	*/
	return t;
}


/*

struct _root {
	Link root;
};

RootTree newTree() {

	RootTree newT = malloc(sizeof(struct _root));
	newT->root = NULL;
	return newT;
}
*/

/*
// generic traversal
void BSTreeTraverse(BSTree t,
				    Visit visit,
                    //void (*visit)(struct BSTNode *),
                    char *style)
{
	if (t == NULL) return;
	if (strcmp(style,"NLR") == 0) (*visit)(t);
	BSTreeTraverse(t->left, visit, style);
	if (strcmp(style,"LNR") == 0) (*visit)(t);
	BSTreeTraverse(t->right, visit, style);
	if (strcmp(style,"LRN") == 0) (*visit)(t);
}
*/


// Pretty tree printer

