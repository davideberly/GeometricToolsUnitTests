#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/ImageProcessing/Morphology.h>
using namespace gtl;

namespace gtl
{
    class UnitTestMorphology
    {
    public:
        UnitTestMorphology();
    };
}

UnitTestMorphology::UnitTestMorphology()
{
    UTInformation("Mathematics/ImageProcessing/Morphology [NEEDS UNIT TESTS]");
}

#else

#include <GTL/Mathematics/ImageProcessing/Morphology.h>

namespace gtl
{
    template class Morphology<std::int32_t>;
    template class Morphology<std::int64_t>;
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(Morphology)
