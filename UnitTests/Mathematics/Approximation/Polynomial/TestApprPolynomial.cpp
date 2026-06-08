#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Approximation/Polynomial/ApprPolynomial.h>
#include <GTL/Mathematics/Approximation/Polynomial/ApprPolynomial1.h>
#include <array>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace gtl;

namespace gtl
{
    class UnitTestApprPolynomial
    {
    public:
        UnitTestApprPolynomial();

    private:
        using Approximator1 = ApprPolynomial<double, 1>;
        using Approximator2 = ApprPolynomial<double, 2>;
        using Approximator3 = ApprPolynomial<double, 3>;

        void TestUnconstrained1() const;
        void TestConstrained1() const;
        void TestSameDegreeUnconstrained2() const;
        void TestSameDegreeConstrained2() const;
        void TestDifferentDegreesUnconstrained2() const;
        void TestDifferentDegreesUnconstrained3() const;
    };
}

UnitTestApprPolynomial::UnitTestApprPolynomial()
{
    UTInformation("Mathematics/Approximation/Polynomial/ApprPolynomial");

    TestUnconstrained1();
    TestConstrained1();
    TestSameDegreeUnconstrained2();
    TestSameDegreeConstrained2();
    TestDifferentDegreesUnconstrained2();
    TestDifferentDegreesUnconstrained3();
}

void UnitTestApprPolynomial::TestUnconstrained1() const
{
    std::vector<std::array<double, 2>> observations(1024);
    std::ifstream inFile("Mathematics/Approximation/2D/Input/RandomUnitPoints2D_Double_1024.binary", std::ios::binary);
    UTAssert(inFile, "Failed to open input file.");
    inFile.read((char*)observations.data(), observations.size() * sizeof(observations[0]));
    inFile.close();

    Approximator1 approximator{};
    std::vector<Approximator1::Multiindex> multiindices = { { 0 }, { 1 }, { 2 }, { 3} };
    std::vector<double> polynomial{};
    bool success = approximator.Fit(multiindices, observations, polynomial);
    UTAssert(success, "The fit failed.");
    // {1, x, x^2, x^3}
    // {2.3417976564982710, -0.76376353669192087, 0.033299763850360264, -0.0011838348907506485}

    // From Mathematica's "Fit" function
    // basis = 
    // Fit[SetPrecision[points, 17], basis, {x}]
    std::vector<double> expectedPolynomial
        // {1, x, x^2, x^3}
    {
       2.341797656498281, -0.7637635366919154, 0.03329976385035867, -0.001183834890750745
    };

    // {1, x, x^2, x^3}
    // {-1.0214051826551440e-14, -5.4400928206632670e-15, 1.5959455978986625e-15, 9.6493993351209895e-17}
    std::array<double, 4> diff{};
    double constexpr maxError = 1.0e-13;
    double error{};
    for (std::size_t i = 0; i <= 3; ++i)
    {
        diff[i] = polynomial[i] - expectedPolynomial[i];
        error = std::fabs(diff[i]);
        UTAssert(error <= maxError, "Inaccurate result diff[" + std::to_string(i) + "].");;
    }

    std::array<double, 1> x = { 1.2345 };
    double w = approximator.Evaluate(x, polynomial); // 1.4474528592173359
    double expectedW = 1.4474528592173503;
    error = std::fabs(w - expectedW);
    UTAssert(error <= maxError, "The w-value is incorrect.");
}

void UnitTestApprPolynomial::TestConstrained1() const
{
    std::vector<std::array<double, 2>> observations(1024);
    std::ifstream inFile("Mathematics/Approximation/2D/Input/RandomUnitPoints2D_Double_1024.binary", std::ios::binary);
    UTAssert(inFile, "Failed to open input file.");
    inFile.read((char*)observations.data(), observations.size() * sizeof(observations[0]));
    inFile.close();

    Approximator1 approximator{};
    std::vector<Approximator1::Multiindex> multiindices = { { 0 }, { 2 }, { 3} };
    std::vector<double> polynomial{};
    bool success = approximator.Fit(multiindices, observations, polynomial);
    UTAssert(success, "The fit failed.");
    // {1, x^2, x^3}
    // {1.9455614180092728, 0.17171907237508721, -0.068141989547314943}

    // From Mathematica's "Fit" function
    // basis = 
    // Fit[SetPrecision[points, 17], basis, {x}]
    std::vector<double> expectedPolynomial
        // {1, x^2, x^3}
    {
       1.945561418009249, 0.1717190723750920, -0.06814198954731575
    };

    // {1, x, x^2, x^3}
    // {2.3758772726978350e-14, -4.8017145815038020e-15, 8.0491169285323849e-16}
    std::array<double, 3> diff{};
    double constexpr maxError = 1.0e-13;
    double error{};
    for (std::size_t i = 0; i <= 2; ++i)
    {
        diff[i] = polynomial[i] - expectedPolynomial[i];
        error = std::fabs(diff[i]);
        UTAssert(error <= maxError, "Inaccurate result diff[" + std::to_string(i) + "].");;
    }

    std::array<double, 1> x = { 1.2345 };
    double w = approximator.Evaluate(x, polynomial); // 2.0790595902199414
    double expectedW = 2.079059590219923;
    error = std::fabs(w - expectedW);
    UTAssert(error <= maxError, "The w-value is incorrect.");
}

void UnitTestApprPolynomial::TestSameDegreeUnconstrained2() const
{
    std::vector<std::array<double, 3>> observations(1024);
    std::ifstream inFile("Mathematics/Approximation/3D/Input/RandomUnitPoints3D_Double_1024.binary", std::ios::binary);
    UTAssert(inFile, "Failed to open input file.");
    inFile.read((char*)observations.data(), observations.size() * sizeof(observations[0]));
    inFile.close();

    Approximator2 approximator{};
    std::vector<Approximator2::Multiindex> multiindices
    {
        { 0, 0},
        { 1, 0 },
        { 2, 0 },
        { 3, 0},
        { 0, 1},
        { 1, 1 },
        { 2, 1 },
        { 3, 1 },
        { 0, 2 },
        { 1, 2 },
        { 2, 2 },
        { 3, 2 },
        { 0, 3 },
        { 1, 3 },
        { 2, 3 },
        { 3, 3 }
    };
    std::vector<double> polynomial{};
    bool success = approximator.Fit(multiindices, observations, polynomial);
    UTAssert(success, "The fit failed.");
    // {1, x, x^2, x^3}
    // {-0.036601514495418090, -0.12361712153192495,  0.081462419748683845,  0.14008828149729002},
    // {y, x*y, x^2*y, x^3*y}
    // { 0.010262828175322753,  0.0099693797919493399, -0.057945503187400299,  0.0025206172798700188},
    // {y^2, x*y^2, x^2*y^2, x^3*y^2}
    // { 0.029618145735493116,  0.44562481699161904,  0.041707525455515426, -0.54896975671798875},
    // {y^3, x*y^3, x^2*y^3, x^3*y^3}
    // {-0.061908945779295579, -0.53463769359038349,  0.20710318626177274,  0.53964776715795004}

    // From Mathematica's "Fit" function
    // basis = {1, x, x^2, x^3, y, x*y, x^2*y, x^3*y, y^2, x*y^2, x^2*y^2, x^3*y^2, y^3, x*y^3, x^2*y^3, x^3*y^3}.
    // Fit[SetPrecision[points, 17], basis, {x,y}]
    std::array<double, 16> expectedPolynomial
    {
        // {1, x, x^2, x^3}
        -0.03660151449541826, -0.1236171215319260,  0.0814624197486839,  0.1400882814972917,
        // y, x*y, x^2*y, x^3*y
         0.01026282817532139,  0.00996937979196267, -0.0579455031873976,  0.002520617279851919,
        // y^2, x*y^2, x^2*y^2, x^3*y^2
         0.02961814573549374,  0.4456248169916172,  0.04170752545551480, -0.5489697567179863,
        // y^3, x*y^3, x^2*y^3, x^3*y^3
        -0.0619089457792936, -0.5346376935904063,  0.2071031862617692,  0.5396477671579816
    };

    // {1, x, x^2, x^3}
    // { 1.9428902930940239e-16,  1.8596235662471372e-15, -1.5265566588595902e-16, -2.8588242884097781e-15}
    // {y, x*y, x^2*y, x^3*y}
    // { 1.2368578383714635e-15, -1.3662682096793333e-14, -2.5535129566378600e-15,  1.9320916394560683e-14}
    // {y^2, x*y^2, x^2*y^2, x^3*y^2}
    // {-6.9735883734267645e-16, -4.4408920985006262e-16, 8.0491169285323849e-16,  8.8817841970012523e-16}
    // {y^3, x*y^3, x^2*y^3, x^3*y^3}
    // {-1.7486012637846216e-15,  2.2870594307278225e-14,  3.2751579226442118e-15, -3.2640556923979602e-14}
    std::array<double, 16> diff{};
    double constexpr maxError = 1.0e-13;
    double error{};
    for (std::size_t i = 0; i < 16; ++i)
    {
        diff[i] = polynomial[i] - expectedPolynomial[i];
        error = std::fabs(diff[i]);
        UTAssert(error <= maxError, "Inaccurate result diff[" + std::to_string(i) + "][");
    }

    std::array<double, 2> x = { 1.2345, 0.6789 };
    double w = approximator.Evaluate(x, polynomial); // 0.16811604808716019
    double expectedW = 0.16811604808716138;
    error = std::fabs(w - expectedW);
    UTAssert(error <= maxError, "The w-value is incorrect.");
}

void UnitTestApprPolynomial::TestSameDegreeConstrained2() const
{
    std::vector<std::array<double, 3>> observations(1024);
    std::ifstream inFile("Mathematics/Approximation/3D/Input/RandomUnitPoints3D_Double_1024.binary", std::ios::binary);
    UTAssert(inFile, "Failed to open input file.");
    inFile.read((char*)observations.data(), observations.size() * sizeof(observations[0]));
    inFile.close();

    Approximator2 approximator{};
    std::vector<Approximator2::Multiindex> multiindices
    {
        { 0, 0},
        { 1, 0 },
        { 3, 0 },
        { 0, 1},
        { 1, 1 },
        { 3, 1 },
        { 0, 3 },
        { 1, 3 },
        { 3, 3 }
    };
    std::vector<double> polynomial{};
    bool success = approximator.Fit(multiindices, observations, polynomial);
    UTAssert(success, "The fit failed.");
    // {1, x, x^3}
    // {0.0078782442858890880, 0.022805270698155942, -0.033629773121739127},
    // {y, x*y, x^3*y}
    // { -0.013901843820662490, -0.021282460316844443, 0.037382899588547291},
    // {y^3, x*y^3, x^3*y^3}
    // {0.030234170997721070, -0.45058345382026510, 0.46046924856684768}

    // From Mathematica's "Fit" function
    // basis = {1, x, x^2, x^3, y, x*y, x^2*y, x^3*y, y^2, x*y^2, x^2*y^2, x^3*y^2, y^3, x*y^3, x^2*y^3, x^3*y^3}.
    // Fit[SetPrecision[points, 17], basis, {x,y}]
    std::array<double, 9> expectedPolynomial
    {
        // {1, x, x^3}
        0.00787824428588910, 0.02280527069815665, -0.03362977312174004,
        // y, x*y, x^3*y
        -0.01390184382066255,  -0.02128246031682090, 0.03738289958851498,
          // y^3, x*y^3, x^3*y^3
        0.03023417099772135, -0.4505834538203005, 0.4604692485668965
    };

    // {1, x, x^3}
    // { 1.9428902930940239e-16,  1.8596235662471372e-15, -1.5265566588595902e-16}
    // {y, x*y, x^3*y}
    // { 1.2368578383714635e-15, -1.3662682096793333e-14, -2.5535129566378600e-15}
    // {y^3, x*y^3, x^3*y^3}
    // {-1.7486012637846216e-15,  2.2870594307278225e-14,  3.2751579226442118e-15}
    std::array<double, 9> diff{};
    double constexpr maxError = 1.0e-13;
    double error{};
    for (std::size_t i = 0; i < 9; ++i)
    {
        diff[i] = polynomial[i] - expectedPolynomial[i];
        error = std::fabs(diff[i]);
        UTAssert(error <= maxError, "Inaccurate result diff[" + std::to_string(i) + "][");
    }

    std::array<double, 2> x = { 1.2345, 0.6789 };
    double w = approximator.Evaluate(x, polynomial); // 0.099717063285001961
    double expectedW = 0.09971706328499472;
    error = std::fabs(w - expectedW);
    UTAssert(error <= maxError, "The w-value is incorrect.");
}

void UnitTestApprPolynomial::TestDifferentDegreesUnconstrained2() const
{
    std::vector<std::array<double, 3>> observations(1024);
    std::ifstream inFile("Mathematics/Approximation/3D/Input/RandomUnitPoints3D_Double_1024.binary", std::ios::binary);
    UTAssert(inFile, "Failed to open input file.");
    inFile.read((char*)observations.data(), observations.size() * sizeof(observations[0]));
    inFile.close();

    Approximator2 approximator{};
    std::vector<Approximator2::Multiindex> multiindices
    {
        { 0, 0},
        { 1, 0 },
        { 2, 0 },
        { 3, 0},
        { 0, 1 },
        { 1, 1 },
        { 2, 1 },
        { 3, 1 }
    };
    std::vector<double> polynomial{};
    bool success = approximator.Fit(multiindices, observations, polynomial);
    UTAssert(success, "The fit failed.");
    // {1, x, x^2, x^3}
    // {-0.027108499479626003, 0.020124308366052703, 0.095671538383850022, -0.032941084969050891}
    // {y, x*y, x^2*y, x^3*y}
    // {-0.023285091002198006, -0.28264297391735688, 0.066689188592509857, 0.28836057459675252}

    // From Mathematica's "Fit" function
    // basis = {1, x, x^2, x^3, y, x*y, x^2*y, x^3*y, y^2}.
    // Fit[SetPrecision[points, 17], basis, {x,y}]
    std::array<double, 8> expectedPolynomial
    {
        // {1, x, x^2, x^3}
        -0.02710849947962588, 0.02012430836605320, 0.0956715383838497, -0.03294108496905159,
        // {y, x*y, x^2*y, x^3*y}
        -0.02328509100219802, -0.2826429739173540, 0.06668918859251004, 0.2883605745967482
    };

    std::array<double, 8> diff{};
    double constexpr maxError = 1.0e-13;
    double error{};
    for (std::size_t i = 0; i < 8; ++i)
    {
        diff[i] = polynomial[i] - expectedPolynomial[i];
        error = std::fabs(diff[i]);
        UTAssert(error <= maxError, "Inaccurate result diff[" + std::to_string(i) + "][");
    }

    std::array<double, 2> x = { 1.2345, 0.6789 };
    double w = approximator.Evaluate(x, polynomial); // 0.26618165227992518
    double expectedW = 0.26618165227992135;
    error = std::fabs(w - expectedW);
    UTAssert(error <= maxError, "The w-value is incorrect.");
}

void UnitTestApprPolynomial::TestDifferentDegreesUnconstrained3() const
{
    std::vector<std::array<double, 4>> observations(1024);
    std::ifstream inFile("Mathematics/Approximation/ND/Input/RandomUnitPoints4D_Double_1024.binary", std::ios::binary);
    UTAssert(inFile, "Failed to open input file.");
    inFile.read((char*)observations.data(), observations.size() * sizeof(observations[0]));
    inFile.close();

    Approximator3 approximator{};
    std::vector<Approximator3::Multiindex> multiindices
    {
        { 0, 0, 0},
        { 1, 0, 0 },
        { 2, 0, 0 },
        { 3, 0, 0 },
        { 0, 1, 0 },
        { 1, 1, 0 },
        { 2, 1, 0 },
        { 3, 1, 0 },
        { 0, 2, 0 },
        { 1, 2, 0 },
        { 2, 2, 0 },
        { 3, 2, 0 },
        { 0, 0, 1 },
        { 1, 0, 1 },
        { 2, 0, 1 },
        { 3, 0, 1 },
        { 0, 1, 1 },
        { 1, 1, 1 },
        { 2, 1, 1 },
        { 3, 1, 1 },
        { 0, 2, 1 },
        { 1, 2, 1 },
        { 2, 2, 1 },
        { 3, 2, 1 }
    };
    std::vector<double> polynomial{};
    bool success = approximator.Fit(multiindices, observations, polynomial);
    UTAssert(success, "The fit failed.");
    //   {1, x, x^2, x^3}
    //   {-0.014284589238581625, -0.26965168367314157, 0.017179112803374169, 0.26714751715803525	}
    //   {y, y*x y*x^2, y*x^3}
    //   {-0.017659624992758007, 0.025837391113287610, -0.069583432491744743, 0.055370744899336015}
    //   {y^2, y^2*x, y^2*x^2, y^2*x^3}
    //   {0.070144835749038584, 0.64024994614447628	, -0.16968056818489405, -0.58151760455371326}
    //   {z, z*x, z*x^2, z*x^3}
    //   {-0.039457187852054453, 0.11086782757404583, 0.16763135888250996, 0.053119980975631087}
    //   {z*y, z*y*x, z*y*x^2, z*y*x^3}
    //   {-0.13990048083846307, -0.14700160470157722, 0.35066334044067571, 0.11027116248641525}
    //   {z*y^2, z*y^2*x, z*y^2*x^2, z*y^2*x^3}
    //   {-0.0079261803145766665, -0.28109860505322626, 0.13176597647613805, -0.011491032406310421}

    // From Mathematica's "Fit" function. basis =
    //   {1, x, x^2, x^3,
    //    y, y*x y*x^2, y*x^3,
    //    y^2, y^2*x, y^2*x^2, y^2*x^3, 
    //    z, z*x, z*x^2, z*x^3,
    //    z*y, z*y*x, z*y*x^2, z*y*x^3,
    //    z*y^2, z*y^2*x, z*y^2*x^2, z*y^2*x^3}
    // Fit[SetPrecision[points, 17], basis, {x,y}, WorkingPrecision -> 64]
    std::vector<double> expectedPolynomial
    {
        // {1, x, x^2, x^3}
        -0.014284589238581833, -0.26965168367313349, 0.017179112803375081, 0.26714751715802264,
        // {y, y*x y*x^2, y*x^3}
        -0.017659624992757659, 0.025837391113289479, -0.06958343249174566, 0.05537074489933345,
        // {y^2, y^2*x, y^2*x^2, y^2*x^3}
        0.07014483574903946 , 0.6402499461444537, -0.16968056818489662, -0.5815176045536783,
        // {z, z*x, z*x^2, z*x^3}
        -0.03945718785205475, 0.11086782757404236 , 0.16763135888251034, 0.05311998097563626,
        // {z*y, z*y*x, z*y*x^2, z*y*x^3}
        -0.13990048083846388, -0.14700160470157331 , 0.3506633404406768, 0.11027116248640820,
        // {z*y^2, z*y^2*x, z*y^2*x^2, z*y^2*x^3}
        -0.007926180314575905 , -0.28109860505322219, 0.13176597647613738 , -0.011491032406316581
    };

    //Polynomial<double, 3> diff = polynomial - expectedPolynomial;
    // {1, x, x^2, x^3} [diff.mCoefficient[0].mCoefficient[0].mCoefficient[0..3]]
    // {2.3765711620882257e-16, -7.3829831137572910e-15, -9.4022012397942945e-16, 1.1435297153639112e-14}
    // {y, y*x y*x^2, y*x^3} [diff.mCoefficient[0].mCoefficient[1].mCoefficient[0..3]]
    // {-3.0531133177191805e-16, -1.9741153156616065e-15, 7.6327832942979512e-16, 2.7131075164277263e-15}
    // {y^2, y^2*x, y^2*x^2, y^2*x^3} [diff.mCoefficient[0].mCoefficient[2].mCoefficient[0..3]]
    // {-9.5756735873919752e-16, 2.0539125955565396e-14, 2.7478019859472624e-15, -3.1641356201816961e-14}
    // {z, z*x, z*x^2, z*x^3} [diff.mCoefficient[1].mCoefficient[0].mCoefficient[0..3]]
    // {6.9388939039072284e-17, 2.9698465908722937e-15, 1.1102230246251565e-16, -4.2882364326146671e-15}
    // {z*y, z*y*x, z*y*x^2, z*y*x^3} [diff.mCoefficient[1].mCoefficient[1].mCoefficient[0..3]]
    // {8.8817841970012523e-16, -3.5527136788005009e-15, -1.3877787807814457e-15, 6.3143934525555778e-15}
    // {z*y^2, z*y^2*x, z*y^2*x^2, z*y^2*x^3} [diff.mCoefficient[1].mCoefficient[2].mCoefficient[0..3]]
    // {-2.0990154059319366e-16, -3.2751579226442118e-15, -3.8857805861880479e-16, 4.8763076909708047e-15}
    std::array<double, 24> diff{};
    double constexpr maxError = 1.0e-13;
    double error{};
    for (std::size_t i = 0; i < 24; ++i)
    {
        diff[i] = polynomial[i] - expectedPolynomial[i];
        error = std::fabs(diff[i]);
        UTAssert(error <= maxError, "Inaccurate result diff[" + std::to_string(i) + "][");
    }

    std::array<double, 3> x = { 1.2345, 0.6789, 0.5 };
    double w = approximator.Evaluate(x, polynomial); // 0.29183616558947112
    double expectedW = 0.291836165589471;
    error = std::fabs(w - expectedW);
    UTAssert(error <= maxError, "The w-value is incorrect.");
}

#if 0
void UnitTestApprPolynomial::Test()
{
    std::vector<std::array<double, 4>> observations(1024);
    std::ifstream inFile("Mathematics/Approximation/ND/Input/RandomUnitPoints4D_Double_1024.binary", std::ios::binary);
    UTAssert(inFile, "Failed to open input file.");
    inFile.read((char*)observations.data(), observations.size() * sizeof(observations[0]));
    inFile.close();

#if defined(INTERNAL_GENERATE_DATA)
    std::ofstream outFile("Mathematics/Approximation/Polynomial/Input/ApprPolynomialInput.txt");
    for (auto const& p : observations)
    {
        outFile << std::setprecision(17) << p[0] << "," << p[1] << "," << p[2] << "," << p[3] << std::endl;
    }
    outFile.close();
#endif

    std::vector<Approximator::Multiindex> powers(24);
    powers[0] = { 0, 0, 0 };
    powers[1] = { 1, 0, 0 };
    powers[2] = { 2, 0, 0 };
    powers[3] = { 3, 0, 0 };
    powers[4] = { 0, 1, 0 };
    powers[5] = { 1, 1, 0 };
    powers[6] = { 2, 1, 0 };
    powers[7] = { 3, 1, 0 };
    powers[8] = { 0, 2, 0 };
    powers[9] = { 1, 2, 0 };
    powers[10] = { 2, 2, 0 };
    powers[11] = { 3, 2, 0 };
    powers[12] = { 0, 0, 1 };
    powers[13] = { 1, 0, 1 };
    powers[14] = { 2, 0, 1 };
    powers[15] = { 3, 0, 1 };
    powers[16] = { 0, 1, 1 };
    powers[17] = { 1, 1, 1 };
    powers[18] = { 2, 1, 1 };
    powers[19] = { 3, 1, 1 };
    powers[20] = { 0, 2, 1 };
    powers[21] = { 1, 2, 1 };
    powers[22] = { 2, 2, 1 };
    powers[23] = { 3, 2, 1 };
    Vector<double> polynomial{};
    bool success = Approximator::Fit(powers, observations, true, polynomial);
    UTAssert(success, "The fit failed.");
    // coefficients of polynomial
    //   {1, x, x^2, x^3} [polynomial.mCoefficient[0].mCoefficient[0].mCoefficient[0..3]]
    //   {-0.014284589238581596, -0.26965168367314085, 0.017179112803374141, 0.26714751715803409}
    //   {y, y*x y*x^2, y*x^3} [polynomial.mCoefficient[0].mCoefficient[1].mCoefficient[0..3]]
    //   {-0.017659624992757965, 0.025837391113287506, -0.069583432491744895, 0.055370744899336161}
    //   {y^2, y^2*x, y^2*x^2, y^2*x^3} [polynomial.mCoefficient[0].mCoefficient[2].mCoefficient[0..3]]
    //   {0.070144835749038500, 0.64024994614447428, -0.16968056818489388, -0.58151760455370993}
    //   {z, z*x, z*x^2, z*x^3} [polynomial.mCoefficient[1].mCoefficient[0].mCoefficient[0..3]]
    //   {-0.039457187852054681, 0.11086782757404533, 0.16763135888251046, 0.053119980975631975}
    //   {z*y, z*y*x, z*y*x^2, z*y*x^3} [polynomial.mCoefficient[1].mCoefficient[1].mCoefficient[0..3]]
    //   {-0.13990048083846299, -0.14700160470157686, 0.35066334044067543, 0.11027116248641451}
    //   {z*y^2, z*y^2*x, z*y^2*x^2, z*y^2*x^3} [polynomial.mCoefficient[1].mCoefficient[2].mCoefficient[0..3]]
    //   {-0.0079261803145761148, -0.28109860505322548, 0.13176597647613700, -0.011491032406311705}

#if 0
    // From Mathematica's "Fit" function
    // basis = {1, x, x^2, x^3, y, y*x y*x^2, y*x^3, y^2, y^2*x, y^2*x^2, y^2*x^3, 
    //     z, z*x, z*x^2, z*x^3, z*y, z*y*x, z*y*x^2, z*y*x^3, z*y^2, z*y^2*x, z*y^2*x^2, z*y^2*x^3}
    // Fit[SetPrecision[points, 17], basis, {x,y}, WorkingPrecision -> 64]
    ApprPolynomial<double, 3>::Polynomial expectedPolynomial
    {
        {{-0.014284589238581833, -0.26965168367313349, 0.017179112803375081, 0.26714751715802264},
        {-0.017659624992757659, 0.025837391113289479, -0.06958343249174566, 0.05537074489933345},
        { 0.07014483574903946, 0.6402499461444537, -0.16968056818489662, -0.5815176045536783}},
        {{-0.03945718785205475, 0.11086782757404236, 0.16763135888251034, 0.05311998097563626},
        {-0.13990048083846388, -0.14700160470157331, 0.3506633404406768, 0.11027116248640820},
        {-0.007926180314575905, -0.28109860505322219, 0.13176597647613738, -0.011491032406316581}}
    };

    Polynomial<double, 3> diff = polynomial - expectedPolynomial;
    // coefficients of diff
    //   {2.3765711620882257e-16, -7.3829831137572910e-15, -9.4022012397942945e-16, 1.1435297153639112e-14}
    //   {-3.0531133177191805e-16, -1.9741153156616065e-15, 7.6327832942979512e-16, 2.7131075164277263e-15}
    //   {-9.5756735873919752e-16, 2.0539125955565396e-14, 2.7478019859472624e-15, -3.1641356201816961e-14}
    //   {6.9388939039072284e-17, 2.9698465908722937e-15, 1.1102230246251565e-16, -4.2882364326146671e-15}
    //   {8.8817841970012523e-16, -3.5527136788005009e-15, -1.3877787807814457e-15, 6.3143934525555778e-15}
    //   {-2.0990154059319366e-16, -3.2751579226442118e-15, -3.8857805861880479e-16, 4.8763076909708047e-15}
    double constexpr maxError = 1.0e-13;
    double error{};
    for (std::size_t s = 0; s <= zDegree; ++s)
    {
        for (std::size_t r = 0; r <= yDegree; ++r)
        {
            for (std::size_t c = 0; c <= xDegree; ++c)
            {
                error = std::fabs(diff[s][r][c]);
                UTAssert(error <= maxError, "Inaccurate result diff[" + std::to_string(s)
                    + "][" + std::to_string(r) + "][" + std::to_string(c) + "]");
            }
        }
    }

    std::array<double, 2> expectedXExtreme{ -0.99651681129409786, 0.99988315531559957 };
    std::array<double, 2> expectedYExtreme{ -0.99606591039127690, 0.99972259312224510 };
    std::array<double, 2> expectedZExtreme{ -0.99997571560185605, 0.99608215171706327 };
    std::array<double, 2> expectedWExtreme{ -0.99874379726483786, 0.99838581631689394 };

    for (std::size_t i = 0; i < 2; ++i)
    {
        error = std::fabs(xExtreme[i] - expectedXExtreme[i]);
        UTAssert(error <= maxError, "The x-extreme value is incorrect.");
        error = std::fabs(yExtreme[i] - expectedYExtreme[i]);
        UTAssert(error <= maxError, "The y-extreme value is incorrect.");
        error = std::fabs(zExtreme[i] - expectedZExtreme[i]);
        UTAssert(error <= maxError, "The z-extreme value is incorrect.");
        error = std::fabs(wExtreme[i] - expectedWExtreme[i]);
        UTAssert(error <= maxError, "The w-extreme value is incorrect.");
    }

    std::array<double, 3> x = { 0.0, 0.0, 0.0 };
    double w = polynomial(x.data());
    double expectedW = -0.014284589238581596;
    error = std::fabs(w - expectedW);
    UTAssert(error <= maxError, "The w-value is incorrect.");
#endif
}
#endif

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Approximation/Polynomial/ApprPolynomial.h>

namespace gtl
{
    template class ApprPolynomial<float, 2>;
    template class ApprPolynomial<double, 3>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class ApprPolynomial<Rational, 4>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(ApprPolynomial)
