#include "core/token_bucket.h"
#include <algorithm>
#include <chrono>

TokenBucket::TokenBucket(double refill_rate, double capacity)
    : refill_rate_(refill_rate),
      capacity_(capacity),
      tokens_(capacity),
      last_refill_time_(std::chrono::steady_clock::now()) {}

void TokenBucket::refill() {
    auto now = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed = now - last_refill_time_;

    double tokens_to_add = elapsed.count() * refill_rate_;
    tokens_ = std::min(capacity_, tokens_ + tokens_to_add);

    last_refill_time_ = now;
}

bool TokenBucket::allow_request(double tokens) {
    refill();

    if (tokens_ >= tokens) {
        tokens_ -= tokens;
        return true;
    }

    return false;
}