#ifndef QUANTLAB_CSV_WRITER
#define QUANTLAB_CSV_WRITER

#include "Quantlab/Trade.hpp"
#include "Quantlab/Result.hpp"
#include "Quantlab/QuantlabExports.h"
#include <vector>
#include <fstream>
#include <string>
#include <map>

namespace quantlab {

	class QUANTLAB_EXPORT csv_writer {
	public:
		static void write(const std::string& filename, const std::map<std::string, result> results);
	};


} // namespace quantlab
#endif // !QUANTLAB_CSV_WRITER
