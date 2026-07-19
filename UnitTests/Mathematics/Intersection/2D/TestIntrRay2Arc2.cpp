#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Intersection/2D/IntrRay2Arc2.h>
using namespace gtl;

namespace gtl
{
    class UnitTestIntrRay2Arc2
    {
    public:
        UnitTestIntrRay2Arc2();

    private:
    };
}

UnitTestIntrRay2Arc2::UnitTestIntrRay2Arc2()
{
    UTInformation("Mathematics/Intersection/2D/IntrRay2Arc2 [NEEDS UNIT TESTS]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Intersection/2D/IntrRay2Arc2.h>

namespace gtl
{
    template class TIQuery<float, Ray2<float>, Arc2<float>>;
    template class FIQuery<float, Ray2<float>, Arc2<float>>;

    template class TIQuery<double, Ray2<double>, Arc2<double>>;
    template class FIQuery<double, Ray2<double>, Arc2<double>>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class TIQuery<Rational, Ray2<Rational>, Arc2<Rational>>;
    template class FIQuery<Rational, Ray2<Rational>, Arc2<Rational>>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(IntrRay2Arc2)
