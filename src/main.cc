/**********
 *  main  *
 **********/

#include <stdio.h>
#include <iostream>
#include <dlfcn.h>
#include "main.h"

typedef struct {
 const char *module;
 int (*GetValue)(char *pszVal);
 int (*PrintfHello)();
} so_API;



int main(int argc, char *argv[]) {
  std::cout << "I am in main!" << std::endl;
  call_process(2); 

  //dlopen model:
  std::string so = "so/libtest.so";
  void *so_obj = dlopen((char*)so.c_str(),RTLD_LAZY);
  if (so_obj == NULL) {
      std::cout << "so is not exist!" << std::endl;
  }

  FunPtr func = (FunPtr)dlsym(so_obj, "call_process");

  if (func != NULL) {
      (*func)(3);
  }

  return 0;
}
