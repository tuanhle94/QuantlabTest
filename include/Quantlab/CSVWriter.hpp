#ifndef QUANTLAB_CSV_WRITER
#define QUANTLAB_CSV_WRITER

#include "Quantlab/Trade.hpp"
#include "Quantlab/QuantlabExports.h"
#include <vector>

#include <string>
#include <map>

namespace quantlab {

	class QUANTLAB_EXPORT csv_writer {
	public:
		static void write(const& std::map<std::string, std::vector<trade>>);
	};


} // namespace quantlab
#endif // !QUANTLAB_CSV_WRITER
