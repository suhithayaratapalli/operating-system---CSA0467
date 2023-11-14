#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 1024
#define NUM_BLOCKS 10

struct Block {
    int data[BLOCK_SIZE];
    struct Block* next;
};

struct File {
    char name[20];
    struct Block* startBlock;
    struct Block* endBlock;
};

// Function to create a new block
struct Block* createBlock() {
    struct Block* block = (struct Block*)malloc(sizeof(struct Block));
    block->next = NULL;
    return block;
}

// Function to create a new file
struct File* createFile(char* name) {
    struct File* file = (struct File*)malloc(sizeof(struct File));
    strcpy(file->name, name);
    file->startBlock = NULL;
    file->endBlock = NULL;
    return file;
}

// Function to append data to a file
void appendData(struct File* file, int data) {
    struct Block* block = createBlock();
    block->data[0] = data;
    if (file->endBlock == NULL) {
        file->startBlock = file->endBlock = block;
    } else {
        file->endBlock->next = block;
        file->endBlock = block;
    }
}

// Function to print file content
void printFile(struct File* file) {
    struct Block* block = file->startBlock;
    while (block != NULL) {
        for (int i = 0; i < BLOCK_SIZE; i++) {
            if (block->data[i] != 0) {
                printf("%d ", block->data[i]);
            }
        }
        block = block->next;
    }
    printf("\n");
}

int main() {
    struct File* myFile = createFile("myFile");

    // Simulate writing data to the file
    for (int i = 1; i <= NUM_BLOCKS * BLOCK_SIZE; i++) {
        appendData(myFile, i);
    }

    printf("File content: ");
    printFile(myFile);

    return 0;
}