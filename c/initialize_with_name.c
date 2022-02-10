/*
 * To verify if a struct initializer can use name on left side.
 * This usage is learnt from linux kernel's LIST_HEAD macro.
*/

#include <stdio.h>

struct list_head {
    struct list_head *prev, *next;
};

int main(int argc, char* argv[]) {
    struct list_head h = {&h, &h};

    printf("Address of h is: %p\n", &h);
    printf("Address of prev is: %p\n", h.prev);
    printf("Address of next is: %p\n", h.next);
}
