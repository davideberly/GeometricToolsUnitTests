#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Geometry/3D/MinimumVolumeBox3.h>
using namespace gtl;

namespace gtl
{
    class UnitTestMinimumVolumeBox3
    {
    public:
        UnitTestMinimumVolumeBox3();

    private:
    };
}

UnitTestMinimumVolumeBox3::UnitTestMinimumVolumeBox3()
{
    UTInformation("Mathematics/Geometry/3D/MinimumVolumeBox3 [NEEDS UNIT TESTING]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Geometry/3D/MinimumVolumeBox3.h>

namespace gtl
{
    template class MinimumVolumeBox3<float, true>;
    template class MinimumVolumeBox3<double, false>;
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(MinimumVolumeBox3)
