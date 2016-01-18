#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>



int main (int argc, char *argv[])
{
  typedef struct CELL *LIST;
  /* This defines a struct CELL which contains an integer and a LIST, which is a pointer to another CELL. */


  /* This defines a type LIST which is a pointer t a CELL */

  struct CELL {
    int val;
    LIST next;
  };

  LIST stack = (LIST) malloc(sizeof(struct CELL));
  /* In C, variable definitions allocate memory.  Declarations, however, do not.  The "extern" keyword makes a variable available to the program without allocating any memory for it. */

  void push(int val) {
    LIST c = (LIST) malloc(sizeof(struct CELL));
    if (c) {
      c->val = val;
      c->next = stack;
      stack = c;
    }
    else { /* handle error */ }
  }

  int pop() {
    int x = stack->val;
    LIST c = stack->next;
    free(stack);
    stack = c;
    return x;
  }

  stack->val = 0;
  stack->next = (LIST) malloc(sizeof(LIST));

  void print_stack() {
    while(stack->next != NULL) {
      printf("%d\n", stack->val);
      pop();
    }
  }

  char *buffer;
  int state = 1;

  while(state != 0) {

    scanf("%s", buffer);

    int count = 0;

    for (count = 0; count <= sizeof(buffer); count++) {

      if (isdigit(buffer[count])) {
	push(atoi(&buffer[count]));

      };

      if (buffer[count] == 'p') {
	int y = pop();
	printf("%d\n", y);
	push(y);

      };

      if (buffer[count] == 'f') {
	print_stack();
      };      

      if (buffer[count] == 'c') {};	

      if (buffer[count]  == 'q') {state = 0;};
    }

  }
  return 0;
}

      
