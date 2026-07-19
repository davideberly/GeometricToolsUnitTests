#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Geometry/ND/CLODPolyline.h>
using namespace gtl;

namespace gtl
{
    class UnitTestCLODPolyline
    {
    public:
        UnitTestCLODPolyline();

    private:
    };
}

UnitTestCLODPolyline::UnitTestCLODPolyline()
{
    UTInformation("Mathematics/Geometry/ND/CLODPolyline");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Geometry/ND/CLODPolyline.h>

namespace gtl
{
    template class CLODPolyline<float, 2>;
    template class CLODPolyline<double, 3>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class CLODPolyline<Rational, 4>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(CLODPolyline)
