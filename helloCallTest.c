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
