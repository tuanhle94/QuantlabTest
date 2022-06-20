#include "Quantlab/CSVWriter.hpp"

namespace quantlab {

	void csv_writer::write(const std::string& filename, const std::map<std::string, result> results)
	{
		std::ofstream file(filename);

		for (auto result : results)
		{
			file << result.first << ','; // Send the trade symbol to the stream
			// Send the calculated values to the stream
			file << result.second.max_time_gap << ',' << result.second.volume << ',' << result.second.weighted_average_price << ',' << result.second.max_price << '\n';
		}

		file.close();
	}
} // namespace quantlab