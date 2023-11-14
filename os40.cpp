#include <stdio.h>
#include <sys/stat.h>

int main() {
    // File path and mode
    char *file_path = "example.txt";
    mode_t file_mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH; // 644

    // Create a text file
    FILE *file = fopen(file_path, "w");
    if (file == NULL) {
        perror("Error creating file");
        return 1;
    }

    // Set file permissions
    if (chmod(file_path, file_mode) == -1) {
        perror("Error setting file permissions");
        return 1;
    }

    printf("File permissions set to 644 (rw-r--r--)\n");

    // Check and display file permissions
    struct stat file_stat;
    if (stat(file_path, &file_stat) == 0) {
        printf("File permissions: %o\n", file_stat.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO));
    } else {
        perror("Error checking file permissions");
    }

    // Close and remove the file
    fclose(file);
    remove(file_path);

return 0;
}
