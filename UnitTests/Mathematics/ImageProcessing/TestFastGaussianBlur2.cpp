#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/ImageProcessing/FastGaussianBlur2.h>
using namespace gtl;

namespace gtl
{
    class UnitTestFastGaussianBlur2
    {
    public:
        UnitTestFastGaussianBlur2();
    };
}

UnitTestFastGaussianBlur2::UnitTestFastGaussianBlur2()
{
    UTInformation("Mathematics/ImageProcessing/FastGaussianBlur2 [NEEDS UNIT TESTS]");
}

#else

#include <GTL/Mathematics/ImageProcessing/FastGaussianBlur2.h>

namespace gtl
{
    template class FastGaussianBlur2<std::int16_t>;
    template class FastGaussianBlur2<std::int32_t>;
    template class FastGaussianBlur2<float>;
    template class FastGaussianBlur2<double>;
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(FastGaussianBlur2)
