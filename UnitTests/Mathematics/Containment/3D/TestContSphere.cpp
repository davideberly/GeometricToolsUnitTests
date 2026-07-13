#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Containment/3D/ContSphere3.h>
using namespace gtl;

namespace gtl
{
    class UnitTestContSphere3
    {
    public:
        UnitTestContSphere3();
    };
}

UnitTestContSphere3::UnitTestContSphere3()
{
    UTInformation("Mathematics/Containment/3D/ContSphere3 [NEEDS UNIT TESTS]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Containment/3D/ContSphere3.h>

namespace gtl
{
    template class ContSphere3<float>;
    template class ContSphere3<double>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class ContSphere3<Rational>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(ContSphere3)
