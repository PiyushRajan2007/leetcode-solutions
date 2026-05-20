class Foo {
private:
    atomic<bool> firstDone;
    atomic<bool> secondDone;

public:
    Foo() {
        firstDone = false;
        secondDone = false;
    }

    void first(function<void()> printFirst) {
        // Print "first"
        printFirst();

        // Signal that first() is completed
        firstDone = true;
    }

    void second(function<void()> printSecond) {
        // Wait until first() finishes
        while (!firstDone.load()) {
        }

        // Print "second"
        printSecond();

        // Signal that second() is completed
        secondDone = true;
    }

    void third(function<void()> printThird) {
        // Wait until second() finishes
        while (!secondDone.load()) {
        }

        // Print "third"
        printThird();
    }
};