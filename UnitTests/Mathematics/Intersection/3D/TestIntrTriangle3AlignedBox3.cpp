#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Intersection/3D/IntrTriangle3AlignedBox3.h>
using namespace gtl;

namespace gtl
{
    class UnitTestIntrTriangle3AlignedBox3
    {
    public:
        UnitTestIntrTriangle3AlignedBox3();

    private:
    };
}

UnitTestIntrTriangle3AlignedBox3::UnitTestIntrTriangle3AlignedBox3()
{
    UTInformation("Mathematics/Intersection/3D/IntrTriangle3AlignedBox3 [NEEDS UNIT TESTS]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Intersection/3D/IntrTriangle3AlignedBox3.h>

namespace gtl
{
    template class TIQuery<float, Triangle3<float>, AlignedBox3<float>>;
    template class FIQuery<float, Triangle3<float>, AlignedBox3<float>>;

    template class TIQuery<double, Triangle3<double>, AlignedBox3<double>>;
    template class FIQuery<double, Triangle3<double>, AlignedBox3<double>>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class TIQuery<Rational, Triangle3<Rational>, CanonicalBox3<Rational>>;
    template class FIQuery<Rational, Triangle3<Rational>, CanonicalBox3<Rational>>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(IntrTriangle3AlignedBox3)
