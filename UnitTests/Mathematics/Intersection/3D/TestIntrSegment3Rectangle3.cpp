#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Intersection/3D/IntrSegment3Rectangle3.h>
using namespace gtl;

namespace gtl
{
    class UnitTestIntrSegment3Rectangle3
    {
    public:
        UnitTestIntrSegment3Rectangle3();

    private:
    };
}

UnitTestIntrSegment3Rectangle3::UnitTestIntrSegment3Rectangle3()
{
    UTInformation("Mathematics/Intersection/3D/IntrSegment3Rectangle3 [NEEDS UNIT TESTS]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Intersection/3D/IntrSegment3Rectangle3.h>

namespace gtl
{
    template class TIQuery<float, Segment3<float>, Rectangle3<float>>;
    template class FIQuery<float, Segment3<float>, Rectangle3<float>>;

    template class TIQuery<double, Segment3<double>, Rectangle3<double>>;
    template class FIQuery<double, Segment3<double>, Rectangle3<double>>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class TIQuery<Rational, Segment3<Rational>, Rectangle3<Rational>>;
    template class FIQuery<Rational, Segment3<Rational>, Rectangle3<Rational>>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(IntrSegment3Rectangle3)
