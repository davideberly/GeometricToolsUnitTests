#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Intersection/3D/IntrCapsule3Capsule3.h>
using namespace gtl;

namespace gtl
{
    class UnitTestIntrCapsule3Capsule3
    {
    public:
        UnitTestIntrCapsule3Capsule3();

    private:
    };
}

UnitTestIntrCapsule3Capsule3::UnitTestIntrCapsule3Capsule3()
{
    UTInformation("Mathematics/Intersection/3D/IntrCapsule3Capsule3 [NEEDS UNIT TESTS]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Intersection/3D/IntrCapsule3Capsule3.h>

namespace gtl
{
    template class TIQuery<float, Capsule3<float>, Capsule3<float>>;
    template class TIQuery<double, Capsule3<double>, Capsule3<double>>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class TIQuery<Rational, Capsule3<Rational>, Capsule3<Rational>>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(IntrCapsule3Capsule3)
