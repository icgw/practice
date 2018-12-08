#include "example.hpp"

#ifdef EXAMPLE
#include EXAMPLE
#else
#include EXAMPLE1
#endif

static const auto _ = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

int main(int argc, char *argv[]){
    RUN_EXAMPLE
	return 0;
}
