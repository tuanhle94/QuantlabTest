# QuantlabTest

# Feedback from Quantlab developer
- no main! Uses GTest to run the system on input.csv

- stores all trades in memory, a requirement violation

- uses a sorted std::map which reduces performance

- using std::string for a 3 character ticker name is not efficient

- for (auto item : input) takes every item (a vector<trade>) by copy !!!

- reimplemented std::max
