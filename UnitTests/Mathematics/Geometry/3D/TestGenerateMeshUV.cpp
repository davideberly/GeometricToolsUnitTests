#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Geometry/3D/GenerateMeshUV.h>
using namespace gtl;

namespace gtl
{
    class UnitTestGenerateMeshUV
    {
    public:
        UnitTestGenerateMeshUV();

    private:
    };
}

UnitTestGenerateMeshUV::UnitTestGenerateMeshUV()
{
    UTInformation("Mathematics/Geometry/3D/GenerateMeshUV [NEEDS UNIT TESTING]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Geometry/3D/GenerateMeshUV.h>

namespace gtl
{
    template class GenerateMeshUV<float>;
    template class GenerateMeshUV<double>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class GenerateMeshUV<Rational>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(GenerateMeshUV)
