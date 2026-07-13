#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Intersection/ND/IntrRayHyperplane.h>
using namespace gtl;

namespace gtl
{
    class UnitTestIntrRayHyperplane
    {
    public:
        UnitTestIntrRayHyperplane();

    };
}

UnitTestIntrRayHyperplane::UnitTestIntrRayHyperplane()
{
    UTInformation("Mathematics/Intersection/ND/IntrRayHyperplane [NEEDS UNIT TESTS]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Intersection/ND/IntrRayHyperplane.h>

namespace gtl
{
    template class TIQuery<float, Ray<float, 2>, Hyperplane<float, 2>>;
    template class FIQuery<float, Ray<float, 2>, Hyperplane<float, 2>>;

    template class TIQuery<double, Ray<double, 3>, Hyperplane<double, 3>>;
    template class FIQuery<double, Ray<double, 3>, Hyperplane<double, 3>>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class TIQuery<Rational, Ray<Rational, 4>, Hyperplane<Rational, 4>>;
    template class FIQuery<Rational, Ray<Rational, 4>, Hyperplane<Rational, 4>>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(IntrRayHyperplane)
