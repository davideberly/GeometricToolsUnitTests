#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Intersection/2D/IntrLine2Arc2.h>
using namespace gtl;

namespace gtl
{
    class UnitTestIntrLine2Arc2
    {
    public:
        UnitTestIntrLine2Arc2();

    private:
    };
}

UnitTestIntrLine2Arc2::UnitTestIntrLine2Arc2()
{
    UTInformation("Mathematics/Intersection/2D/IntrLine2Arc2 [NEEDS UNIT TESTS]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Intersection/2D/IntrLine2Arc2.h>

namespace gtl
{
    template class TIQuery<float, Line2<float>, Arc2<float>>;
    template class FIQuery<float, Line2<float>, Arc2<float>>;

    template class TIQuery<double, Line2<double>, Arc2<double>>;
    template class FIQuery<double, Line2<double>, Arc2<double>>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class TIQuery<Rational, Line2<Rational>, Arc2<Rational>>;
    template class FIQuery<Rational, Line2<Rational>, Arc2<Rational>>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(IntrLine2Arc2)
