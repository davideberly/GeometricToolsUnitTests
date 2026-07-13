#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Containment/2D/ContAlignedBox2.h>
using namespace gtl;

namespace gtl
{
    class UnitTestContAlignedBox2
    {
    public:
        UnitTestContAlignedBox2();
    };
}

UnitTestContAlignedBox2::UnitTestContAlignedBox2()
{
    UTInformation("Mathematics/Containment/2D/ContAlignedBox2 [NEEDS UNIT TESTS]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Containment/2D/ContAlignedBox2.h>

namespace gtl
{
    template class ContAlignedBox2<float>;
    template class ContAlignedBox2<double>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class ContAlignedBox2<Rational>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(ContAlignedBox2)
