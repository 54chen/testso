/**********
 *  main  *
 **********/

#include <stdio.h>
#include <iostream>
#include "main.h"

int main(int argc, char *argv[]) {
  std::cout << "I am in main!" << std::endl;
  call_process(2); 
  return 0;
}
