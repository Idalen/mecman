#include <vector>
#include <cstdio>

class Database{
    
    private:
        std::vector<int> scores;
        int rrn;
        FILE* db;

    public:
        Database();
        ~Database();
        void addScore(int new_score);
        int getScores(int i);
        int getPlayers();
};