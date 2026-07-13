#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Containment/3D/ContCylinder3.h>
using namespace gtl;

namespace gtl
{
    class UnitTestContCylinder3
    {
    public:
        UnitTestContCylinder3();
    };
}

UnitTestContCylinder3::UnitTestContCylinder3()
{
    UTInformation("Mathematics/Containment/3D/ContCylinder3 [NEEDS UNIT TESTS]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Containment/3D/ContCylinder3.h>

namespace gtl
{
    template class ContCylinder3<float>;
    template class ContCylinder3<double>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class ContCylinder3<Rational>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(ContCylinder3)
