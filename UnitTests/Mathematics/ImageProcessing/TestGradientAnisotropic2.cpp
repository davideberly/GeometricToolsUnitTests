#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/ImageProcessing/GradientAnisotropic2.h>
using namespace gtl;

namespace gtl
{
    class UnitTestGradientAnisotropic2
    {
    public:
        UnitTestGradientAnisotropic2();
    };
}

UnitTestGradientAnisotropic2::UnitTestGradientAnisotropic2()
{
    UTInformation("Mathematics/ImageProcessing/GradientAnisotropic2 [NEEDS UNIT TESTS]");
}

#else

#include <GTL/Mathematics/ImageProcessing/GradientAnisotropic2.h>

namespace gtl
{
    template class GradientAnisotropic2<float>;
    template class GradientAnisotropic2<double>;
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(GradientAnisotropic2)
