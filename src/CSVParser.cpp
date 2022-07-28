#include "Quantlab/CSVParser.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

namespace quantlab {

	std::unordered_map<std::string, std::vector<trade>> csv_parser::parse(const std::string& filepath)
	{
		auto trade_map = std::unordered_map<std::string, std::vector<trade>>();
		std::ifstream file(filepath);
		if (!file.is_open()) {
			throw std::runtime_error(
				"The file path is invalid"
			);
		};

		std::string line = "";
		while (std::getline(file, line))
		{
			std::string timestamp;
			std::string symbol;
			std::string quantity;
			std::string price;

			std::stringstream input_string(line);

			std::getline(input_string, timestamp, ',');
			std::getline(input_string, symbol, ',');
			std::getline(input_string, quantity, ',');
			std::getline(input_string, price, ',');

			trade trade_object = { std::stoll(timestamp), symbol, std::stoi(quantity), std::stoi(price) };

			if (trade_map.find(symbol) != trade_map.end()) {
				// Found symbol in the map
				auto& trade_list = trade_map.at(symbol);
				trade_list.push_back(trade_object);
			}
			else {
				auto trade_list = std::vector<trade>();
				trade_list.emplace_back(trade_object);
				trade_map.insert_or_assign(symbol, trade_list);
			}
			line = "";
		}
		return trade_map;
	}
} // namespace quantlab


