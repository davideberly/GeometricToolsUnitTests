#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Intersection/2D/IntrOrientedBox2Cone2.h>
using namespace gtl;

namespace gtl
{
    class UnitTestIntrOrientedBox2Cone2
    {
    public:
        UnitTestIntrOrientedBox2Cone2();

    private:
    };
}

UnitTestIntrOrientedBox2Cone2::UnitTestIntrOrientedBox2Cone2()
{
    UTInformation("Mathematics/Intersection/2D/IntrOrientedBox2Cone2 [NEEDS UNIT TESTS]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Intersection/2D/IntrOrientedBox2Cone2.h>

namespace gtl
{
    template class TIQuery<float, OrientedBox2<float>, Cone2<float>>;
    template class TIQuery<double, OrientedBox2<double>, Cone2<double>>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class TIQuery<Rational, OrientedBox2<Rational>, Cone2<Rational>>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(IntrOrientedBox2Cone2)
