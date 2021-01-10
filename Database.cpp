#include "Database.h"

Database::Database(void)
{
    this->db = fopen("database.bin", "r+b");
    if(this->db == NULL){
        this->db = fopen("database.bin", "w+b");
        this->rrn = 1;
        fprintf(this->db, "%d", this->rrn);
        
    }
    else
    {
        int score;
        fscanf(this->db, "%d", &(this->rrn));
        for(int i = 1; i < this->rrn; i++){
            fscanf(this->db, "%d", &score);
            this->scores.push_back(score);
        }
    }            
}

Database::~Database(){
    fclose(this->db);
}

void Database::addScore(int new_score){
    
    this->scores.push_back(new_score);
    fseek(this->db, sizeof(int)*this->rrn, SEEK_SET);
    fprintf(this->db, "%d", new_score);

    this->rrn ++;

    fseek(this->db, 0, SEEK_SET);
    fprintf(this->db, "%d", this->rrn);
}

int Database::getScores(int i){
    return this->scores.at(i);
}

int Database::getPlayers(){
    return this->rrn-1;
}
