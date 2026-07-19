#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Intersection/3D/IntrPlane3OrientedBox3.h>
using namespace gtl;

namespace gtl
{
    class UnitTestIntrPlane3OrientedBox3
    {
    public:
        UnitTestIntrPlane3OrientedBox3();

    private:
    };
}

UnitTestIntrPlane3OrientedBox3::UnitTestIntrPlane3OrientedBox3()
{
    UTInformation("Mathematics/Intersection/3D/IntrPlane3OrientedBox3 [NEEDS UNIT TESTS]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Intersection/3D/IntrPlane3OrientedBox3.h>

namespace gtl
{
    template class TIQuery<float, Plane3<float>, OrientedBox3<float>>;
    template class TIQuery<double, Plane3<double>, OrientedBox3<double>>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class TIQuery<Rational, Plane3<Rational>, OrientedBox3<Rational>>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(IntrPlane3OrientedBox3)
