#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Intersection/ND/IntrLineHyperplane.h>
using namespace gtl;

namespace gtl
{
    class UnitTestIntrLineHyperplane
    {
    public:
        UnitTestIntrLineHyperplane();

    };
}

UnitTestIntrLineHyperplane::UnitTestIntrLineHyperplane()
{
    UTInformation("Mathematics/Intersection/ND/IntrLineHyperplane [NEEDS UNIT TESTS]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Intersection/ND/IntrLineHyperplane.h>

namespace gtl
{
    template class TIQuery<float, Line<float, 2>, Hyperplane<float, 2>>;
    template class FIQuery<float, Line<float, 2>, Hyperplane<float, 2>>;

    template class TIQuery<double, Line<double, 3>, Hyperplane<double, 3>>;
    template class FIQuery<double, Line<double, 3>, Hyperplane<double, 3>>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class TIQuery<Rational, Line<Rational, 4>, Hyperplane<Rational, 4>>;
    template class FIQuery<Rational, Line<Rational, 4>, Hyperplane<Rational, 4>>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(IntrLineHyperplane)
