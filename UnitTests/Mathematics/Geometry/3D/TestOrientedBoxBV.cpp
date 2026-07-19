#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Geometry/3D/OrientedBoxBV.h>
using namespace gtl;

namespace gtl
{
    class UnitTestOrientedBoxBV
    {
    public:
        UnitTestOrientedBoxBV();

    private:
    };
}

UnitTestOrientedBoxBV::UnitTestOrientedBoxBV()
{
    UTInformation("Mathematics/Geometry/3D/OrientedBoxBV [NEEDS UNIT TESTING]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Geometry/3D/OrientedBoxBV.h>

namespace gtl
{
    template class OrientedBoxBV<float>;
    template class OrientedBoxBV<double>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class OrientedBoxBV<Rational>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(OrientedBoxBV)
