class MPMC {
public:
    MPCM(int n) :
        size_{n}, buffer_(n)
    {

    }

    void push(int val) {
        unique_lock<mutex> lock(mutex_);

        not_full_.wait(lock, [&] {
            return writer_ - reader_ < size_;
        });

        buffer_[writer_ % size_] = val;
        writer_++;

        lock.unlock();
        not_empty_.notify_one();
    }

    int pop() {
        unique_lock<mutex> lock(mutex_);

        not_empty_.wait(lock, [&] {
            return writer_ != reader_;
        });

        int val = buffer_[reader_ % size_];
        reader_++;

        lock.unlock();
        not_full_.notify_one();

        return val;
    }

private:
    vector<int> buffer_;
    int size_;

    uint64_t reader_ = 0;
    uint64_t writer_ = 0;

    mutex m_;
    condition_variable not_empty_;
    condition_variable not_full_;
};
