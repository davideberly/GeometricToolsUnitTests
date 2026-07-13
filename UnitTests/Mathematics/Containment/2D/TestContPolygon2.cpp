#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Containment/2D/ContPolygon2.h>
using namespace gtl;

namespace gtl
{
    class UnitTestContPolygon2
    {
    public:
        UnitTestContPolygon2();
    };
}

UnitTestContPolygon2::UnitTestContPolygon2()
{
    UTInformation("Mathematics/Containment/2D/ContPolygon2 [NEEDS UNIT TESTS]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Containment/2D/ContPolygon2.h>

namespace gtl
{
    template class ContPolygon2<float>;
    template class ContPolygon2<double>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class ContPolygon2<Rational>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(ContPolygon2)
