#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Approximation/Polynomial/ApprPolynomial2.h>
#include <fstream>
using namespace gtl;

//#define INTERNAL_GENERATE_DATA

namespace gtl
{
    class UnitTestApprPolynomial2
    {
    public:
        UnitTestApprPolynomial2();

    private:
        void TestSameDegree();
        void TestDifferentDegrees();
    };
}

UnitTestApprPolynomial2::UnitTestApprPolynomial2()
{
    UTInformation("Mathematics/Approximation/Polynomial/ApprPolynomial2");

    TestSameDegree();
    TestDifferentDegrees();
}

void UnitTestApprPolynomial2::TestSameDegree()
{
    std::vector<std::array<double, 3>> observations(1024);
    std::ifstream inFile("Mathematics/Approximation/3D/Input/RandomUnitPoints3D_Double_1024.binary", std::ios::binary);
    UTAssert(inFile, "Failed to open input file.");
    inFile.read((char*)observations.data(), observations.size() * sizeof(observations[0]));
    inFile.close();
#if defined(INTERNAL_GENERATE_DATA)
    std::ofstream outFile("Mathematics/Approximation/Polynomial/Input/ApprPolynomial2Input.txt");
    for (auto const& p : observations)
    {
        outFile << std::setprecision(17) << p[0] << "," << p[1] << "," << p[2] << std::endl;
    }
    outFile.close();
#endif

    std::size_t constexpr xDegree = 3, yDegree = 3;
    Polynomial<double, 2> polynomial{};
    bool success = ApprPolynomial2<double>::Fit(xDegree, yDegree, observations, true, polynomial);
    UTAssert(success, "The fit failed.");
    // {1, x, x^2, x^3}
    // {-0.036601514495418062, -0.1236171215319241400,  0.081462419748683748,  0.1400882814972888300},
    // {y, x*y, x^2*y, x^3*y}
    // { 0.010262828175322626,  0.0099693797919490068, -0.057945503187400153,  0.0025206172798712401},
    // {y^2, x*y^2, x^2*y^2, x^3*y^2}
    // { 0.029618145735493043,  0.4456248169916167700,  0.041707525455515607, -0.5489697567179854200},
    // {y^3, x*y^3, x^2*y^3, x^3*y^3}
    // {-0.061908945779295350, -0.5346376935903833800,  0.207103186261772490,  0.5396477671579489300}

    // From Mathematica's "Fit" function
    // basis = {1, x, x^2, x^3, y, x*y, x^2*y, x^3*y, y^2, x*y^2, x^2*y^2, x^3*y^2, y^3, x*y^3, x^2*y^3, x^3*y^3}.
    // Fit[SetPrecision[points, 17], basis, {x,y}]
    Polynomial<double, 2> expectedPolynomial
    {
        // {1, x, x^2, x^3}
        {-0.03660151449541826, -0.1236171215319260,  0.0814624197486839,  0.1400882814972917},
        // {y, x*y, x^2*y, x^3*y}
        { 0.01026282817532139,  0.00996937979196267, -0.0579455031873976,  0.002520617279851919},
        // {y^2, x*y^2, x^2*y^2, x^3*y^2}
        { 0.02961814573549374,  0.4456248169916172,  0.04170752545551480, -0.5489697567179863},
        // {y^3, x*y^3, x^2*y^3, x^3*y^3}
        {-0.0619089457792936, -0.5346376935904063,  0.2071031862617692,  0.5396477671579816}
    };

    // {1, x, x^2, x^3}
    // { 1.9428902930940239e-16,  1.8596235662471372e-15, -1.5265566588595902e-16, -2.8588242884097781e-15}
    // {y, x*y, x^2*y, x^3*y}
    // { 1.2368578383714635e-15, -1.3662682096793333e-14, -2.5535129566378600e-15,  1.9320916394560683e-14}
    // {y^2, x*y^2, x^2*y^2, x^3*y^2}
    // {-6.9735883734267645e-16, -4.4408920985006262e-16, 8.0491169285323849e-16,  8.8817841970012523e-16}
    // {y^3, x*y^3, x^2*y^3, x^3*y^3}
    // {-1.7486012637846216e-15,  2.2870594307278225e-14,  3.2751579226442118e-15, -3.2640556923979602e-14}
    Polynomial<double, 2> diff = polynomial - expectedPolynomial;
    double constexpr maxError = 1.0e-13;
    double error{};
    for (std::size_t r = 0; r <= yDegree; ++r)
    {
        for (std::size_t c = 0; c <= xDegree; ++c)
        {
            error = std::fabs(diff[r][c]);
            UTAssert(error <= maxError, "Inaccurate result diff[" + std::to_string(r) + "][" + std::to_string(c) + "]");
        }
    }

    std::array<double, 2> x = { 1.2345, 0.6789 };
    double w = polynomial(x.data()); // 0.16811604808716127
    double expectedW = 0.16811604808716138;
    error = std::fabs(w - expectedW);
    UTAssert(error <= maxError, "The w-value is incorrect.");
}

void UnitTestApprPolynomial2::TestDifferentDegrees()
{
    std::vector<std::array<double, 3>> observations(1024);
    std::ifstream inFile("Mathematics/Approximation/3D/Input/RandomUnitPoints3D_Double_1024.binary", std::ios::binary);
    UTAssert(inFile, "Failed to open input file.");
    inFile.read((char*)observations.data(), observations.size() * sizeof(observations[0]));
    inFile.close();
#if defined(INTERNAL_GENERATE_DATA)
    std::ofstream outFile("Mathematics/Approximation/Polynomial/Input/ApprPolynomial2Input.txt");
    for (auto const& p : observations)
    {
        outFile << std::setprecision(17) << p[0] << "," << p[1] << "," << p[2] << std::endl;
    }
    outFile.close();
#endif

    std::size_t constexpr xDegree = 3, yDegree = 1;
    Polynomial<double, 2> polynomial{};
    bool success = ApprPolynomial2<double>::Fit(xDegree, yDegree, observations, true, polynomial);
    UTAssert(success, "The fit failed.");
    //   {1, x, x^2, x^3} [polynomial.mCoefficient[0].mCoefficient[0..3]]
    //   {-0.027108499479626003, 0.020124308366052661, 0.095671538383850022, -0.032941084969050828}
    //   {y, y*x, y*x^2, y*x^3} [polynomial.mCoefficient[1].mCoefficient[0..3]]
    //   {-0.023285091002197961, -0.28264297391735627, 0.066689188592509746, 0.28836057459675163}

    // From Mathematica's "Fit" function
    // basis = {1, x, x^2, x^3, y, y*x, y*x^2, y*x^3}
    // Fit[SetPrecision[points, 17], basis, {x,y}]
    Polynomial<double, 2> expectedPolynomial
    {
        // {1, x, x^2, x^3} [expectedPolynomial.mCoefficient[0].mCoefficient[0..3]]
        {-0.02710849947962588, 0.02012430836605320, 0.0956715383838497, -0.03294108496905159},
        // {y, y*x, y*x^2, y*x^3} [expectedPolynomial.mCoefficient[1].mCoefficient[0..3]]
        {-0.02328509100219802, -0.2826429739173540, 0.06668918859251004, 0.2883605745967482}
    };

    // {1, x, x^2, x^3} [diff.mCoefficient[0].mCoefficient[0..3]]
    // { 2.7755575615628914e-17,  2.9837243786801082e-15, 4.0245584642661925e-16, -2.5660029656648931e-14}
    // {y, y*x, y*x^2, y*x^3} [diff.mCoefficient[1].mCoefficient[0..3]]
    // {-2.4633073358870661e-16, -3.3306690738754696e-15, -6.1062266354383610e-16,  3.7858605139717838e-14}
    Polynomial<double, 2> diff = polynomial - expectedPolynomial;
    double constexpr maxError = 1.0e-13;
    double error{};
    for (std::size_t r = 0; r <= yDegree; ++r)
    {
        for (std::size_t c = 0; c <= xDegree; ++c)
        {
            error = std::fabs(diff[r][c]);
            UTAssert(error <= maxError, "Inaccurate result diff[" + std::to_string(r) + "][" + std::to_string(c) + "]");
        }
    }

    std::array<double, 2> x = { 1.2345, 0.6789 };
    double w = polynomial(x.data()); // 0.26618165227992463
    double expectedW = 0.26618165227992135;
    error = std::fabs(w - expectedW);
    UTAssert(error <= maxError, "The w-value is incorrect.");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Approximation/Polynomial/ApprPolynomial2.h>

namespace gtl
{
    template class ApprPolynomial2<float>;
    template class ApprPolynomial2<double>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class ApprPolynomial2<Rational>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(ApprPolynomial2)
