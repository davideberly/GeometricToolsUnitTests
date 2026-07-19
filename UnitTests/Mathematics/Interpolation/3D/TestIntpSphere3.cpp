#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Interpolation/3D/IntpSphere3.h>
#include "WICFileIONative.h"
#include <fstream>
using namespace gtl;

namespace gtl
{
    class UnitTestIntpSphere3
    {
    public:
        UnitTestIntpSphere3();
    };
}

UnitTestIntpSphere3::UnitTestIntpSphere3()
{
    UTInformation("Mathematics/Interpolation/3D/IntpSphere3 [NEEDS UNIT TESTS]");
}

#else

#include <GTL/Mathematics/Interpolation/3D/IntpSphere3.h>

namespace gtl
{
    template class IntpSphere3<float>;
    template class IntpSphere3<double>;
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(IntpSphere3)
