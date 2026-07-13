#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Geometry/2D/SeparatePoints2.h>
#include <GTL/Utility/Timer.h>
#include <random>
using namespace gtl;

namespace gtl
{
    class UnitTestSeparatePoints2
    {
    public:
        UnitTestSeparatePoints2();
    };
}

UnitTestSeparatePoints2::UnitTestSeparatePoints2()
{
    UTInformation("Mathematics/Geometry/2D/SeparatePoints2 [NEEDS UNIT TESTS]");
}

#else

#include <GTL/Mathematics/Geometry/2D/SeparatePoints2.h>

namespace gtl
{
    template class SeparatePoints2<float>;
    template class SeparatePoints2<double>;
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(SeparatePoints2)
