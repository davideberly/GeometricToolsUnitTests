#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Geometry/3D/BVTree.h>
#include <GTL/Mathematics/Geometry/3D/AlignedBoxBV.h>
#include <GTL/Mathematics/Geometry/3D/OrientedBoxBV.h>
using namespace gtl;

namespace gtl
{
    class UnitTestBVTree
    {
    public:
        UnitTestBVTree();

    private:
    };
}

UnitTestBVTree::UnitTestBVTree()
{
    UTInformation("Mathematics/Geometry/3D/BVTree [NEEDS UNIT TESTING]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Geometry/3D/BVTree.h>
#include <GTL/Mathematics/Geometry/3D/AlignedBoxBV.h>
#include <GTL/Mathematics/Geometry/3D/OrientedBoxBV.h>

namespace gtl
{
    template class BVTree<float, AlignedBoxBV<float>>;
    template class BVTree<double, OrientedBoxBV<double>>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class BVTree<Rational, AlignedBoxBV<Rational>>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(BVTree)
