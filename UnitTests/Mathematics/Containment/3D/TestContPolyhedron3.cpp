#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Containment/3D/ContPolyhedron3.h>
using namespace gtl;

namespace gtl
{
    class UnitTestContPolyhedron3
    {
    public:
        UnitTestContPolyhedron3();
    };
}

UnitTestContPolyhedron3::UnitTestContPolyhedron3()
{
    UTInformation("Mathematics/Containment/3D/ContPolyhedron3 [NEEDS UNIT TESTS]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Containment/3D/ContPolyhedron3.h>

namespace gtl
{
    template class ContPolyhedron3<float>;
    template class ContPolyhedron3<double>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class ContPolyhedron3<Rational>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(ContPolyhedron3)
