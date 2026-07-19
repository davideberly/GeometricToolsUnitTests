#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Meshes/VertexCollapseMesh.h>
#include <map>
#include <set>
#include <string>
using namespace gtl;

namespace gtl
{
    class UnitTestVertexCollapseMesh
    {
    public:
        UnitTestVertexCollapseMesh();

    private:
    };
}

UnitTestVertexCollapseMesh::UnitTestVertexCollapseMesh()
{
    UTInformation("Mathematics/Meshes/VertexCollapseMesh");
}

#else

#include <GTL/Mathematics/Meshes/VertexCollapseMesh.h>

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(VertexCollapseMesh)
