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
        if (stat(argv[i], &s) == -1) {
            perror(argv[i]);
        }
        
        // TODO: change the permissions with chmod if the file is publically writeable
        mode_t mode = s.st_mode;
        if (S_IWOTH & mode) {
            printf("removing public write from %s\n", argv[i]);
            chmod(argv[i], mode & ~S_IWOTH);
        } else {
            printf("%s is not publically writable\n", argv[i]);
        }
        
    }
    
    return 0;
}
