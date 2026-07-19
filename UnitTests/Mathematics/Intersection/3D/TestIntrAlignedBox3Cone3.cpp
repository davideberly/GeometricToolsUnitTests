#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Intersection/3D/IntrAlignedBox3Cone3.h>
using namespace gtl;

namespace gtl
{
    class UnitTestIntrAlignedBox3Cone3
    {
    public:
        UnitTestIntrAlignedBox3Cone3();

    private:
    };
}

UnitTestIntrAlignedBox3Cone3::UnitTestIntrAlignedBox3Cone3()
{
    UTInformation("Mathematics/Intersection/3D/IntrAlignedBox3Cone3 [NEEDS UNIT TESTS]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Intersection/3D/IntrAlignedBox3Cone3.h>

namespace gtl
{
    template class TIQuery<float, AlignedBox3<float>, Cone3<float>>;
    template class TIQuery<double, AlignedBox3<double>, Cone3<double>>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class TIQuery<Rational, AlignedBox3<Rational>, Cone3<Rational>>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(IntrAlignedBox3Cone3)
