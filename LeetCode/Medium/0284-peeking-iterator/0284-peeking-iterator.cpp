class PeekingIterator : public Iterator {
private:
    int nxt;
    bool has_next;

public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        has_next = Iterator::hasNext();

        if (has_next) {
            nxt = Iterator::next();
        }
	}

	int peek() {
        return nxt;
	}

	int next() {
        int curr = nxt;

        has_next = Iterator::hasNext();

        if (has_next) {
            nxt = Iterator::next();
        }

        return curr;
	}

	bool hasNext() const {
        return has_next;
	}
};