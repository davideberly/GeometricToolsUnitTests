#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Intersection/3D/IntrHalfspace3OrientedBox3.h>
using namespace gtl;

namespace gtl
{
    class UnitTestIntrHalfspace3OrientedBox3
    {
    public:
        UnitTestIntrHalfspace3OrientedBox3();

    private:
    };
}

UnitTestIntrHalfspace3OrientedBox3::UnitTestIntrHalfspace3OrientedBox3()
{
    UTInformation("Mathematics/Intersection/3D/IntrHalfspace3OrientedBox3 [NEEDS UNIT TESTS]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Intersection/3D/IntrHalfspace3OrientedBox3.h>

namespace gtl
{
    template class TIQuery<float, Halfspace3<float>, OrientedBox3<float>>;
    template class TIQuery<double, Halfspace3<double>, OrientedBox3<double>>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class TIQuery<Rational, Halfspace3<Rational>, OrientedBox3<Rational>>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(IntrHalfspace3OrientedBox3)
