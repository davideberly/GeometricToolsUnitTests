#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Geometry/3D/AlignedBoxTreeOfTriangles.h>
using namespace gtl;

namespace gtl
{
    class UnitTestAlignedBoxTreeOfTriangles
    {
    public:
        UnitTestAlignedBoxTreeOfTriangles();

    private:
    };
}

UnitTestAlignedBoxTreeOfTriangles::UnitTestAlignedBoxTreeOfTriangles()
{
    UTInformation("Mathematics/Geometry/3D/AlignedBoxTreeOfTriangles [NEEDS UNIT TESTING]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Geometry/3D/AlignedBoxTreeOfTriangles.h>

namespace gtl
{
    template class AlignedBoxTreeOfTriangles<float>;
    template class AlignedBoxTreeOfTriangles<double>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class AlignedBoxTreeOfTriangles<Rational>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(AlignedBoxTreeOfTriangles)
