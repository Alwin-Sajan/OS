#include <stdio.h>

struct frames {
    int content, count;
} frame[100];

struct frame {
    int content;
    int freq;
    int cnt;
} frames[100];

void FIFO(int m, int n, int pg[]) {
    int i, j, fnd, k = 0, cnt = 0, fr[100];;
    for (i = 0; i < m; i++) {
        fr[i] = -1;
    }
    printf("\nREFERENCE STRING\t PAGE NUMBER\t\t  STATUS\n");
    for (i = 0; i < n; i++) {
        fnd = 0;
        printf("\t\t%d\t\t", pg[i]);
        for (j = 0; j < m; j++) {
            if (fr[j] == pg[i]) {
                fnd = 1;
            }
        }
        if (fnd == 0) {
            fr[k] = pg[i];
            k = (k + 1) % m;
            cnt++;
        }
        for (j = 0; j < m; j++) {
            if (fr[j] != -1) {
                printf("%d   ", fr[j]);
            }
        }
        if (fnd == 1) {
            printf("\t\tHIT\n");
        } else {
            printf("\t\tMISS\n");
        }
    }
    printf("\nPAGE FAULT : %d\n", cnt);
}

void LRU(int pages[], int n, int frames) {
    int frame[50], recent[50];
    int page_faults = 0, i, j, k, lru, flag;

    for (i = 0; i < frames; i++) {
        frame[i] = -1; // Initialize frames as empty
        recent[i] = 0; // Initialize recent counters as 0
    }

printf("\nREFERENCE STRING\t PAGE NUMBER\t\t  STATUS\n");
    for (i = 0; i < n; i++) {
        flag = 0;

        // Check if page already in frame
        for (j = 0; j < frames; j++) {
            if (frame[j] == pages[i]) {
                flag = 1;
                recent[j] = i + 1; // Update recent counter
                break;
            }
        }

        // If page not in frame, replace LRU page
        if (flag == 0) {
            lru = 0;
            for (j = 1; j < frames; j++) {
                if (recent[j] < recent[lru]) {
                    lru = j;
                }
            }
            frame[lru] = pages[i];
            recent[lru] = i + 1; // Update recent counter
            page_faults++;
        }

//printf("REFERENCE STRING: %d -> PAGE NUMBER: ", pages[i]);
        printf("\t\t%d\t\t", pages[i]);
        for (k = 0; k < frames; k++) {
            if (frame[k] == -1)
                printf(" |  ");
            else
                printf("%d | ", frame[k]);
        }
       
        //printf("STATUS: ");
       
        if (flag == 0) {
            printf("\t\tMISS\n");
        } else {
            printf("\t\tHIT\n");
        }
    }

    printf("\nTotal Page Faults: %d\n", page_faults);
}

void LFU(int page[], int pgn, int fr) {

    int i, j, cnt, pf, min, id = 0;

    for (i = 0; i < fr; i++) {
        frames[i].content = -1;
        frames[i].freq = 0;
        frames[i].cnt = 0;
    }
   
    printf("\nREFERENCE STRING\t PAGE NUMBER\t\t  STATUS\n");
    //printf("\nREFERENCE STRING\tSTATUS\t\tPAGE NUMBER\n\n");
    for (pf = 0, cnt = 1, i = 0; i < pgn; i++) {
        printf("\t\t%d\t\t", page[i]);
        for (j = 0; j < fr; j++) {
            if (frames[j].content != -1)
                printf("%d   ", frames[j].content);
        }
        for (j = 0; j < fr; j++) {
            if (frames[j].content == page[i]) {
                printf("\t\tHIT\t\t");
                frames[j].freq++;
                break;
            }
        }
        if (j == fr) {
            printf("\t\tMISS\t\t");
            if (id < fr) {
                frames[id].content = page[i];
                frames[id].freq++;
                frames[id].cnt = cnt++;
                id++;
            } else {
                for (min = 0, j = 0; j < fr; j++) {
                    if (frames[min].freq > frames[j].freq) {
                        min = j;
                    } else if (frames[min].freq == frames[j].freq && frames[min].cnt > frames[j].cnt) {
                        min = j;
                    }
                }
                frames[min].content = page[i];
                frames[min].freq = 1;
                frames[min].cnt = cnt++;
            }
            pf++;
        }
       
        printf("\n");
    }
    printf("\nTotal Page Faults: %d\n", pf);
}

int main() {
    int i, n, m, choice = 0, pg[100];
    printf("Enter the number of pages: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter the page number %d: ", i + 1);
        scanf("%d", &pg[i]);
    }
    printf("Enter the number of frames: ");
    scanf("%d", &m);
    printf("1) FIFO   2) LRU   3) LFU   4) Exit");
    do {
        printf("\nEnter the choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                FIFO(m, n, pg);
                break;

            case 2:
                LRU(pg, n, m);
                break;

            case 3:
                LFU(pg, n, m);
                break;

            case 4:
                break;

            default:
                printf("Invalid choice");
        }
    } while (choice != 4);

    return 0;
}



