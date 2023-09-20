void successful(){
        unsigned char from[size] = "Hello, World!";
        unsigned char to[size];
        //int size = strlen(from) + 1;

        long result = syscall(549, to, from, size); 

        if (result == 0) {
                printf("Syscall succeeded!\n");
                printf("Copied data from 'from': %s\n", from);
                //for (int ii = 0; ii < size; ii++) {
                //      printf("%c", from[ii]);
                //}
        printf("Copied data to 'to': %s\n", to);
                //for (int i = 0; i < size; i++) {
                //      printf("%c", from[i]);
                //}
        } else {
        perror("Syscall failed");
        }
}
//invalid size
void sizeError(){
        //invalid size
        int size = 100;
        unsigned char from[size] = "Hello, World!";
        unsigned char to[size];
        //int size = strlen(from) + 1;

        long result = syscall(549, to, from, (size*2) ); 

        if (result != 0) {
                printf("Syscall failed successfully!\n");
                printf("from: %s\n", from);
                //for (int ii = 0; ii < size; ii++) {
                //      printf("%c", from[ii]);
                //}
        printf("to: %s\n", to);
                //for (int i = 0; i < size; i++) {
                //      printf("%c", from[i]);
                //}
        } else {
        perror("Syscall failed to fail");
        }
}
void nullCopyFrom(){
//null from or to?
        int size = 100;
        unsigned char from[size] = null;
        unsigned char to[size]; 

        long result = syscall(549, to, from, size);

        if (result != 0) {
                printf("Syscall failed successfully!\n");
                printf("from: %s\n", from);
                //for (int ii = 0; ii < size; ii++) {
                //      printf("%c", from[ii]);
                //}
        printf("to: %s\n", to);
                //for (int i = 0; i < size; i++) {
                //      printf("%c", from[i]);
                //}
        } else {
        perror("Syscall failed to fail");
        }
}
void nullCopyTo(){
//null from or to?
        int size = 100;
        unsigned char from[size] = "Hello, World!";
        unsigned char to[0]; 

        long result = syscall(549, to, from, size);

        if (result != 0) {
                printf("Syscall failed successfully!\n");
                printf("from: %s\n", from);
                //for (int ii = 0; ii < size; ii++) {
                //      printf("%c", from[ii]);
                //}
        printf("to: %s\n", to);
                //for (int i = 0; i < size; i++) {
                //      printf("%c", from[i]);
                //}
        } else {
        perror("Syscall failed to fail");
        }
}
void toSelf(){
//from is to?
        int size = 100;
        unsigned char from[size] = "Hello, World!";
        //unsigned char to[0]; 

        long result = syscall(549, from, from, size);

        if (result != 0) {
                printf("Syscall failed successfully!\n");
                printf("from: %s\n", from);
                //for (int ii = 0; ii < size; ii++) {
                //      printf("%c", from[ii]);
                //}
        printf("to: %s\n", from);
                //for (int i = 0; i < size; i++) {
                //      printf("%c", from[i]);
                //}
        } else {
        perror("Syscall failed to fail");
        }
}


int main() {
        successful();
        sizeError();
        nullCopyFrom();
        nullCopyTo();
        toSelf();
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


