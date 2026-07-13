#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Intersection/ND/IntrSegmentHyperplane.h>
using namespace gtl;

namespace gtl
{
    class UnitTestIntrSegmentHyperplane
    {
    public:
        UnitTestIntrSegmentHyperplane();

    };
}

UnitTestIntrSegmentHyperplane::UnitTestIntrSegmentHyperplane()
{
    UTInformation("Mathematics/Intersection/ND/IntrSegmentHyperplane [NEEDS UNIT TESTS]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Intersection/ND/IntrSegmentHyperplane.h>

namespace gtl
{
    template class TIQuery<float, Segment<float, 2>, Hyperplane<float, 2>>;
    template class FIQuery<float, Segment<float, 2>, Hyperplane<float, 2>>;

    template class TIQuery<double, Segment<double, 3>, Hyperplane<double, 3>>;
    template class FIQuery<double, Segment<double, 3>, Hyperplane<double, 3>>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class TIQuery<Rational, Segment<Rational, 4>, Hyperplane<Rational, 4>>;
    template class FIQuery<Rational, Segment<Rational, 4>, Hyperplane<Rational, 4>>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(IntrSegmentHyperplane)
