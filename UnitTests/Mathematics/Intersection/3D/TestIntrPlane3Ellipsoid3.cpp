#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Intersection/3D/IntrPlane3Ellipsoid3.h>
using namespace gtl;

namespace gtl
{
    class UnitTestIntrPlane3Ellipsoid3
    {
    public:
        UnitTestIntrPlane3Ellipsoid3();

    private:
    };
}

UnitTestIntrPlane3Ellipsoid3::UnitTestIntrPlane3Ellipsoid3()
{
    UTInformation("Mathematics/Intersection/3D/IntrPlane3Ellipsoid3 [NEEDS UNIT TESTS]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Intersection/3D/IntrPlane3Ellipsoid3.h>

namespace gtl
{
    template class TIQuery<float, Plane3<float>, Ellipsoid3<float>>;
    template class TIQuery<double, Plane3<double>, Ellipsoid3<double>>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class TIQuery<Rational, Plane3<Rational>, Ellipsoid3<Rational>>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(IntrPlane3Ellipsoid3)
