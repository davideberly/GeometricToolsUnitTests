#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Geometry/3D/SeparatePoints3.h>
using namespace gtl;

namespace gtl
{
    class UnitTestSeparatePoints3
    {
    public:
        UnitTestSeparatePoints3();

    private:
    };
}

UnitTestSeparatePoints3::UnitTestSeparatePoints3()
{
    UTInformation("Mathematics/Geometry/3D/SeparatePoints3 [NEEDS UNIT TESTING]");
}

#else

#include <GTL/Mathematics/Geometry/3D/SeparatePoints3.h>

namespace gtl
{
    template class SeparatePoints3<float>;
    template class SeparatePoints3<double>;
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(SeparatePoints3)
