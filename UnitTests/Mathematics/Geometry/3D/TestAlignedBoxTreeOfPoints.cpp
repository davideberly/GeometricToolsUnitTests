#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Geometry/3D/AlignedBoxTreeOfPoints.h>
using namespace gtl;

namespace gtl
{
    class UnitTestAlignedBoxTreeOfPoints
    {
    public:
        UnitTestAlignedBoxTreeOfPoints();

    private:
    };
}

UnitTestAlignedBoxTreeOfPoints::UnitTestAlignedBoxTreeOfPoints()
{
    UTInformation("Mathematics/Geometry/3D/AlignedBoxTreeOfPoints [NEEDS UNIT TESTING]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Geometry/3D/AlignedBoxTreeOfPoints.h>

namespace gtl
{
    template class AlignedBoxTreeOfPoints<float>;
    template class AlignedBoxTreeOfPoints<double>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class AlignedBoxTreeOfPoints<Rational>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(AlignedBoxTreeOfPoints)
