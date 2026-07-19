#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Intersection/3D/IntrSphere3Sphere3.h>
using namespace gtl;

namespace gtl
{
    class UnitTestIntrSphere3Sphere3
    {
    public:
        UnitTestIntrSphere3Sphere3();

    private:
    };
}

UnitTestIntrSphere3Sphere3::UnitTestIntrSphere3Sphere3()
{
    UTInformation("Mathematics/Intersection/3D/IntrSphere3Sphere3 [NEEDS UNIT TESTS]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Intersection/3D/IntrSphere3Sphere3.h>

namespace gtl
{
    template class TIQuery<float, Sphere3<float>, Sphere3<float>>;
    template class FIQuery<float, Sphere3<float>, Sphere3<float>>;

    template class TIQuery<double, Sphere3<double>, Sphere3<double>>;
    template class FIQuery<double, Sphere3<double>, Sphere3<double>>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class TIQuery<Rational, Sphere3<Rational>, Sphere3<Rational>>;
    template class FIQuery<Rational, Sphere3<Rational>, Sphere3<Rational>>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(IntrSphere3Sphere3)
