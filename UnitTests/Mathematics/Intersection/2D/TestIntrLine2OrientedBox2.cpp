#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Intersection/2D/IntrLine2OrientedBox2.h>
using namespace gtl;

namespace gtl
{
    class UnitTestIntrLine2OrientedBox2
    {
    public:
        UnitTestIntrLine2OrientedBox2();

    private:
    };
}

UnitTestIntrLine2OrientedBox2::UnitTestIntrLine2OrientedBox2()
{
    UTInformation("Mathematics/Intersection/2D/IntrLine2OrientedBox2");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Intersection/2D/IntrLine2OrientedBox2.h>

namespace gtl
{
    template class TIQuery<float, Line2<float>, OrientedBox2<float>>;
    template class FIQuery<float, Line2<float>, OrientedBox2<float>>;

    template class TIQuery<double, Line2<double>, OrientedBox2<double>>;
    template class FIQuery<double, Line2<double>, OrientedBox2<double>>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class TIQuery<Rational, Line2<Rational>, OrientedBox2<Rational>>;
    template class FIQuery<Rational, Line2<Rational>, OrientedBox2<Rational>>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(IntrLine2OrientedBox2)
