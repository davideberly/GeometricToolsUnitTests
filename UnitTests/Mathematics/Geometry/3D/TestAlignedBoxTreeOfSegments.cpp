#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Geometry/3D/AlignedBoxTreeOfSegments.h>
using namespace gtl;

namespace gtl
{
    class UnitTestAlignedBoxTreeOfSegments
    {
    public:
        UnitTestAlignedBoxTreeOfSegments();

    private:
    };
}

UnitTestAlignedBoxTreeOfSegments::UnitTestAlignedBoxTreeOfSegments()
{
    UTInformation("Mathematics/Geometry/3D/AlignedBoxTreeOfSegments [NEEDS UNIT TESTING]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Geometry/3D/AlignedBoxTreeOfSegments.h>

namespace gtl
{
    template class AlignedBoxTreeOfSegments<float>;
    template class AlignedBoxTreeOfSegments<double>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class AlignedBoxTreeOfSegments<Rational>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(AlignedBoxTreeOfSegments)
