#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Intersection/3D/IntrAlignedBox3Cylinder3.h>
using namespace gtl;

namespace gtl
{
    class UnitTestIntrAlignedBox3Cylinder3
    {
    public:
        UnitTestIntrAlignedBox3Cylinder3();

    private:
    };
}

UnitTestIntrAlignedBox3Cylinder3::UnitTestIntrAlignedBox3Cylinder3()
{
    UTInformation("Mathematics/Intersection/3D/IntrAlignedBox3Cylinder3 [NEEDS UNIT TESTS]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Intersection/3D/IntrAlignedBox3Cylinder3.h>

namespace gtl
{
    template class TIQuery<float, AlignedBox3<float>, Cylinder3<float>>;
    template class TIQuery<double, AlignedBox3<double>, Cylinder3<double>>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class TIQuery<Rational, AlignedBox3<Rational>, Cylinder3<Rational>>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(IntrAlignedBox3Cylinder3)
