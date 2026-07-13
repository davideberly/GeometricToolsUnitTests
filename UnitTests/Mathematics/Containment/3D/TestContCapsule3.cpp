#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Containment/3D/ContCapsule3.h>
using namespace gtl;

namespace gtl
{
    class UnitTestContCapsule3
    {
    public:
        UnitTestContCapsule3();
    };
}

UnitTestContCapsule3::UnitTestContCapsule3()
{
    UTInformation("Mathematics/Containment/3D/ContCapsule3 [NEEDS UNIT TESTS]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Containment/3D/ContCapsule3.h>

namespace gtl
{
    template class ContCapsule3<float>;
    template class ContCapsule3<double>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class ContCapsule3<Rational>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(ContCapsule3)
