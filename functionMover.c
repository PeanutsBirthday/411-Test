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

#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/uaccess.h>
#include <linux/errno.h>

SYSCALL_DEFINE3(memory_copy, unsigned char user *,to, unsigned char user *, from, int, size){
	if( access_ok(VERIFY_READ, from, size) ){
		if( !( get_user(to, from) )){//return 0 on success 
			if( !( put_user(to, from) )){//return 0 on success {
				return 0;//successful copy
			}
		}
	}
	return -EFAULT; //copy fails 
}
