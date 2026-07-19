#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Intersection/2D/IntrAlignedBox2OrientedBox2.h>
using namespace gtl;

namespace gtl
{
    class UnitTestIntrAlignedBox2OrientedBox2
    {
    public:
        UnitTestIntrAlignedBox2OrientedBox2();

    private:
    };
}

UnitTestIntrAlignedBox2OrientedBox2::UnitTestIntrAlignedBox2OrientedBox2()
{
    UTInformation("Mathematics/Intersection/2D/IntrAlignedBox2OrientedBox2 [NEEDS UNIT TESTS]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Intersection/2D/IntrAlignedBox2OrientedBox2.h>

namespace gtl
{
    template class TIQuery<float, AlignedBox2<float>, OrientedBox2<float>>;
    template class TIQuery<double, AlignedBox2<double>, OrientedBox2<double>>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class TIQuery<Rational, AlignedBox2<Rational>, OrientedBox2<Rational>>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(IntrAlignedBox2OrientedBox2)
