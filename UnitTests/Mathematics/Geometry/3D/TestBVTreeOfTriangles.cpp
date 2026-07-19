#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Geometry/3D/BVTreeOfTriangles.h>
#include <GTL/Mathematics/Geometry/3D/AlignedBoxBV.h>
#include <GTL/Mathematics/Geometry/3D/OrientedBoxBV.h>
using namespace gtl;

namespace gtl
{
    class UnitTestBVTreeOfTriangles
    {
    public:
        UnitTestBVTreeOfTriangles();

    private:
    };
}

UnitTestBVTreeOfTriangles::UnitTestBVTreeOfTriangles()
{
    UTInformation("Mathematics/Geometry/3D/BVTreeOfTriangles [NEEDS UNIT TESTING]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Geometry/3D/BVTreeOfTriangles.h>
#include <GTL/Mathematics/Geometry/3D/AlignedBoxBV.h>
#include <GTL/Mathematics/Geometry/3D/OrientedBoxBV.h>

namespace gtl
{
    template class BVTreeOfTriangles<float, AlignedBoxBV<float>>;
    template class BVTreeOfTriangles<double, OrientedBoxBV<double>>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class BVTreeOfTriangles<Rational, AlignedBoxBV<Rational>>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(BVTreeOfTriangles)
