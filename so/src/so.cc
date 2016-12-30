/********
 *  so  *
 ********/


#include <stdio.h>
#include <iostream>
#include "main.h"

extern "C" void call_process(int i) {
    std::cout << i << std::endl;
}
