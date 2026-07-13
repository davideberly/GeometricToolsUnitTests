#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/ImageProcessing/GradientAnisotropic3.h>
using namespace gtl;

namespace gtl
{
    class UnitTestGradientAnisotropic3
    {
    public:
        UnitTestGradientAnisotropic3();
    };
}

UnitTestGradientAnisotropic3::UnitTestGradientAnisotropic3()
{
    UTInformation("Mathematics/ImageProcessing/GradientAnisotropic3 [NEEDS UNIT TESTS]");
}

#else

#include <GTL/Mathematics/ImageProcessing/GradientAnisotropic3.h>

namespace gtl
{
    template class GradientAnisotropic3<float>;
    template class GradientAnisotropic3<double>;
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(GradientAnisotropic3)
