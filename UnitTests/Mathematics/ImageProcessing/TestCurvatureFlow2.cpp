#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/ImageProcessing/CurvatureFlow2.h>
using namespace gtl;

namespace gtl
{
    class UnitTestCurvatureFlow2
    {
    public:
        UnitTestCurvatureFlow2();
    };
}

UnitTestCurvatureFlow2::UnitTestCurvatureFlow2()
{
    UTInformation("Mathematics/ImageProcessing/CurvatureFlow2 [NEEDS UNIT TESTS]");
}

#else

#include <GTL/Mathematics/ImageProcessing/CurvatureFlow2.h>

namespace gtl
{
    template class CurvatureFlow2<std::int32_t>;
    template class CurvatureFlow2<std::int64_t>;
    template class CurvatureFlow2<float>;
    template class CurvatureFlow2<double>;
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(CurvatureFlow2)
