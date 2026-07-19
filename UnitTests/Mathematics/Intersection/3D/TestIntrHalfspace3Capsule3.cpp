#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Intersection/3D/IntrHalfspace3Capsule3.h>
using namespace gtl;

namespace gtl
{
    class UnitTestIntrHalfspace3Capsule3
    {
    public:
        UnitTestIntrHalfspace3Capsule3();

    private:
    };
}

UnitTestIntrHalfspace3Capsule3::UnitTestIntrHalfspace3Capsule3()
{
    UTInformation("Mathematics/Intersection/3D/IntrHalfspace3Capsule3 [NEEDS UNIT TESTS]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Intersection/3D/IntrHalfspace3Capsule3.h>

namespace gtl
{
    template class TIQuery<float, Halfspace3<float>, Capsule3<float>>;
    template class TIQuery<double, Halfspace3<double>, Capsule3<double>>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class TIQuery<Rational, Halfspace3<Rational>, Capsule3<Rational>>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(IntrHalfspace3Capsule3)
