#include "Quantlab/CSVParser.hpp"
#include "Quantlab/Calculator.hpp"
#include "gtest/gtest.h"


class CalculatorSingleFunctionTests : public ::testing::Test {
public:
	std::vector<quantlab::trade> aaa_trades{ {52924702, "aaa", 13, 1136}, { 52930489,  "aaa", 18, 1222 }, { 52931654,  "aaa", 9,1077 } };
	std::vector<quantlab::trade> aab_trades{ {52925641, "aab", 31, 907}, { 52927350,  "aab", 29, 724 }, { 52933453,  "aab", 9,756 } };
	std::vector<quantlab::trade> aac_trades{ {52924702, "aac", 20, 477}, { 52927783,  "aac", 21, 638} };
};


TEST_F(CalculatorSingleFunctionTests, MaxTimeGapTest)
{
	auto aaa_max_time_gap = quantlab::calculator::calculate_max_time_gap(aaa_trades);
	EXPECT_EQ(aaa_max_time_gap, 5787);

	auto aab_max_time_gap = quantlab::calculator::calculate_max_time_gap(aab_trades);
	EXPECT_EQ(aab_max_time_gap, 6103);

	auto aac_max_time_gap = quantlab::calculator::calculate_max_time_gap(aac_trades);
	EXPECT_EQ(aac_max_time_gap, 3081);
}

TEST_F(CalculatorSingleFunctionTests, TotalVolumeTest)
{
	auto aaa_total_volume = quantlab::calculator::calculate_total_volume(aaa_trades);
	EXPECT_EQ(aaa_total_volume, 40);

	auto aab_total_volume = quantlab::calculator::calculate_total_volume(aab_trades);
	EXPECT_EQ(aab_total_volume, 69);

	auto aac_total_volume = quantlab::calculator::calculate_total_volume(aac_trades);
	EXPECT_EQ(aac_total_volume, 41);
}

TEST_F(CalculatorSingleFunctionTests, WeightedAveragePriceTest)
{
	auto aaa_weighted_average_price = quantlab::calculator::calculate_weighted_average_price(aaa_trades);
	EXPECT_EQ(aaa_weighted_average_price, 1161);

	auto aab_weighted_average_price = quantlab::calculator::calculate_weighted_average_price(aab_trades);
	EXPECT_EQ(aab_weighted_average_price, 810);

	auto aac_weighted_average_price = quantlab::calculator::calculate_weighted_average_price(aac_trades);
	EXPECT_EQ(aac_weighted_average_price, 559);
}

TEST_F(CalculatorSingleFunctionTests, MaxPriceTest)
{
	auto aaa_max_price = quantlab::calculator::calculate_max_trade_price(aaa_trades);
	EXPECT_EQ(aaa_max_price, 1222);

	auto aab_max_price = quantlab::calculator::calculate_max_trade_price(aab_trades);
	EXPECT_EQ(aab_max_price, 907);

	auto aac_max_price = quantlab::calculator::calculate_max_trade_price(aac_trades);
	EXPECT_EQ(aac_max_price, 638);
}

class CalculatorCalculateAllTests : public ::testing::Test {
public:
	CalculatorCalculateAllTests() {
		trade_map = quantlab::csv_parser::parse(input_file);
	}

	std::string input_file = "sample_files/small_input.csv";
	std::map<std::string, std::vector<quantlab::trade>> trade_map;

};

TEST_F(CalculatorCalculateAllTests, CalculateAllTests)
{
	auto result = quantlab::calculator::calculate_all(trade_map);
	EXPECT_EQ(result.size(), 3);

	EXPECT_EQ(result.at("aaa").max_time_gap, 5787);
	EXPECT_EQ(result.at("aaa").volume, 40);
	EXPECT_EQ(result.at("aaa").weighted_average_price, 1161);
	EXPECT_EQ(result.at("aaa").max_price, 1222);


	EXPECT_EQ(result.at("aab").max_time_gap, 6103);
	EXPECT_EQ(result.at("aab").volume, 69);
	EXPECT_EQ(result.at("aab").weighted_average_price, 810);
	EXPECT_EQ(result.at("aab").max_price, 907);


	EXPECT_EQ(result.at("aac").max_time_gap, 3081);
	EXPECT_EQ(result.at("aac").volume, 41);
	EXPECT_EQ(result.at("aac").weighted_average_price, 559);
	EXPECT_EQ(result.at("aac").max_price, 638);
}