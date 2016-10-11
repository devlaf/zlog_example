#include <iostream>
#include <stdio.h>
#include "logger.h"

using namespace std;

int main()
{
    log_synchronous("test %d", 4);
    return 0;
}
