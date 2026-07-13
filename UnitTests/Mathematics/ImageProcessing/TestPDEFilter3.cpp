#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/ImageProcessing/PDEFilter3.h>
using namespace gtl;

namespace gtl
{
    class UnitTestPDEFilter3
    {
    public:
        UnitTestPDEFilter3();
    };
}

UnitTestPDEFilter3::UnitTestPDEFilter3()
{
    UTInformation("Mathematics/ImageProcessing/PDEFilter3 [NEEDS UNIT TESTS]");
}

#else

#include <GTL/Mathematics/ImageProcessing/PDEFilter3.h>

namespace gtl
{
    template class PDEFilter3<std::int32_t>;
    template class PDEFilter3<std::int64_t>;
    template class PDEFilter3<float>;
    template class PDEFilter3<double>;
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(PDEFilter3)
