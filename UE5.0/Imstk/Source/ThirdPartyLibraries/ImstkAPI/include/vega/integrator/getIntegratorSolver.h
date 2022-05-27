#ifndef _GETINTEGRATORSOLVER_H_
#define _GETINTEGRATORSOLVER_H_

namespace vega 
{

// returns the string corresponding to the selected integrator solver
// "solver" must be pre-allocated
// result: PARDISO, SPOOLES or PCG
void GetIntegratorSolver(char * solver);
 
} // namespace vega

#endif

