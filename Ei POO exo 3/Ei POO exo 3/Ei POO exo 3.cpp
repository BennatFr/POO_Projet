#include <iostream>
#include "CL_svc_T1.h"
#include "CL_svc_T2.h"

int main()
{
    std::cout << "Hello World!\n";

    CL_svc_T1 o1 = CL_svc_T1();
    o1.svc_T1_S1();

    CL_svc_T2 o2 = CL_svc_T2();
    o2.CL_svc_S1();
}
