#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/ImageProcessing/FastMarch.h>
using namespace gtl;

namespace gtl
{
    class UnitTestFastMarch
    {
    public:
        UnitTestFastMarch();
    };
}

UnitTestFastMarch::UnitTestFastMarch()
{
    UTInformation("Mathematics/ImageProcessing/FastMarch [NEEDS UNIT TESTS]");
}

#else

#include <GTL/Mathematics/ImageProcessing/FastMarch.h>

namespace gtl
{
    template class FastMarch<float> ;
    template class FastMarch<double>;
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(FastMarch)
