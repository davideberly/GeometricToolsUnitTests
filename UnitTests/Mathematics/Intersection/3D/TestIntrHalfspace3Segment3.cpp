#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Intersection/3D/IntrHalfspace3Segment3.h>
using namespace gtl;

namespace gtl
{
    class UnitTestIntrHalfspace3Segment3
    {
    public:
        UnitTestIntrHalfspace3Segment3();

    private:
    };
}

UnitTestIntrHalfspace3Segment3::UnitTestIntrHalfspace3Segment3()
{
    UTInformation("Mathematics/Intersection/3D/IntrHalfspace3Segment3 [NEEDS UNIT TESTS]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Intersection/3D/IntrHalfspace3Segment3.h>

namespace gtl
{
    template class TIQuery<float, Halfspace3<float>, Segment3<float>>;
    template class FIQuery<float, Halfspace3<float>, Segment3<float>>;

    template class TIQuery<double, Halfspace3<double>, Segment3<double>>;
    template class FIQuery<double, Halfspace3<double>, Segment3<double>>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class TIQuery<Rational, Halfspace3<Rational>, Segment3<Rational>>;
    template class FIQuery<Rational, Halfspace3<Rational>, Segment3<Rational>>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(IntrHalfspace3Segment3)
