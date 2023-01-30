
#include "CL_svc_T1.h"

CL_svc_T1::CL_svc_T1()
{
	this->oA = new CL_cmp_A();
	this->oB = new CL_cmp_B();
}

void CL_svc_T1::svc_T1_S1()
{
	this->oA->workA();
	this->oB->workB();
}

void CL_svc_T1::svc_T1_S2()
{
	this->oB->workB();
}
