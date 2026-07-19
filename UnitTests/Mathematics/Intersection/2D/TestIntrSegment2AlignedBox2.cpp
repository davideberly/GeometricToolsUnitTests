#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Intersection/2D/IntrSegment2AlignedBox2.h>
using namespace gtl;

namespace gtl
{
    class UnitTestIntrSegment2AlignedBox2
    {
    public:
        UnitTestIntrSegment2AlignedBox2();

    private:
    };
}

UnitTestIntrSegment2AlignedBox2::UnitTestIntrSegment2AlignedBox2()
{
    UTInformation("Mathematics/Intersection/2D/IntrSegment2AlignedBox2");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Intersection/2D/IntrSegment2AlignedBox2.h>

namespace gtl
{
    template class TIQuery<float, Segment2<float>, AlignedBox2<float>>;
    template class FIQuery<float, Segment2<float>, AlignedBox2<float>>;

    template class TIQuery<double, Segment2<double>, AlignedBox2<double>>;
    template class FIQuery<double, Segment2<double>, AlignedBox2<double>>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class TIQuery<Rational, Segment2<Rational>, AlignedBox2<Rational>>;
    template class FIQuery<Rational, Segment2<Rational>, AlignedBox2<Rational>>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(IntrSegment2AlignedBox2)
