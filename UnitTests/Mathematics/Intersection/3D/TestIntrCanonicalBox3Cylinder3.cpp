#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Intersection/3D/IntrCanonicalBox3Cylinder3.h>
using namespace gtl;

namespace gtl
{
    class UnitTestIntrCanonicalBox3Cylinder3
    {
    public:
        UnitTestIntrCanonicalBox3Cylinder3();

    private:
    };
}

UnitTestIntrCanonicalBox3Cylinder3::UnitTestIntrCanonicalBox3Cylinder3()
{
    UTInformation("Mathematics/Intersection/3D/IntrCanonicalBox3Cylinder3 [NEEDS UNIT TESTS]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Intersection/3D/IntrCanonicalBox3Cylinder3.h>

namespace gtl
{
    template class TIQuery<float, CanonicalBox3<float>, Cylinder3<float>>;
    template class TIQuery<double, CanonicalBox3<double>, Cylinder3<double>>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class TIQuery<Rational, CanonicalBox3<Rational>, Cylinder3<Rational>>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(IntrCanonicalBox3Cylinder3)
