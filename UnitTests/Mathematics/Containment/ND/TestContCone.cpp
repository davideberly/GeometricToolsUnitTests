#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Containment/ND/ContCone.h>
#include <random>
using namespace gtl;

namespace gtl
{
    class UnitTestContCone
    {
    public:
        UnitTestContCone();

    private:
        void Test();
    };
}

UnitTestContCone::UnitTestContCone()
{
    UTInformation("Mathematics/Containment/ND/ContCone [NEEDS UNIT TESTS]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Containment/ND/ContCone.h>

namespace gtl
{
    template class ContCone<float, 2>;
    template class ContCone<double, 3>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class ContCone<Rational, 4>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(ContCone)
