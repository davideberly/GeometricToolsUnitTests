#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Intersection/2D/IntrHalfspace2Polygon2.h>
using namespace gtl;

namespace gtl
{
    class UnitTestIntrHalfspace2Polygon2
    {
    public:
        UnitTestIntrHalfspace2Polygon2();

    private:
    };
}

UnitTestIntrHalfspace2Polygon2::UnitTestIntrHalfspace2Polygon2()
{
    UTInformation("Mathematics/Intersection/2D/IntrHalfspace2Polygon2 [NEEDS UNIT TESTS]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Intersection/2D/IntrHalfspace2Polygon2.h>

namespace gtl
{
    template class FIQuery<float, Halfspace2<float>, std::vector<Vector2<float>>>;
    template class FIQuery<double, Halfspace2<double>, std::vector<Vector2<double>>>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class FIQuery<Rational, Halfspace2<Rational>, std::vector<Vector2<Rational>>>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(IntrHalfspace2Polygon2)
