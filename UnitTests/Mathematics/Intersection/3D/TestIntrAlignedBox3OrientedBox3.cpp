#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Intersection/3D/IntrAlignedBox3OrientedBox3.h>
using namespace gtl;

namespace gtl
{
    class UnitTestIntrAlignedBox3OrientedBox3
    {
    public:
        UnitTestIntrAlignedBox3OrientedBox3();

    private:
    };
}

UnitTestIntrAlignedBox3OrientedBox3::UnitTestIntrAlignedBox3OrientedBox3()
{
    UTInformation("Mathematics/Intersection/3D/IntrAlignedBox3OrientedBox3 [NEEDS UNIT TESTS]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Intersection/3D/IntrAlignedBox3OrientedBox3.h>

namespace gtl
{
    template class TIQuery<float, AlignedBox3<float>, OrientedBox3<float>>;
    template class TIQuery<double, AlignedBox3<double>, OrientedBox3<double>>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class TIQuery<Rational, AlignedBox3<Rational>, OrientedBox3<Rational>>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(IntrAlignedBox3OrientedBox3)
