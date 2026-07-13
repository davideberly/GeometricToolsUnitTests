#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/ImageProcessing/CurvatureFlow3.h>
using namespace gtl;

namespace gtl
{
    class UnitTestCurvatureFlow3
    {
    public:
        UnitTestCurvatureFlow3();
    };
}

UnitTestCurvatureFlow3::UnitTestCurvatureFlow3()
{
    UTInformation("Mathematics/ImageProcessing/CurvatureFlow3 [NEEDS UNIT TESTS]");
}

#else

#include <GTL/Mathematics/ImageProcessing/CurvatureFlow3.h>

namespace gtl
{
    template class CurvatureFlow3<std::int32_t>;
    template class CurvatureFlow3<std::int64_t>;
    template class CurvatureFlow3<float>;
    template class CurvatureFlow3<double>;
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(CurvatureFlow3)
