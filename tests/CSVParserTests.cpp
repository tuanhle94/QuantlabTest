#include "Quantlab/CSVParser.hpp"
#include "gtest/gtest.h"


class ParserTests : public ::testing::Test {};

// Parse an input file

TEST(ParserTests, ParseInvalidFile)
{
	EXPECT_THROW(quantlab::csv_parser::parse("invalid"), std::runtime_error);
}

TEST(ParserTests, ParseValidFile)
{
	auto result = quantlab::csv_parser::parse("sample_files/input.csv");
	EXPECT_FALSE(result.empty());
}
