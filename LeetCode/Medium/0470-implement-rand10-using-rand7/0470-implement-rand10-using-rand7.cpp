class Solution {
public:
    int rand10() {
        while (true) {
            int a = rand7();
            int b = rand7();

            int num = (a - 1) * 7 + b;   // 1 to 49

            if (num <= 40)
                return (num - 1) % 10 + 1;
        }
    }
};