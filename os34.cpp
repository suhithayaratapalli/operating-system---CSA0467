#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

// Structure to represent a record
struct Record {
    int recordID;
    char data[100];
};

int main() {
    struct Record file[MAX_RECORDS];  // Array to store records
    int totalRecords = 0;

    while (1) {
        int choice;
        printf("1. Add Record\n");
        printf("2. Read Record\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (totalRecords < MAX_RECORDS) {
                    struct Record newRecord;
                    newRecord.recordID = totalRecords + 1;
                    printf("Enter data for Record %d: ", newRecord.recordID);
                    scanf(" %[^\n]s", newRecord.data);
                    file[totalRecords] = newRecord;
                    totalRecords++;
                    printf("Record %d added successfully.\n", newRecord.recordID);
                } else {
                    printf("File is full. Cannot add more records.\n");
                }
                break;
            case 2:
                if (totalRecords > 0) {
                    int recordNumber;
                    printf("Enter the record number to read (1 to %d): ", totalRecords);
                    scanf("%d", &recordNumber);

                    if (recordNumber >= 1 && recordNumber <= totalRecords) {
                        printf("Reading Record %d: %s\n", recordNumber, file[recordNumber - 1].data);
                    } else {
                        printf("Invalid record number. Please enter a valid record number.\n");
                    }
                } else {
                    printf("File is empty. No records to read.\n");
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please select a valid option.\n");
                break;
        }
    }

return 0;
}