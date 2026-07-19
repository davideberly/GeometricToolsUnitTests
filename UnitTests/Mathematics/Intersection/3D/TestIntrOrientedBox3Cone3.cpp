#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Intersection/3D/IntrOrientedBox3Cone3.h>
using namespace gtl;

namespace gtl
{
    class UnitTestIntrOrientedBox3Cone3
    {
    public:
        UnitTestIntrOrientedBox3Cone3();

    private:
    };
}

UnitTestIntrOrientedBox3Cone3::UnitTestIntrOrientedBox3Cone3()
{
    UTInformation("Mathematics/Intersection/3D/IntrOrientedBox3Cone3 [NEEDS UNIT TESTS]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Intersection/3D/IntrOrientedBox3Cone3.h>

namespace gtl
{
    template class TIQuery<float, OrientedBox3<float>, Cone3<float>>;
    template class TIQuery<double, OrientedBox3<double>, Cone3<double>>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class TIQuery<Rational, OrientedBox3<Rational>, Cone3<Rational>>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(IntrOrientedBox3Cone3)
