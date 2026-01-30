#include <chrono>

class TokenBucket {
public:
    TokenBucket(double refill_rate, double capacity);

    bool allow_request(double tokens = 1.0);

private:
    double refill_rate_; 
    double capacity_;
    double tokens_;

    std::chrono::steady_clock::time_point last_refill_time_;

    void refill();
};