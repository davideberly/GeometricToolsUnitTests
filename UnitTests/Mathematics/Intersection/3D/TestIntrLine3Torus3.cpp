#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Intersection/3D/IntrLine3Torus3.h>
using namespace gtl;

namespace gtl
{
    class UnitTestIntrLine3Torus3
    {
    public:
        UnitTestIntrLine3Torus3();

    private:
    };
}

UnitTestIntrLine3Torus3::UnitTestIntrLine3Torus3()
{
    UTInformation("Mathematics/Intersection/3D/IntrLine3Torus3 [NEEDS UNIT TESTS]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Intersection/3D/IntrLine3Torus3.h>

namespace gtl
{
    template class FIQuery<float, Line3<float>, Torus3<float>>;
    template class FIQuery<double, Line3<double>, Torus3<double>>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class FIQuery<Rational, Line3<Rational>, Torus3<Rational>>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(IntrLine3Torus3)
