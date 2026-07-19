#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Geometry/3D/ExtremalQuery3BSP.h>
using namespace gtl;

namespace gtl
{
    class UnitTestExtremalQuery3BSP
    {
    public:
        UnitTestExtremalQuery3BSP();

    private:
    };
}

UnitTestExtremalQuery3BSP::UnitTestExtremalQuery3BSP()
{
    UTInformation("Mathematics/Geometry/3D/ExtremalQuery3BSP [NEEDS UNIT TESTING]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Geometry/3D/ExtremalQuery3BSP.h>

namespace gtl
{
    template class ExtremalQuery3BSP<float>;
    template class ExtremalQuery3BSP<double>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class ExtremalQuery3BSP<Rational>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(ExtremalQuery3BSP)
