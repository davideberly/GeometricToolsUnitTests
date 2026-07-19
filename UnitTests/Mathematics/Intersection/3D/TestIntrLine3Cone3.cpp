#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Intersection/3D/IntrLine3Cone3.h>
using namespace gtl;

namespace gtl
{
    class UnitTestIntrLine3Cone3
    {
    public:
        UnitTestIntrLine3Cone3();

    private:
    };
}

UnitTestIntrLine3Cone3::UnitTestIntrLine3Cone3()
{
    UTInformation("Mathematics/Intersection/3D/IntrLine3Cone3 [NEEDS UNIT TESTS]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Intersection/3D/IntrLine3Cone3.h>

namespace gtl
{
    template class FIQuery<float, Line3<float>, Cone3<float>>;
    template class FIQuery<double, Line3<double>, Cone3<double>>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class FIQuery<Rational, Line3<Rational>, Cone3<Rational>>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(IntrLine3Cone3)
