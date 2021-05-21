#include "Config.h"
#include <iostream>
#include "MathFunctions/MathFunctions.h"
int main(int argc, char *argv[])
{

#ifdef USE_MATH
    double outputValue = mysqrt(100);
    std::cout << " Use math ************** " << outputValue << std::endl;
#else
    double outputValue = 100;
    std::cout << " Not Use math ************** " << outputValue << std::endl;
#endif
}
