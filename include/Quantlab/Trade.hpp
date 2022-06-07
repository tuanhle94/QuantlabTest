#ifndef QUANTLAB_TRADE_HPP
#define QUANTLAB_TRADE_HPP

#include "Quantlab/QuantlabExports.h"

#include <string>
#include <vector>

namespace quantlab {

	struct QUANTLAB_EXPORT trade {
		/** @brief Value indicating the microseconds since midnight.. */
		int timestamp;
		/** @brief The 3 character unique identifier for a financial instrument (Stock, future etc.)*/
		std::string symbol;
		/** @brief The amount traded */
		int quantity;
		/** @brief The price of the trade for that financial instrument */
		int price;
	};

} // namepsace quantlab
#endif
