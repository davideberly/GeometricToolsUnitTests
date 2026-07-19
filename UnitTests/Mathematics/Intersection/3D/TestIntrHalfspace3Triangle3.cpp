#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Intersection/3D/IntrHalfspace3Triangle3.h>
using namespace gtl;

namespace gtl
{
    class UnitTestIntrHalfspace3Triangle3
    {
    public:
        UnitTestIntrHalfspace3Triangle3();

    private:
    };
}

UnitTestIntrHalfspace3Triangle3::UnitTestIntrHalfspace3Triangle3()
{
    UTInformation("Mathematics/Intersection/3D/IntrHalfspace3Triangle3 [NEEDS UNIT TESTS]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Intersection/3D/IntrHalfspace3Triangle3.h>

namespace gtl
{
    template class TIQuery<float, Halfspace3<float>, Triangle3<float>>;
    template class FIQuery<float, Halfspace3<float>, Triangle3<float>>;

    template class TIQuery<double, Halfspace3<double>, Triangle3<double>>;
    template class FIQuery<double, Halfspace3<double>, Triangle3<double>>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class TIQuery<Rational, Halfspace3<Rational>, Triangle3<Rational>>;
    template class FIQuery<Rational, Halfspace3<Rational>, Triangle3<Rational>>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(IntrHalfspace3Triangle3)
