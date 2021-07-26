#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "linkedlist.h"
#include "readdata.h"
#include "findkey.h"

int main(int argc, char* argv[]) {
	/* Make a linked list to fill with the information, and a string for the key */
	list_t *datas = make_empty_list();
	char *key = (char*)malloc(sizeof(char)*MAX_FIELD_LEN);
	assert(key!=NULL);
	
	/* Fill the linked list */
	fill_list(argv, datas);
	
	/* Get key from user */
	printf("Input key (company name): ");
	scanf("%[^\n]s", key);
	
	/* Search the dictionary for the key */
	traverse_dictionary(argv, datas, key);
	
	/* Free key and datas (linked list) */
	free(key);
	free_list(datas);
	
	return 0;
}