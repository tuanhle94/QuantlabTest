#include "Quantlab/CSVParser.hpp"
#include "gtest/gtest.h"


class ParserTests : public ::testing::Test {};

// Parse an input file

TEST(ParserTests, ParseInvalidFile)
{
	auto result = quantlab::csv_parser::parse("invalid");
	EXPECT_TRUE(result.empty());
}
