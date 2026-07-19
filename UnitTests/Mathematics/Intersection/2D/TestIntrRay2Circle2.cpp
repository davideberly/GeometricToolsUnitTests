#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Intersection/2D/IntrRay2Circle2.h>
using namespace gtl;

namespace gtl
{
    class UnitTestIntrRay2Circle2
    {
    public:
        UnitTestIntrRay2Circle2();

    private:
    };
}

UnitTestIntrRay2Circle2::UnitTestIntrRay2Circle2()
{
    UTInformation("Mathematics/Intersection/2D/IntrRay2Circle2 [NEEDS UNIT TESTS]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Intersection/2D/IntrRay2Circle2.h>

namespace gtl
{
    template class TIQuery<float, Ray2<float>, Circle2<float>>;
    template class FIQuery<float, Ray2<float>, Circle2<float>>;

    template class TIQuery<double, Ray2<double>, Circle2<double>>;
    template class FIQuery<double, Ray2<double>, Circle2<double>>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class TIQuery<Rational, Ray2<Rational>, Circle2<Rational>>;
    template class FIQuery<Rational, Ray2<Rational>, Circle2<Rational>>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(IntrRay2Circle2)
