#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Intersection/2D/IntrOrientedBox2OrientedBox2.h>
using namespace gtl;

namespace gtl
{
    class UnitTestIntrOrientedBox2OrientedBox2
    {
    public:
        UnitTestIntrOrientedBox2OrientedBox2();

    private:
    };
}

UnitTestIntrOrientedBox2OrientedBox2::UnitTestIntrOrientedBox2OrientedBox2()
{
    UTInformation("Mathematics/Intersection/2D/IntrOrientedBox2OrientedBox2 [NEEDS UNIT TESTS]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Intersection/2D/IntrOrientedBox2OrientedBox2.h>

namespace gtl
{
    template class TIQuery<float, OrientedBox2<float>, OrientedBox2<float>>;
    template class FIQuery<float, OrientedBox2<float>, OrientedBox2<float>>;

    template class TIQuery<double, OrientedBox2<double>, OrientedBox2<double>>;
    template class FIQuery<float, OrientedBox2<float>, OrientedBox2<float>>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class TIQuery<Rational, OrientedBox2<Rational>, OrientedBox2<Rational>>;
    template class FIQuery<float, OrientedBox2<float>, OrientedBox2<float>>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(IntrOrientedBox2OrientedBox2)
