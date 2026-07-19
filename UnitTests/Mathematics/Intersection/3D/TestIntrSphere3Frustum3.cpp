#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Intersection/3D/IntrSphere3Frustum3.h>
using namespace gtl;

namespace gtl
{
    class UnitTestIntrSphere3Frustum3
    {
    public:
        UnitTestIntrSphere3Frustum3();

    private:
    };
}

UnitTestIntrSphere3Frustum3::UnitTestIntrSphere3Frustum3()
{
    UTInformation("Mathematics/Intersection/3D/IntrSphere3Frustum3 [NEEDS UNIT TESTS]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Intersection/3D/IntrSphere3Frustum3.h>

namespace gtl
{
    template class TIQuery<float, Sphere3<float>, Frustum3<float>>;
    template class TIQuery<double, Sphere3<double>, Frustum3<double>>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class TIQuery<Rational, Sphere3<Rational>, Frustum3<Rational>>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(IntrSphere3Frustum3)
