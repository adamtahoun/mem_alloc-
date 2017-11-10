#include "mem.h"

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <errno.h>

#define APPLE

int policy;
int head_ptr;
int tail_ptr;

struct Mem_Obj{
    int start_ptr;
    int end_ptr;
    struct Mem_Obj *next;
 };

struct Mem_Obj head;


int Mem_Init(int size, int policy_) {
  policy = policy_;
  void *ptr;
  double pages;
  int page_amount;
  double page_size;
  page_size = getpagesize();
  pages = page_size/(double)size;
  size = (ceil(pages) * page_size);
  #ifdef APPLE
  ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
  #else
  //open the /dev/zero device
  int fd = open("/dev/zero", O_RDWR);
  // size (in bytes) must be divisible by page size
  ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
  #endif
  if (ptr == MAP_FAILED) {
    perror("mmap");
    return -1;
  }
  head_ptr = ptr;
  tail_ptr = ptr + size;
  head = NULL;

  // close the device (don't worry, mapping should be unaffected)
  #ifndef APPLE
  close(fd);
  #endif
  return 0;
}


void* Mem_Alloc(int size) {

  switch (policy) {
    case MEM_POLICY_FIRSTFIT:
      if(head == NULL){
        printf("we up in dis bitch");
      }
    break;
    case MEM_POLICY_BESTFIT:
      printf("%s\n", "allocating in BF mode");
    break;
    case MEM_POLICY_WORSTFIT:
    printf("%s\n", "allocating in WF mode");
    break;
  }

  void* ptr;
  ptr = 0;
  return ptr;

}
