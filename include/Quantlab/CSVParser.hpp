#ifndef QUANTLAB_CSV_PARSER
#define QUANTLAB_CSV_PARSER

#include "Quantlab/Trade.hpp"
#include "Quantlab/QuantlabExports.h"
#include <vector>

#include <string>
#include <unordered_map>


namespace quantlab {

	class QUANTLAB_EXPORT csv_parser {
	public:
		static std::unordered_map<std::string, std::vector<trade>> parse(const std::string& filepath);
	};


} // namespace quantlab
#endif // !QUANTLAB_CSV_PARSER
