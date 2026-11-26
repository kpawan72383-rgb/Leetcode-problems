class Solution {
public:
    bool canAliceWin(int n) {
        int move = 10;
        bool aliceTurn = true;
        while (n >= move && move > 0) {
            n -= move;
            move--;
            aliceTurn = !aliceTurn;
        }
        return !aliceTurn;
    }
};
