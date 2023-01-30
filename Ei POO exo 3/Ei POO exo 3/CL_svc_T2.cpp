#include "CL_svc_T2.h"

CL_svc_T2::CL_svc_T2()
{
	this->oc = new CL_cmp_C();
}

void CL_svc_T2::CL_svc_S1()
{
	this->oc->workC();
}
