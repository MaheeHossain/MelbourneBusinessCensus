#ifndef READDATA
#define READDATA

#include "linkedlist.h"

#define PRINT_ALL_INFO "Census year: %s || Block ID: %s || Property ID: %s || Base Property ID: %s || CLUE \
small area: %s || Trading Name: %s || Industry (ANZSIC4) code: %s || Industry (ANZSIC4) \
description: %s || x coordinate: %s || y coordinate: %s || Location: %s ||\n\n"
#define MAX_FIELD_LEN 128
#define MAX_LINE_LEN 512
#define FIELDS_NUM 13

void fill_list(char* argv[], list_t *datas);

void print_data_linked_list(char* argv[], list_t *datas);

void internal_comma_token(char *token, char *rest);

#endif