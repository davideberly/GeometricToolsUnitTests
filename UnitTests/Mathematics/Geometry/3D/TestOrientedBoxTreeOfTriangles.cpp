#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Geometry/3D/OrientedBoxTreeOfTriangles.h>
using namespace gtl;

namespace gtl
{
    class UnitTestOrientedBoxTreeOfTriangles
    {
    public:
        UnitTestOrientedBoxTreeOfTriangles();

    private:
    };
}

UnitTestOrientedBoxTreeOfTriangles::UnitTestOrientedBoxTreeOfTriangles()
{
    UTInformation("Mathematics/Geometry/3D/OrientedBoxTreeOfTriangles [NEEDS UNIT TESTING]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Geometry/3D/OrientedBoxTreeOfTriangles.h>

namespace gtl
{
    template class OrientedBoxTreeOfTriangles<float>;
    template class OrientedBoxTreeOfTriangles<double>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class OrientedBoxTreeOfTriangles<Rational>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(OrientedBoxTreeOfTriangles)
