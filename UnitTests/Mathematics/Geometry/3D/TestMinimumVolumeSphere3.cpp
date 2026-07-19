#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Geometry/3D/MinimumVolumeSphere3.h>
using namespace gtl;

namespace gtl
{
    class UnitTestMinimumVolumeSphere3
    {
    public:
        UnitTestMinimumVolumeSphere3();

    private:
    };
}

UnitTestMinimumVolumeSphere3::UnitTestMinimumVolumeSphere3()
{
    UTInformation("Mathematics/Geometry/3D/MinimumVolumeSphere3 [NEEDS UNIT TESTING]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Geometry/3D/MinimumVolumeSphere3.h>

namespace gtl
{
    template class MinimumVolumeSphere3<float, double>;
    template class MinimumVolumeSphere3<double, float>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class MinimumVolumeSphere3<float, Rational>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(MinimumVolumeSphere3)
