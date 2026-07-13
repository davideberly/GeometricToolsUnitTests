#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/ImageProcessing/Morphology2.h>
using namespace gtl;

namespace gtl
{
    class UnitTestMorphology2
    {
    public:
        UnitTestMorphology2();
    };
}

UnitTestMorphology2::UnitTestMorphology2()
{
    UTInformation("Mathematics/ImageProcessing/Morphology2 [NEEDS UNIT TESTS]");
}

#else

#include <GTL/Mathematics/ImageProcessing/Morphology2.h>

namespace gtl
{
    template class Morphology2<std::int32_t>;
    template class Morphology2<std::int64_t>;
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(Morphology2)
