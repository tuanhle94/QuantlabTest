#include "Quantlab/CSVWriter.hpp"
#include "Quantlab/CSVParser.hpp"
#include "Quantlab/Calculator.hpp"

#include "gtest/gtest.h"

class WriterTests : public ::testing::Test {};

TEST(WriterTests, WriteSmallOutput)
{
	std::string input_file = "sample_files/small_input.csv";
	auto trade_map = quantlab::csv_parser::parse(input_file);
	auto result = quantlab::calculator::calculate_all(trade_map);
	quantlab::csv_writer::write("small_output.csv", result);
}

TEST(ParserTests, WriteLargeOutput)
{
	std::string input_file = "sample_files/input.csv";
	auto trade_map = quantlab::csv_parser::parse(input_file);
	auto result = quantlab::calculator::calculate_all(trade_map);
	quantlab::csv_writer::write("output.csv", result);
}