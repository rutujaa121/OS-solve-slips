#include <stdio.h>
int main() {
    int i, j, n, frames, pages[30], temp[10], flag1, flag2, pos = 0, faults = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter the page reference string: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    
    for (i = 0; i < frames; i++) {
temp[i] = -1;
    }

    printf("\nPage Reference String  |  Frames\n");

    for (i = 0; i < n; i++) {
        flag1 = flag2 = 0;

        
        for (j = 0; j < frames; j++) {
            if (temp[j] == pages[i]) {
                flag1 = flag2 = 1;
                break;
            }
 }

        
        if (flag1 == 0) {
            for (j = 0; j < frames; j++) {
                if (temp[j] == -1) {
                    temp[j] = pages[i];
                    flag2 = 1;
                    faults++;
                    break;
                }
            }
        }

        if (flag2 == 0) {
            temp[pos] = pages[i];
            pos = (pos + 1) % frames;
            faults++;
        }

        
        printf("\n%2d\t\t\t", pages[i]);
        for (j = 0; j < frames; j++) {
            if (temp[j] != -1)
                printf("%2d ", temp[j]);
            else
                printf("- ");
        }
    }

    printf("\n\nTotal Page Faults: %d\n", faults);
    return 0;
}

