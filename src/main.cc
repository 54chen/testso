/**********
 *  main  *
 **********/
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <dlfcn.h>
#include "main.h"

using namespace std;

int main(int argc, char *argv[]) {
  //std::cout << "I am in main!" << std::endl;
  //call_process(2); 

  //dlopen model:
  std::string so = "/home/cz/testso/libtest.so";
  void *so_obj = dlopen((char*)so.c_str(),RTLD_LAZY);
  if (so_obj == NULL) {
      std::cout << "so is not exist!" << std::endl;
  }

  void (*call_process)(int);
  call_process  = (void(*)(int))dlsym(so_obj, "call_process");

  if (call_process != NULL) {
      std::cout << "it is work!" << std::endl;
      (call_process)(1);
  }
  return 0;
}
