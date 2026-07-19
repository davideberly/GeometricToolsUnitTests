#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Intersection/2D/IntrRay2AlignedBox2.h>
using namespace gtl;

namespace gtl
{
    class UnitTestIntrRay2AlignedBox2
    {
    public:
        UnitTestIntrRay2AlignedBox2();

    private:
    };
}

UnitTestIntrRay2AlignedBox2::UnitTestIntrRay2AlignedBox2()
{
    UTInformation("Mathematics/Intersection/2D/IntrRay2AlignedBox2");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Intersection/2D/IntrRay2AlignedBox2.h>

namespace gtl
{
    template class TIQuery<float, Ray2<float>, AlignedBox2<float>>;
    template class FIQuery<float, Ray2<float>, AlignedBox2<float>>;

    template class TIQuery<double, Ray2<double>, AlignedBox2<double>>;
    template class FIQuery<double, Ray2<double>, AlignedBox2<double>>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class TIQuery<Rational, Ray2<Rational>, AlignedBox2<Rational>>;
    template class FIQuery<Rational, Ray2<Rational>, AlignedBox2<Rational>>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(IntrRay2AlignedBox2)
