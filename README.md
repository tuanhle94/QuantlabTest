# QuantlabTest

# Feedback from Quantlab developer
- no main! Uses GTest to run the system on input.csv ----> Main is not needed since the job description is about maintaining a trading library. Therefore, I am showing Quantlab how to make a library

- stores all trades in memory, a requirement violation ---> Not sure what they want

- uses a sorted std::map which reduces performance ----> resolved by using std::unordered_map

- using std::string for a 3 character ticker name is not efficient ---> Could use a C-style string or std::string_view?

- for (auto item : input) takes every item (a vector<trade>) by copy !!! ---> resolved by changing auto item to const auto & item

- reimplemented std::max ----> Yes std::max should've been used. I just forgot about it when implementing the solution
