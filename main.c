#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

// menu
// 1. Udon 120/1
// 2. Karage 80/1
// 3. Tap_water 10/1

int main(int argc, char * argv[]) {

    Queue q;
    int count = 0;
    q.size = 0;
    q.headPtr = NULL;
    q.tailPtr = NULL;

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == 'x') {
            dequeue_struct(&q);
        }
        else {
            count++;
            enqueue_struct(&q, count, atoi(argv[i]), atoi(argv[i+1]));
            i++;
        }
    }

    // print_queue(q);

    printf("=========================================\n");

    if (q.size != 0) {
        printf("There are %d ppl left in the queue\n", q.size);
    }

    return 0;
}