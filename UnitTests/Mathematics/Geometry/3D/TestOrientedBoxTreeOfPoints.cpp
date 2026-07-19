#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Geometry/3D/OrientedBoxTreeOfPoints.h>
using namespace gtl;

namespace gtl
{
    class UnitTestOrientedBoxTreeOfPoints
    {
    public:
        UnitTestOrientedBoxTreeOfPoints();

    private:
    };
}

UnitTestOrientedBoxTreeOfPoints::UnitTestOrientedBoxTreeOfPoints()
{
    UTInformation("Mathematics/Geometry/3D/OrientedBoxTreeOfPoints [NEEDS UNIT TESTING]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Geometry/3D/OrientedBoxTreeOfPoints.h>

namespace gtl
{
    template class OrientedBoxTreeOfPoints<float>;
    template class OrientedBoxTreeOfPoints<double>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class OrientedBoxTreeOfPoints<Rational>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(OrientedBoxTreeOfPoints)
