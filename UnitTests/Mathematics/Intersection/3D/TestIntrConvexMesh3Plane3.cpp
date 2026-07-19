#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Intersection/3D/IntrConvexMesh3Plane3.h>
using namespace gtl;

namespace gtl
{
    class UnitTestIntrConvexMesh3Plane3
    {
    public:
        UnitTestIntrConvexMesh3Plane3();

    private:
    };
}

UnitTestIntrConvexMesh3Plane3::UnitTestIntrConvexMesh3Plane3()
{
    UTInformation("Mathematics/Intersection/3D/IntrConvexMesh3Plane3 [NEEDS UNIT TESTS]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Intersection/3D/IntrConvexMesh3Plane3.h>

namespace gtl
{
#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class FIQuery<Rational, ConvexMesh3<Rational>, Plane3<Rational>>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(IntrConvexMesh3Plane3)
