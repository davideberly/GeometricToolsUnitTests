#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Geometry/3D/ConformalMapGenusZero.h>
using namespace gtl;

namespace gtl
{
    class UnitTestConformalMapGenusZero
    {
    public:
        UnitTestConformalMapGenusZero();

    private:
    };
}

UnitTestConformalMapGenusZero::UnitTestConformalMapGenusZero()
{
    UTInformation("Mathematics/Geometry/3D/ConformalMapGenusZero [NEEDS UNIT TESTING]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Geometry/3D/ConformalMapGenusZero.h>

namespace gtl
{
    template class ConformalMapGenusZero<float>;
    template class ConformalMapGenusZero<double>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class ConformalMapGenusZero<Rational>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(ConformalMapGenusZero)
