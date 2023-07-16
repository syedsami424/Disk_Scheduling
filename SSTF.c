#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

int sstf(int req[], int size, int head) {
    int seek_time = 0;
    int current = head;

    bool visited[size];
    int i;
    for (i = 0; i < size; i++) {
        visited[i] = false;
    }

    for (i = 0; i < size; i++) {
        int min_seek = INT_MAX;
        int min_index = -1;
		int j;
        for (j = 0; j < size; j++) {
            if (!visited[j]) {
                int distance = abs(current - req[j]);
                if (distance < min_seek) {
                    min_seek = distance;
                    min_index = j;
                }
            }
        }

        visited[min_index] = true;
        seek_time += min_seek;
        current = req[min_index];
    }

    return seek_time;
}

int main() {
    int size, head;

    printf("Enter the number of requests: ");
    if (scanf("%d", &size) != 1) {
        printf("Invalid input. Exiting...\n");
        return 1;
    }

    int* req = malloc(size * sizeof(int));
    if (req == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }

    printf("Enter the request queue:\n");
    int i;
    for (i = 0; i < size; i++) {
        if (scanf("%d", &req[i]) != 1) {
            printf("Invalid input. Exiting...\n");
            free(req);
            return 1;
        }
    }
    printf("Enter the initial head position: ");
    if (scanf("%d", &head) != 1) {
        printf("Invalid input. Exiting...\n");
        free(req);
        return 1;
    }
    int seek_time = sstf(req, size, head);
    printf("Total Seek Time: %d\n", seek_time);
    free(req);
	printf("21BCE3439 SYED SAMI AHMED");
    return 0;
}

