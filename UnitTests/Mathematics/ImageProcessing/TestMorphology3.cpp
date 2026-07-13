#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/ImageProcessing/Morphology3.h>
using namespace gtl;

namespace gtl
{
    class UnitTestMorphology3
    {
    public:
        UnitTestMorphology3();
    };
}

UnitTestMorphology3::UnitTestMorphology3()
{
    UTInformation("Mathematics/ImageProcessing/Morphology3 [NEEDS UNIT TESTS]");
}

#else

#include <GTL/Mathematics/ImageProcessing/Morphology3.h>

namespace gtl
{
    template class Morphology3<std::int32_t>;
    template class Morphology3<std::int64_t>;
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(Morphology3)
