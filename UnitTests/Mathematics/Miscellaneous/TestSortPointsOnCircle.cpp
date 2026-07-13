#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Miscellaneous/SortPointsOnCircle.h>
using namespace gtl;

namespace gtl
{
    class UnitTestSortPointsOnCircle
    {
    public:
        UnitTestSortPointsOnCircle();

    private:
    };
}

UnitTestSortPointsOnCircle::UnitTestSortPointsOnCircle()
{
    UTInformation("Mathematics/Miscellaneous/SortPointsOnCircle [NEEDS UNIT TESTS]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Miscellaneous/SortPointsOnCircle.h>

namespace gtl
{
    template class SortPointsOnCircle<float>;
    template class SortPointsOnCircle<double>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class SortPointsOnCircle<Rational>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(SortPointsOnCircle)
