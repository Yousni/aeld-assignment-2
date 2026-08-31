#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // Check for correct number of arguments
    if (argc != 3) {
        syslog(LOG_ERR, "Invalid number of arguments. Usage: writer <file> <string>");
        return 1;
    }

    const char *filename = argv[1];
    const char *string = argv[2];

    // Open file for writing (create if it doesn't exist, append if it does)
    int fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd == -1) {
        syslog(LOG_ERR, "Failed to open file %s", filename);
        return 1;
    }

    // Write string to file
    ssize_t bytes_written = write(fd, string, strlen(string));
    if (bytes_written == -1) {
        syslog(LOG_ERR, "Failed to write to file %s", filename);
        close(fd);
        return 1;
    }
   
    syslog(LOG_DEBUG, "Wrote string: %s to file %s", string, filename);

    // Write newline to file
    bytes_written = write(fd, "\n", 1);
    if (bytes_written == -1) {
        syslog(LOG_ERR, "Failed to write to file %s", filename);
        close(fd);
        return 1;
    }

    syslog(LOG_DEBUG, "Wrote newline to file %s", filename);

    // Close file
    if (close(fd) == -1) {
        syslog(LOG_ERR, "Failed to close file %s", filename);
        return 1;
    }

    return 0;
}