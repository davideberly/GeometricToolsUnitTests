#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Containment/3D/ContCircle3.h>
using namespace gtl;

namespace gtl
{
    class UnitTestContCircle3
    {
    public:
        UnitTestContCircle3();
    };
}

UnitTestContCircle3::UnitTestContCircle3()
{
    UTInformation("Mathematics/Containment/3D/ContCircle3 [NEEDS UNIT TESTS]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Containment/3D/ContCircle3.h>

namespace gtl
{
    template class ContCircle3<float>;
    template class ContCircle3<double>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class ContCircle3<Rational>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(ContCircle3)
