#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Geometry/3D/AlignedBoxBV.h>
using namespace gtl;

namespace gtl
{
    class UnitTestAlignedBoxBV
    {
    public:
        UnitTestAlignedBoxBV();

    private:
    };
}

UnitTestAlignedBoxBV::UnitTestAlignedBoxBV()
{
    UTInformation("Mathematics/Geometry/3D/AlignedBoxBV [NEEDS UNIT TESTING]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Geometry/3D/AlignedBoxBV.h>

namespace gtl
{
    template class AlignedBoxBV<float>;
    template class AlignedBoxBV<double>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class AlignedBoxBV<Rational>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(AlignedBoxBV)
