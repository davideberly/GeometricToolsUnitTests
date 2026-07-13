#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Geometry/2D/IsPlanarGraph.h>
#include <GTL/Utility/Timer.h>
#include <random>
using namespace gtl;

namespace gtl
{
    class UnitTestIsPlanarGraph
    {
    public:
        UnitTestIsPlanarGraph();
    };
}

UnitTestIsPlanarGraph::UnitTestIsPlanarGraph()
{
    UTInformation("Mathematics/Geometry/2D/IsPlanarGraph [NEEDS UNIT TESTS]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Geometry/2D/IsPlanarGraph.h>

namespace gtl
{
    template class IsPlanarGraph<float>;
    template class IsPlanarGraph<double>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class IsPlanarGraph<Rational>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(IsPlanarGraph)
