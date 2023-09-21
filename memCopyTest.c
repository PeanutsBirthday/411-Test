#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <linux/kernel.h>
#include <sys/syscall.h>

void successful(){
	//int size = 100;
        unsigned char from[100] = "Hello, World!";
        unsigned char to[100];
        int size = strlen(from) + 1;

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
        //int size = 100;
        unsigned char from[100] = "Hello, World!";
        unsigned char to[200];
        int size = strlen(from) + 1;

        long result = syscall(549, to, from, (size*2) );

        if (result != 0) {
                printf("	Syscall failed successfully!\n");
                //for (int ii = 0; ii < size; ii++) {
                //      printf("%c", from[ii]);
                //}
        printf("to: %s\n", to);
                //for (int i = 0; i < size; i++) {
                //      printf("%c", from[i]);
                //}
        } else {
        perror("	Syscall failed to fail");
        printf("	to: %s\n", to);

        }
}
void nullCopyFrom(){
//null from or to?
//        int size = 100;
        unsigned char from = NULL;
        unsigned char to[100];
//        int size = strlen(from) + 1;
	int size = 100;
        long result = syscall(549, to, from, size);

        if (result != 0) {
                printf("	Syscall failed successfully!\n");
                printf("	to: %s\n",to);
                //for (int ii = 0; ii < size; ii++) {
                //      printf("%c", from[ii]);
                //}
                //for (int i = 0; i < size; i++) {
                //      printf("%c", from[i]);
                //}
        } else {
        perror("	Syscall failed to fail");
        }
}
void nullCopyTo(){
//null from or to?
//        int size = 100;
        unsigned char from[100] = "Hello, World!";
        unsigned char to[0];
        int size = strlen(from) + 1;

        long result = syscall(549, to, from, size);

        if (result != 0) {
                printf("	Syscall failed successfully!\n");
                printf("	to: %s\n", to);
                //for (int ii = 0; ii < size; ii++) {
                //      printf("%c", from[ii]);
                //}
                //for (int i = 0; i < size; i++) {
                //      printf("%c", from[i]);
                //}
        } else {
        perror("	Syscall failed to fail");
                printf("	to: %s\n", to);
        }
}
void toSelf(){
//from is to?
        //int size = 100;
        unsigned char from[100] = "Hello, World!"; 
        int size = strlen(from) + 1;

        long result = syscall(549, from, from, size);

        if (result != 0) {
                printf("	Syscall failed successfully!\n");
                //for (int ii = 0; ii < size; ii++) {
                //      printf("%c", from[ii]);
                //}
        	printf("	to: %s\n", from);
                //for (int i = 0; i < size; i++) {
                //      printf("%c", from[i]);
                //}
        } else {
        perror("	Syscall failed to fail");
                printf("	from: %s\n", from);
}
}


int main() {
        successful();
        printf("sizeError()\n");
        sizeError();
        printf("nullCopyFrom()\n");
        nullCopyFrom();
        printf("nullcopyTo()\n");
        nullCopyTo();
        printf("toSelf()\n");
        toSelf();
        return 0;
}
