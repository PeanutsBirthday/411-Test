#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <linux/kernel.h>
#include <sys/syscall.h>

int main() {
    unsigned char from[100] = "Hello, World!"; // Source data
    unsigned char to[100];                     // Destination buffer
    int size = strlen(from) + 1;               // Include null terminator

    // Initialize the destination buffer with zeros
    //memset(to, 0, sizeof(to));

    // Call the syscall to copy data from 'from' to 'to'
    long result = syscall(549, to, from, size); 

    if (result == 0) {
        printf("Syscall succeeded!\n");
        printf("Copied data from 'from': %s\n", from);
	//for (int ii = 0; ii < size; ii++) {
        //	printf("%c", from[ii]);
	//}
        printf("Copied data to 'to': %s\n", to);
	//for (int i = 0; i < size; i++) {
        //	printf("%c", from[i]);
        //}
    } else {
        perror("Syscall failed");
    }

    return 0;
}




////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <linux/kernel.h>
#include <sys/syscall.h>

#define NR_hello 548 

long hello_syscall(void) {
  return syscall( NR_hello);
}

int main(int argc, char *argv[]) {
  long rv;
  rv = hello_syscall(); 
  if(rv < 0) {
    perror("Hello syscall failed");
  }else {
    printf("Hello syscall ran successfully, check dmesg output\n");
  }
  return 0;
}

////////////////////////////////////////////////////////////////////////////


