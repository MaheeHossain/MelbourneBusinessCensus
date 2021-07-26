/* =========================================================================
* readdata.c
*
* Created by Mahee Hossain 1080102 (mfhossain@student.unimelb.edu.au)
* 24/08/2020
*
* Reads csv file, and fills pre-made linked list with it. Function to 
* print linked list data included
*
==========================================================================*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "readdata.h"
#include "linkedlist.h"

void fill_list(char* argv[], list_t *datas) {
	/* Fill the linked list with the input from a csv file */
	
	/* Open both input and output files (they are arguments in the makefile) */
	FILE *input_file = fopen(argv[1], "r");
	
	/* Check if input file is empty */
	if (input_file == NULL) {
		printf("Input file is empty");
		exit(EXIT_FAILURE);
	}
	
	/* Create a line to put the info in */
	char *line = (char*)malloc(sizeof(char)*MAX_LINE_LEN);
	assert(line!=NULL);
	
	/* Get first line out of the way */
	fgets(line, MAX_LINE_LEN, input_file);
	
	while(fgets(line, MAX_LINE_LEN, input_file)) {
		int fieldNum=0;
		
		/* Initialise a 2D array to place line into */
		char **dataArray = (char**)malloc(sizeof(char*)*FIELDS_NUM); //not freed
		assert(dataArray!=NULL);
		
		/* Split the line by commas (ignoring extra commas for now) */
		for(char *token=strtok(line, ","); token != NULL; token=strtok(NULL, ",")) {
			
			/* Check if its a quote (means has comma inside) */
			if (token[0] == '\"'){ 
				internal_comma_token(token++, strtok(NULL, "\""));
			}
			
			/* Initialise the internal arrays for the tokens */
			dataArray[fieldNum] = (char*)malloc(sizeof(char)*MAX_FIELD_LEN); //not freed
			assert(dataArray[fieldNum]!=NULL);
			
			/* Fill 2D array with the the tokens */
			strcpy(dataArray[fieldNum++], token);
		}
		
		/* Place the 2D array inside the linked list */
		insert_at_foot(datas, dataArray);
	}
	
	/* Free line */
	free(line);
	
	/* Close files */
	fclose(input_file);
}

void print_data_linked_list(char* argv[], list_t *datas){
	/* Print the linked list filled with the data from the csv file */
	/* Open output file */
	FILE *output_file = fopen(argv[2], "w");
	
	/* Create a new node, check if it and initial list are not NULL */
	node_t *curr = (node_t*)malloc(sizeof(*curr));
	assert(datas!=NULL && curr!=NULL);
	
	/* Traverse the linked list with the node,
	   printing each node as it goes along */
	data_t dataArr;
	curr = datas->head;
	
	while (curr != NULL) {
		
		dataArr = curr->data;
		fprintf(output_file, PRINT_ALL_INFO, dataArr[0], dataArr[1], dataArr[2],
				dataArr[3], dataArr[4], dataArr[5], dataArr[6], dataArr[7],
				dataArr[8], dataArr[9], dataArr[10]);
		curr = curr->next;
	}
	
	/* Free node */
	free(curr);
	
	/* Close files */
	fclose(output_file);
}

void internal_comma_token(char *token, char *rest) {
	/* When the token in a line starts with a quote, have to construct the
	   token differently, including the comma inside */
	char newToken[MAX_FIELD_LEN];
	strcpy(newToken, rest);
	strcat(token, ",");
	strcat(token, newToken);
}