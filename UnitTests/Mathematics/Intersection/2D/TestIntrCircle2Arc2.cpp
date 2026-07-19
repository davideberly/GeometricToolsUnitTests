#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Intersection/2D/IntrCircle2Arc2.h>
using namespace gtl;

namespace gtl
{
    class UnitTestIntrCircle2Arc2
    {
    public:
        UnitTestIntrCircle2Arc2();

    private:
    };
}

UnitTestIntrCircle2Arc2::UnitTestIntrCircle2Arc2()
{
    UTInformation("Mathematics/Intersection/2D/IntrCircle2Arc2 [NEEDS UNIT TESTS]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Intersection/2D/IntrCircle2Arc2.h>

namespace gtl
{
    template class FIQuery<float, Circle2<float>, Arc2<float>>;
    template class FIQuery<double, Circle2<double>, Arc2<double>>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class FIQuery<Rational, Circle2<Rational>, Arc2<Rational>>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(IntrCircle2Arc2)
