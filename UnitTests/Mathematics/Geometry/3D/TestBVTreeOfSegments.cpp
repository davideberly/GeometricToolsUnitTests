#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Geometry/3D/BVTreeOfSegments.h>
#include <GTL/Mathematics/Geometry/3D/AlignedBoxBV.h>
#include <GTL/Mathematics/Geometry/3D/OrientedBoxBV.h>
using namespace gtl;

namespace gtl
{
    class UnitTestBVTreeOfSegments
    {
    public:
        UnitTestBVTreeOfSegments();

    private:
    };
}

UnitTestBVTreeOfSegments::UnitTestBVTreeOfSegments()
{
    UTInformation("Mathematics/Geometry/3D/BVTreeOfSegments [NEEDS UNIT TESTING]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Geometry/3D/BVTreeOfSegments.h>
#include <GTL/Mathematics/Geometry/3D/AlignedBoxBV.h>
#include <GTL/Mathematics/Geometry/3D/OrientedBoxBV.h>

namespace gtl
{
    template class BVTreeOfSegments<float, AlignedBoxBV<float>>;
    template class BVTreeOfSegments<double, OrientedBoxBV<double>>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class BVTreeOfSegments<Rational, AlignedBoxBV<Rational>>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(BVTreeOfSegments)
