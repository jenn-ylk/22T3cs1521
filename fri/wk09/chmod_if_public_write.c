// code that will change file permissions to not be publically writeable 
// if it is publically writeable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    struct stat s;
    for (int i = 1; i < argc; i++) {
        // TODO: stat the file, and check the permissions
        if (stat(argv[i], &s)) {
            perror(argv[i]);
            continue;
        }

        // TODO: change the permissions with chmod if the file is publically writeable
        mode_t mode = s.st_mode;
        // S_IWOTH - writabel by other
        // S_IROTH - readable by other
        // S_IRUSR - 
        // check if publically writable
        if (mode & S_IWOTH) {
            printf("removing public write from %s\n", argv[i]);
            if (chmod(argv[i], mode & ~S_IWOTH)) {
                // mode - S_IWOTH
                // mode ^ S_IWOTH
                perror(argv[i]);
                continue;
            }
        } else {
            printf("%s is not publically writable\n", argv[i]);
        }
        
    }
    
    return 0;
}
