#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Containment/2D/ContEllipse2.h>
using namespace gtl;

namespace gtl
{
    class UnitTestContEllipse2
    {
    public:
        UnitTestContEllipse2();
    };
}

UnitTestContEllipse2::UnitTestContEllipse2()
{
    UTInformation("Mathematics/Containment/2D/ContEllipse2 [NEEDS UNIT TESTS]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Containment/2D/ContEllipse2.h>

namespace gtl
{
    template class ContEllipse2<float>;
    template class ContEllipse2<double>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class ContEllipse2<Rational>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(ContEllipse2)
