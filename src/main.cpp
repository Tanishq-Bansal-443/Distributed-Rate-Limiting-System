#include <iostream>
#include "core/token_bucket.h"
#include <thread>

int main() {
    TokenBucket bucket(5.0, 10.0); // 5 tokens/sec, burst = 10

    for (int i = 0; i < 20; i++) {
        bool allowed = bucket.allow_request();

        std::cout << "Request " << i 
                  << (allowed ? " ALLOWED" : " DENIED") 
                  << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }

    return 0;
}
