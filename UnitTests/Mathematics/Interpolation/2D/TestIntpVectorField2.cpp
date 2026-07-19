#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Interpolation/2D/IntpVectorField2.h>
#include <fstream>
using namespace gtl;

namespace gtl
{
    class UnitTestIntpVectorField2
    {
    public:
        UnitTestIntpVectorField2();
    };
}

UnitTestIntpVectorField2::UnitTestIntpVectorField2()
{
    UTInformation("Mathematics/Interpolation/2D/IntpVectorField2 [tested by GTL/VisualTests/Mathematics/Interpolation/Interpolation2D]");
}

#else

#include <GTL/Mathematics/Interpolation/2D/IntpVectorField2.h>

namespace gtl
{
    template class IntpVectorField2<float>;
    template class IntpVectorField2<double>;
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(IntpVectorField2)
