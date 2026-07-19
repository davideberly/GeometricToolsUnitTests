#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Intersection/3D/IntrEllipsoid3Ellipsoid3.h>
using namespace gtl;

namespace gtl
{
    class UnitTestIntrEllipsoid3Ellipsoid3
    {
    public:
        UnitTestIntrEllipsoid3Ellipsoid3();

    private:
    };
}

UnitTestIntrEllipsoid3Ellipsoid3::UnitTestIntrEllipsoid3Ellipsoid3()
{
    UTInformation("Mathematics/Intersection/3D/IntrEllipsoid3Ellipsoid3 [NEEDS UNIT TESTS]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Intersection/3D/IntrEllipsoid3Ellipsoid3.h>

namespace gtl
{
    template class TIQuery<float, Ellipsoid3<float>, Ellipsoid3<float>>;
    template class TIQuery<double, Ellipsoid3<double>, Ellipsoid3<double>>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class TIQuery<Rational, Ellipsoid3<Rational>, Ellipsoid3<Rational>>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(IntrEllipsoid3Ellipsoid3)
