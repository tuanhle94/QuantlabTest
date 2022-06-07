#ifndef QUANTLAB_CSV_PARSER
#define QUANTLAB_CSV_PARSER

#include "Quantlab/Trade.hpp"
#include "Quantlab/QuantlabExports.h"

#include <string>
#include <map>

namespace quantlab {

	class QUANTLAB_EXPORT csv_parser {
	public:
		static std::map<std::string, trade> parse(const std::string& filepath);

	};


} // namespace quantlab
#endif // !QUANTLAB_CSV_PARSER
