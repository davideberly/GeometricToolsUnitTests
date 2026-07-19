#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Intersection/3D/IntrSphere3Triangle3.h>
using namespace gtl;

namespace gtl
{
    class UnitTestIntrSphere3Triangle3
    {
    public:
        UnitTestIntrSphere3Triangle3();

    private:
    };
}

UnitTestIntrSphere3Triangle3::UnitTestIntrSphere3Triangle3()
{
    UTInformation("Mathematics/Intersection/3D/IntrSphere3Triangle3 [NEEDS UNIT TESTS]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Intersection/3D/IntrSphere3Triangle3.h>

namespace gtl
{
    template class FIQuery<float, Sphere3<float>, Triangle3<float>>;
    template class FIQuery<double, Sphere3<double>, Triangle3<double>>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class FIQuery<Rational, Sphere3<Rational>, Triangle3<Rational>>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(IntrSphere3Triangle3)
