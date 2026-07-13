#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Containment/3D/ContEllipsoid3.h>
using namespace gtl;

namespace gtl
{
    class UnitTestContEllipsoid3
    {
    public:
        UnitTestContEllipsoid3();
    };
}

UnitTestContEllipsoid3::UnitTestContEllipsoid3()
{
    UTInformation("Mathematics/Containment/3D/ContEllipsoid3 [NEEDS UNIT TESTS]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Containment/3D/ContEllipsoid3.h>

namespace gtl
{
    template class ContEllipsoid3<float>;
    template class ContEllipsoid3<double>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class ContEllipsoid3<Rational>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(ContEllipsoid3)
