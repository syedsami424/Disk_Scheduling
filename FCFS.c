#include <stdio.h>
#include <stdlib.h>

int fcfs(int req[], int size, int head) {
    int seek_time = 0;
    int current = head;
    int i;
    for (i = 0; i < size; i++) {
        int distance = abs(current-req[i]);
        current = req[i];
        seek_time += distance;
    }
    return seek_time;
}

int main() {
    int size, head;
    printf("Enter the number of requests: ");
    scanf("%d", &size);
    int* req = (int*)malloc(size * sizeof(int));
    printf("Enter the request queue:\n");
    int i;
    for (i = 0; i < size; i++) {
        scanf("%d", &req[i]);
    }
    printf("Enter the initial head position: ");
    scanf("%d", &head);
    int seek_time = fcfs(req, size, head);
    printf("Total Seek Time: %d\n", seek_time);
    free(req);
    printf("21BCE3439 SYED SAMI AHMED");    
    return 0;
}





