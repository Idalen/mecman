
class Scoreboard
{
    public:

        explicit Scoreboard (int lives, int score, int level)
        {
            this->lives = lives;
            this->score = score;
            this->level = level;
        }
        
        // Getters/Setters
        int getLives() {return lives;}
        int getScore() {return score;}
        int getLevel() {return level;}
        void setLives(int lives) {this->lives = lives;}
        void setScore(int score) {this->score = score;}
        void setLevel(int level) {this->level = level;}

    private:
        int lives;
        int score;
        int level;
};