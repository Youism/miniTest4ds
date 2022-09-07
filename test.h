#ifndef TEST_H
#define TEST_H 
#include "../sequence/LinkedList.h"
#include <stdbool.h>
void assert_equal(int a, int b, const char* str);
void assert_array(int *a, int *b, int size, const char* str);
void assert_list(int *a, int, LinkList, const char*);

#endif // !TEST_H
#define TEST_H 

