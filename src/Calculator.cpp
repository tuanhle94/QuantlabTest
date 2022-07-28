#include "Quantlab/Calculator.hpp"

namespace quantlab {

	long long calculator::calculate_max_time_gap(const std::vector<trade>& trades)
	{
		long long current_value = 0;
		long long next_value = 0;
		long long max_time_gap = 0;

		for (int i = 0; i < trades.size() - 1; i++)
		{
			auto j = i + 1; // The next index after i

			current_value = trades.at(i).timestamp;
			next_value = trades.at(j).timestamp;

			auto time_gap = next_value - current_value;
			if (time_gap > max_time_gap)
			{
				max_time_gap = time_gap;
			}
		}
		return max_time_gap;
	}

	int calculator::calculate_total_volume(const std::vector<trade>& trades)
	{
		int total_volume = 0;

		for (const auto& trade : trades)
		{
			total_volume = total_volume + trade.quantity;
		}
		return total_volume;
	}

	int calculator::calculate_max_trade_price(const std::vector<trade>& trades)
	{
		int max_trade_price = 0;

		for (const auto& trade : trades)
		{
			if (trade.price > max_trade_price) {
				max_trade_price = trade.price;

			}
		}
		return max_trade_price;
	}

	int calculator::calculate_weighted_average_price(const std::vector<trade>& trades)
	{
		int numerator = 0;
		int denominator = 0;

		for (const auto& trade : trades)
		{
			numerator = numerator + trade.quantity * trade.price;
			denominator = denominator + trade.quantity;
		}
		return numerator / denominator;
	}


	std::map<std::string, result> calculator::calculate_all(const std::unordered_map<std::string, std::vector<trade>>& input) {
		std::map<std::string, result> results;

		for (const auto& item : input)
		{
			auto symbol = item.first;
			auto trades = item.second;

			auto max_time_gap = calculate_max_time_gap(trades);
			auto total_volume = calculate_total_volume(trades);
			auto weighted_average_price = calculate_weighted_average_price(trades);
			auto max_price = calculate_max_trade_price(trades);

			result result{ max_time_gap , total_volume,  weighted_average_price, max_price };

			results.insert_or_assign(symbol, result);
		}

		return results;
	}

} // namespace quantlab