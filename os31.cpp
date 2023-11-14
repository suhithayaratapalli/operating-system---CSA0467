#include <stdio.h>
#include <stdbool.h>

// Function to initialize page frames with -1 (empty)
void initializePageFrames(int pageFrames[], int frameCount) {
    for (int i = 0; i < frameCount; i++) {
        pageFrames[i] = -1;
    }
}

// Function to display the contents of page frames
void displayPageFrames(int pageFrames[], int frameCount) {
    for (int i = 0; i < frameCount; i++) {
        if (pageFrames[i] == -1) {
            printf(" - ");
        } else {
            printf(" %d ", pageFrames[i]);
        }
    }
    printf("\n");
}

// Function to check if a page is present in page frames
bool isPagePresent(int pageFrames[], int frameCount, int page) {
    for (int i = 0; i < frameCount; i++) {
        if (pageFrames[i] == page) {
            return true;
        }
    }
    return false;
}

// FIFO Page Replacement Algorithm
void FIFOPageReplacement(int pages[], int pageCount, int pageFrames[], int frameCount) {
    int pageFaults = 0;
    int currentIndex = 0; // Index for the current page frame to replace

    for (int i = 0; i < pageCount; i++) {
        int currentPage = pages[i];

        if (!isPagePresent(pageFrames, frameCount, currentPage)) {
            // Page fault, replace the current page frame with the new page
            pageFrames[currentIndex] = currentPage;
            currentIndex = (currentIndex + 1) % frameCount; // Update the index in a circular manner
            pageFaults++;

            printf("Page fault for page %d: ", currentPage);
            displayPageFrames(pageFrames, frameCount);
        }
    }

    printf("Total Page Faults: %d\n", pageFaults);
}

int main() {
    int frameCount, pageCount;

    printf("Enter the number of page frames: ");
    scanf("%d", &frameCount);

    printf("Enter the number of pages in the reference string: ");
    scanf("%d", &pageCount);

    int pageFrames[frameCount];
    int pages[pageCount];

    printf("Enter the page reference string:\n");
    for (int i = 0; i < pageCount; i++) {
        scanf("%d", &pages[i]);
    }

    initializePageFrames(pageFrames, frameCount);
    FIFOPageReplacement(pages, pageCount, pageFrames, frameCount);
return 0;
}