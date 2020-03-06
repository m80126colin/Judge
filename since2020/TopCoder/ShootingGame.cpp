/**
 * @judge TopCoder
 * @name ShootingGame
 * 
 * @tag Math, Probability
 */
class ShootingGame {
    public:
        double findProbability(int p) {
            if (p > 500000)
                return -1.0;
            return (double) p / (1000000 - p);
        }
};