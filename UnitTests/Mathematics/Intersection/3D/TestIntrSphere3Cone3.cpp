#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Intersection/3D/IntrSphere3Cone3.h>
using namespace gtl;

namespace gtl
{
    class UnitTestIntrSphere3Cone3
    {
    public:
        UnitTestIntrSphere3Cone3();

    private:
    };
}

UnitTestIntrSphere3Cone3::UnitTestIntrSphere3Cone3()
{
    UTInformation("Mathematics/Intersection/3D/IntrSphere3Cone3 [NEEDS UNIT TESTS]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Intersection/3D/IntrSphere3Cone3.h>

namespace gtl
{
    template class TIQuery<float, Sphere3<float>, Cone3<float>>;
    template class FIQuery<float, Sphere3<float>, Cone3<float>>;

    template class TIQuery<double, Sphere3<double>, Cone3<double>>;
    template class FIQuery<double, Sphere3<double>, Cone3<double>>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class TIQuery<Rational, Sphere3<Rational>, Cone3<Rational>>;
    template class FIQuery<Rational, Sphere3<Rational>, Cone3<Rational>>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(IntrSphere3Cone3)
