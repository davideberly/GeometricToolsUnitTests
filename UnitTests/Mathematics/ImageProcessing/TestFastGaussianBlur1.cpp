#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/ImageProcessing/FastGaussianBlur1.h>
using namespace gtl;

namespace gtl
{
    class UnitTestFastGaussianBlur1
    {
    public:
        UnitTestFastGaussianBlur1();
    };
}

UnitTestFastGaussianBlur1::UnitTestFastGaussianBlur1()
{
    UTInformation("Mathematics/ImageProcessing/FastGaussianBlur1 [NEEDS UNIT TESTS]");
}

#else

#include <GTL/Mathematics/ImageProcessing/FastGaussianBlur1.h>

namespace gtl
{
    template class FastGaussianBlur1<std::int16_t>;
    template class FastGaussianBlur1<std::int32_t>;
    template class FastGaussianBlur1<float>;
    template class FastGaussianBlur1<double>;
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(FastGaussianBlur1)
