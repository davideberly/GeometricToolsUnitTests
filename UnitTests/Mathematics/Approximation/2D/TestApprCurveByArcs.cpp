#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Approximation/2D/ApprCurveByArcs.h>
#include <random>
using namespace gtl;

namespace gtl
{
    class UnitTestApprCurveByArcs
    {
    public:
        UnitTestApprCurveByArcs();

    private:
    };
}

UnitTestApprCurveByArcs::UnitTestApprCurveByArcs()
{
    UTInformation("Mathematics/Approximation/2D/ApprCurveByArcs [tested by GTL/VisualTests/Approximation/ApproximationBezierCurveByArcs]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Approximation/2D/ApprCurveByArcs.h>

namespace gtl
{
    template class ApprCurveByArcs<float>;
    template class ApprCurveByArcs<double>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class ApprCurveByArcs<Rational>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(ApprCurveByArcs)
