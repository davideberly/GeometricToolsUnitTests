#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Intersection/2D/IntrLine2AlignedBox2.h>
using namespace gtl;

namespace gtl
{
    class UnitTestIntrLine2AlignedBox2
    {
    public:
        UnitTestIntrLine2AlignedBox2();

    private:
    };
}

UnitTestIntrLine2AlignedBox2::UnitTestIntrLine2AlignedBox2()
{
    UTInformation("Mathematics/Intersection/2D/IntrLine2AlignedBox2");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Intersection/2D/IntrLine2AlignedBox2.h>

namespace gtl
{
    template class TIQuery<float, Line2<float>, AlignedBox2<float>>;
    template class FIQuery<float, Line2<float>, AlignedBox2<float>>;

    template class TIQuery<double, Line2<double>, AlignedBox2<double>>;
    template class FIQuery<double, Line2<double>, AlignedBox2<double>>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class TIQuery<Rational, Line2<Rational>, AlignedBox2<Rational>>;
    template class FIQuery<Rational, Line2<Rational>, AlignedBox2<Rational>>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(IntrLine2AlignedBox2)
