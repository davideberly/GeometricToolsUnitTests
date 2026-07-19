#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Geometry/3D/OrientedBoxTreeOfSegments.h>
using namespace gtl;

namespace gtl
{
    class UnitTestOrientedBoxTreeOfSegments
    {
    public:
        UnitTestOrientedBoxTreeOfSegments();

    private:
    };
}

UnitTestOrientedBoxTreeOfSegments::UnitTestOrientedBoxTreeOfSegments()
{
    UTInformation("Mathematics/Geometry/3D/OrientedBoxTreeOfSegments [NEEDS UNIT TESTING]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Geometry/3D/OrientedBoxTreeOfSegments.h>

namespace gtl
{
    template class OrientedBoxTreeOfSegments<float>;
    template class OrientedBoxTreeOfSegments<double>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class OrientedBoxTreeOfSegments<Rational>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(OrientedBoxTreeOfSegments)
