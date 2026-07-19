#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Intersection/2D/IntrSegment2OrientedBox2.h>
using namespace gtl;

namespace gtl
{
    class UnitTestIntrSegment2OrientedBox2
    {
    public:
        UnitTestIntrSegment2OrientedBox2();

    private:
    };
}

UnitTestIntrSegment2OrientedBox2::UnitTestIntrSegment2OrientedBox2()
{
    UTInformation("Mathematics/Intersection/2D/IntrSegment2OrientedBox2");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Intersection/2D/IntrSegment2OrientedBox2.h>

namespace gtl
{
    template class TIQuery<float, Segment2<float>, OrientedBox2<float>>;
    template class FIQuery<float, Segment2<float>, OrientedBox2<float>>;

    template class TIQuery<double, Segment2<double>, OrientedBox2<double>>;
    template class FIQuery<double, Segment2<double>, OrientedBox2<double>>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class TIQuery<Rational, Segment2<Rational>, OrientedBox2<Rational>>;
    template class FIQuery<Rational, Segment2<Rational>, OrientedBox2<Rational>>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(IntrSegment2OrientedBox2)
