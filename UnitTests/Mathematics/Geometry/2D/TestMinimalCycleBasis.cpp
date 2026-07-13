#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Geometry/2D/MinimalCycleBasis.h>
#include <GTL/Utility/Timer.h>
#include <random>
using namespace gtl;

namespace gtl
{
    class UnitTestMinimalCycleBasis
    {
    public:
        UnitTestMinimalCycleBasis();
    };
}

UnitTestMinimalCycleBasis::UnitTestMinimalCycleBasis()
{
    UTInformation("Mathematics/Geometry/2D/MinimalCycleBasis [NEEDS UNIT TESTS]");
}

#else

// TODO: The MinimalCycleBasis constructor has a static assert that the
// template type is a floating-point type and not an arbitrary-precision type.
// The MSVS 2026 compiler does not throw the static assert when the type is
// Rational. Is this a compiler bug? Or am I missing something about type
// traits?
//#if defined(GTL_INSTANTIATE_RATIONAL)
//#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
//#endif
#include <GTL/Mathematics/Geometry/2D/MinimalCycleBasis.h>

namespace gtl
{
    template class MinimalCycleBasis<float>;
    template class MinimalCycleBasis<double>;

//#if defined(GTL_INSTANTIATE_RATIONAL)
//    using Rational = BSRational<UIntegerAP32>;
//    template class MinimalCycleBasis<Rational>;
//#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(MinimalCycleBasis)
