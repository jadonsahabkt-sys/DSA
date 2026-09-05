class Solution {
public:
         vector<string> ans;

    void solve(string& num, long long target, int index,
               string expression, long long value, long long prev) {

        // All digits have been used
        if (index == num.size()) {
            if (value == target) {
                ans.push_back(expression);
            }
            return;
        }

        // Try every possible number starting from index
        for (int i = index; i < num.size(); i++) {

            // Leading zero is not allowed
            if (i > index && num[index] == '0') {
                break;
            }

            string part = num.substr(index, i - index + 1);
            long long current = stoll(part);

            // First number
            if (index == 0) {

                solve(num, target, i + 1,
                      part, current, current);
            }
            else {

                // +
                solve(num, target, i + 1,
                      expression + "+" + part,
                      value + current,
                      current);

                // -
                solve(num, target, i + 1,
                      expression + "-" + part,
                      value - current,
                      -current);

                // *
                solve(num, target, i + 1,
                      expression + "*" + part,
                      value - prev + prev * current,
                      prev * current);
            }
        }
    }


    vector<string> addOperators(string num, int target) {
         solve(num, target, 0, "", 0, 0);

        return ans;
    }
};