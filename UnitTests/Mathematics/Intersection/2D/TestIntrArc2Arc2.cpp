#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Intersection/2D/IntrArc2Arc2.h>
using namespace gtl;

namespace gtl
{
    class UnitTestIntrArc2Arc2
    {
    public:
        UnitTestIntrArc2Arc2();

    private:
    };
}

UnitTestIntrArc2Arc2::UnitTestIntrArc2Arc2()
{
    UTInformation("Mathematics/Intersection/2D/IntrArc2Arc2 [NEEDS UNIT TESTS]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Intersection/2D/IntrArc2Arc2.h>

namespace gtl
{
    template class FIQuery<float, Arc2<float>, Arc2<float>>;
    template class FIQuery<double, Arc2<double>, Arc2<double>>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class FIQuery<Rational, Arc2<Rational>, Arc2<Rational>>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(IntrArc2Arc2)
