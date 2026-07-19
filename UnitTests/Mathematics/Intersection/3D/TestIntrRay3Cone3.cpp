#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Intersection/3D/IntrRay3Cone3.h>
using namespace gtl;

namespace gtl
{
    class UnitTestIntrRay3Cone3
    {
    public:
        UnitTestIntrRay3Cone3();

    private:
    };
}

UnitTestIntrRay3Cone3::UnitTestIntrRay3Cone3()
{
    UTInformation("Mathematics/Intersection/3D/IntrRay3Cone3 [NEEDS UNIT TESTS]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Intersection/3D/IntrRay3Cone3.h>

namespace gtl
{
    template class FIQuery<float, Ray3<float>, Cone3<float>>;
    template class FIQuery<double, Ray3<double>, Cone3<double>>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class FIQuery<Rational, Ray3<Rational>, Cone3<Rational>>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(IntrRay3Cone3)
