#include "test.h"
#include "../sequence/LinkedList.h"
#include <stdio.h>
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"
#define CHECK "\u2705"
#define X     "\u274c"

void print_(int *a, int length, int ith){
	for (size_t i = 0; i < length; i++) {
		if (i == ith) {
			printf(RED "%d " RESET, a[i]);
			continue;
		}
		printf("%d ", a[i]);
	}
	putc('\n', stdout);
}
 

void print_list(LinkList L, int i){	
	LinkList p = L->next;
	while (p) {
		printf("%d ", p->data);
		p = p->next;
	}
	putc('\n', stdout);
}

void assert_array(int *a, int *b, int size, const char* str){
	for (int i = 0; i < size; i++) {
		if (a[i] != b[i]){
			printf(RED "=============================================>\n" RESET);
			printf("%s " RED "failed " X "\n" RESET, str);
			puts("Expected: ");print_(a, size, i);
			puts("Your result: ");print_(b, size, i);
			return;
		}
	}
	printf(CYN "=============================================>\n" RESET);
	printf("%s " BLU "passed " CHECK "\n" RESET, str);
}

void assert_equal(int a, int b, const char *str){
	if(a == b) printf("%s passed " CHECK "\n", str);
	else {
		printf(RED "=============================================>\n" RESET);
		printf("%s " RED "failed " X "\n" RESET, str);
		printf("Expected: %d\n", a);		
		printf("Your result: %d\n", b);
	}
}

void assert_list(int *arr, int length, LinkList list, const char* str){
	LinkList p = list->next;
	for (int i = 0; i < length; i++) {
		if (p == NULL || arr[i] != p->data){
			printf(RED "=============================================>\n" RESET);
			printf("%s " RED "failed " X "\n" RESET, str);
			puts("Expected: "); print_(arr, length, i);
			puts("Your result: "); print_list(list, i);
			return;
		}
		p = p->next;
	}
	printf(CYN "=============================================>\n" RESET);
	printf("%s " BLU "passed " CHECK "\n" RESET, str);
}
