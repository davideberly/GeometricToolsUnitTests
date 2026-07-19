#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Intersection/3D/IntrPlane3Sphere3.h>
using namespace gtl;

namespace gtl
{
    class UnitTestIntrPlane3Sphere3
    {
    public:
        UnitTestIntrPlane3Sphere3();

    private:
    };
}

UnitTestIntrPlane3Sphere3::UnitTestIntrPlane3Sphere3()
{
    UTInformation("Mathematics/Intersection/3D/IntrPlane3Sphere3 [NEEDS UNIT TESTS]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Intersection/3D/IntrPlane3Sphere3.h>

namespace gtl
{
    template class TIQuery<float, Plane3<float>, Sphere3<float>>;
    template class FIQuery<float, Plane3<float>, Sphere3<float>>;

    template class TIQuery<double, Plane3<double>, Sphere3<double>>;
    template class FIQuery<double, Plane3<double>, Sphere3<double>>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class TIQuery<Rational, Plane3<Rational>, Sphere3<Rational>>;
    template class FIQuery<Rational, Plane3<Rational>, Sphere3<Rational>>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(IntrPlane3Sphere3)
