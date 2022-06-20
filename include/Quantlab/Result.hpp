#ifndef QUANTLAB_RESULT_HPP
#define QUANTLAB_RESULT_HPP

#include "Quantlab/QuantlabExports.h"

namespace quantlab {

	struct QUANTLAB_EXPORT result {
		/** @brief Amount of time that passes between consecutive trades of a symbol */
		long long max_time_gap;
		/** @brief Sum of the quantity for all trades in a symbol*/
		int volume;
		/** @brief Average price per unit traded not per trade.*/
		int weighted_average_price;
		/** @brief Max Trade Price */
		int max_price;
	};

} // namepsace quantlab
#endif
