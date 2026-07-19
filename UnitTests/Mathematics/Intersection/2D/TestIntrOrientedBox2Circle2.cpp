#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Intersection/2D/IntrOrientedBox2Circle2.h>
using namespace gtl;

namespace gtl
{
    class UnitTestIntrOrientedBox2Circle2
    {
    public:
        UnitTestIntrOrientedBox2Circle2();

    private:
    };
}

UnitTestIntrOrientedBox2Circle2::UnitTestIntrOrientedBox2Circle2()
{
    UTInformation("Mathematics/Intersection/2D/IntrOrientedBox2Circle2 [NEEDS UNIT TESTS]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Intersection/2D/IntrOrientedBox2Circle2.h>

namespace gtl
{
    template class TIQuery<float, OrientedBox2<float>, Circle2<float>>;
    template class FIQuery<float, OrientedBox2<float>, Circle2<float>>;

    template class TIQuery<double, OrientedBox2<double>, Circle2<double>>;
    template class FIQuery<double, OrientedBox2<double>, Circle2<double>>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class TIQuery<Rational, OrientedBox2<Rational>, Circle2<Rational>>;
    template class FIQuery<Rational, OrientedBox2<Rational>, Circle2<Rational>>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(IntrOrientedBox2Circle2)
