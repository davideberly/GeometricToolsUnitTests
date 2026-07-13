#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Geometry/2D/TriangulateEC.h>
#include <GTL/Utility/Timer.h>
#include <random>
using namespace gtl;

namespace gtl
{
    class UnitTestTriangulateEC
    {
    public:
        UnitTestTriangulateEC();
    };
}

UnitTestTriangulateEC::UnitTestTriangulateEC()
{
    UTInformation("Mathematics/Geometry/2D/TriangulateEC [NEEDS UNIT TESTS]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Geometry/2D/TriangulateEC.h>

namespace gtl
{
    template class TriangulateEC<float, double>;
    template class TriangulateEC<double, double>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class TriangulateEC<Rational, Rational>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(TriangulateEC)
