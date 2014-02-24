#pragma once

#define NSBEGIN(x)  namespace x {
#define NSEND }

#include <vector>
#include <algorithm>
#include <cassert>


#define FOR_INC(var, indexf, indext)  for(int var = indexf; var < indext; ++var)
#define FOR_ITR(itrT, var, itrb, itre)  for(itrT var = itrb;var!=itre;++var)




