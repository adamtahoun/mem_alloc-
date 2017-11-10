#include <stdio.h>
#include "mem.c"

#define REGION_SIZE (10*1024)

/*void* myalloc(int size)
{
  printf("allocate memory of size=%d bytes...", size);
  void* p = Mem_Alloc(size);
  if(p) printf("  success (p=%p, f=%g)\n", p, Mem_GetFragmentation());
  else printf("  failed\n");
  return p;
}*/

int main(int argc, char* argv[])
{
  //myalloc(1000);

  printf("init memory allocator...");
  if(Mem_Init(REGION_SIZE, MEM_POLICY_FIRSTFIT) < 0) {
    printf("  unable to initialize memory allocator!\n");
    return -1;
  } else printf("  success!\n");


}
