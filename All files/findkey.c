/* =========================================================================
* findkey.c
*
* Created by Mahee Hossain 1080102 (mfhossain@student.unimelb.edu.au)
* 24/08/2020
*
* Takes user inputted key (company name), and searches the dictionary
* created in "readdata.c" for the information, and prints it to output
* file
*
==========================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include "readdata.h"
#include "linkedlist.h"
#include "findkey.h"

void traverse_dictionary(char* argv[], list_t *datas, char *key) {
	/* Goes through dictionary looking for key */
	/* Open files */
	FILE *output_file = fopen(argv[2], "w");
	
	/* Create a new node, check if it and initial list are not NULL */
	node_t *curr = (node_t*)malloc(sizeof(*curr));
	assert(datas!=NULL && curr!=NULL);
	
	/* Traverse the dictionary */
	data_t dA;
	curr = datas->head;
	int resultsFound = 0;
	while(curr!=NULL) {
		dA = curr->data;
		/* Check if the node has the right info, if so print output */
		if (strcasecmp(key, dA[5]) == 0){
			resultsFound++;
			fprintf(output_file, "%s --> ", key);
			fprintf(output_file, PRINT_OUTPUT, dA[0], dA[1], dA[2], dA[3], dA[4],
					dA[6], dA[7], dA[8], dA[9], dA[10]);
		}
		
		curr = curr->next;
	}
	
	/* If no results were found, print so */
	if (resultsFound==0) {
		fprintf(output_file, "%s --> NOTFOUND\n", key);
	}
	
	/* Close files */
	fclose(output_file);
}