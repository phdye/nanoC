/*
100
*/
#include <print>
int main() {
    int _private_var;
    int __double_underscore;
    int var_with_underscores_;
    _private_var = 10;
    __double_underscore = 20;
    var_with_underscores_ = 70;
    print_i(_private_var + __double_underscore + var_with_underscores_);
    return 0;
}
