#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/ImageProcessing/PDEFilter2.h>
using namespace gtl;

namespace gtl
{
    class UnitTestPDEFilter2
    {
    public:
        UnitTestPDEFilter2();
    };
}

UnitTestPDEFilter2::UnitTestPDEFilter2()
{
    UTInformation("Mathematics/ImageProcessing/PDEFilter2 [NEEDS UNIT TESTS]");
}

#else

#include <GTL/Mathematics/ImageProcessing/PDEFilter2.h>

namespace gtl
{
    template class PDEFilter2<std::int32_t>;
    template class PDEFilter2<std::int64_t>;
    template class PDEFilter2<float>;
    template class PDEFilter2<double>;
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(PDEFilter2)
