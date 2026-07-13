#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Containment/2D/ContOrientedBox2.h>
using namespace gtl;

namespace gtl
{
    class UnitTestContOrientedBox2
    {
    public:
        UnitTestContOrientedBox2();
    };
}

UnitTestContOrientedBox2::UnitTestContOrientedBox2()
{
    UTInformation("Mathematics/Containment/2D/ContOrientedBox2 [tested by GTL/VisualTests/Mathematics/Approximation/2D/ApproximateEllipse2]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Containment/2D/ContOrientedBox2.h>

namespace gtl
{
    template class ContOrientedBox2<float>;
    template class ContOrientedBox2<double>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class ContOrientedBox2<Rational>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(ContOrientedBox2)
