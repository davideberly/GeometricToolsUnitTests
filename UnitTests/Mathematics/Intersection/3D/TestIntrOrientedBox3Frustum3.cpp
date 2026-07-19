#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Intersection/3D/IntrOrientedBox3Frustum3.h>
using namespace gtl;

namespace gtl
{
    class UnitTestIntrOrientedBox3Frustum3
    {
    public:
        UnitTestIntrOrientedBox3Frustum3();

    private:
    };
}

UnitTestIntrOrientedBox3Frustum3::UnitTestIntrOrientedBox3Frustum3()
{
    UTInformation("Mathematics/Intersection/3D/IntrOrientedBox3Frustum3 [NEEDS UNIT TESTS]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Intersection/3D/IntrOrientedBox3Frustum3.h>

namespace gtl
{
    template class TIQuery<float, OrientedBox3<float>, Frustum3<float>>;
    template class TIQuery<double, OrientedBox3<double>, Frustum3<double>>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class TIQuery<Rational, OrientedBox3<Rational>, Frustum3<Rational>>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(IntrOrientedBox3Frustum3)
