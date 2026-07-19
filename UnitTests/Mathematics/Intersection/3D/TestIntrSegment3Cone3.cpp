#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Intersection/3D/IntrSegment3Cone3.h>
using namespace gtl;

namespace gtl
{
    class UnitTestIntrSegment3Cone3
    {
    public:
        UnitTestIntrSegment3Cone3();

    private:
    };
}

UnitTestIntrSegment3Cone3::UnitTestIntrSegment3Cone3()
{
    UTInformation("Mathematics/Intersection/3D/IntrSegment3Cone3 [NEEDS UNIT TESTS]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Intersection/3D/IntrSegment3Cone3.h>

namespace gtl
{
    template class FIQuery<float, Segment3<float>, Cone3<float>>;
    template class FIQuery<double, Segment3<double>, Cone3<double>>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class FIQuery<Rational, Segment3<Rational>, Cone3<Rational>>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(IntrSegment3Cone3)
