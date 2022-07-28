# QuantlabTest

# Feedback from Quantlab developer
- no main! Uses GTest to run the system on input.csv

- stores all trades in memory, a requirement violation

- uses a sorted std::map which reduces performance ----> resolved by using std::unordered_map

- using std::string for a 3 character ticker name is not efficient

- for (auto item : input) takes every item (a vector<trade>) by copy !!! ---> resolved by changing auto item to const auto & item

- reimplemented std::max
