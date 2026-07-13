#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Geometry/2D/MinimumAreaCircle2.h>
#include <GTL/Utility/Timer.h>
#include <random>
using namespace gtl;

namespace gtl
{
    class UnitTestMinimumAreaCircle2
    {
    public:
        UnitTestMinimumAreaCircle2();
    };
}

UnitTestMinimumAreaCircle2::UnitTestMinimumAreaCircle2()
{
    UTInformation("Mathematics/Geometry/2D/MinimumAreaCircle2 [NEEDS UNIT TESTS]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Geometry/2D/MinimumAreaCircle2.h>

namespace gtl
{
    template class MinimumAreaCircle2<float, double>;
    template class MinimumAreaCircle2<double, double>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class MinimumAreaCircle2<Rational, Rational>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(MinimumAreaCircle2)
