#ifndef QUANTLAB_CALCULATOR
#define QUANTLAB_CALCULATOR

#include "Quantlab/Trade.hpp"
#include "Quantlab/Result.hpp"

#include "Quantlab/QuantlabExports.h"

#include <string>
#include <map>
#include <vector>

namespace quantlab {

	class QUANTLAB_EXPORT calculator {

	public:
		static std::map<std::string, result> calculate_all(const std::map<std::string, std::vector<trade>>& input);
		static long long calculate_max_time_gap(const std::vector<trade>& trades);
		static int calculate_total_volume(const std::vector<trade>& trades);
		static int calculate_max_trade_price(const std::vector<trade>& trades);
		static int calculate_weighted_average_price(const std::vector<trade>& trades);
	};


} // namespace quantlab
#endif // !QUANTLAB_CALCULATOR
