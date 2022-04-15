#include <iostream>
#include <cstring>

struct Player
{
    char name[64];
    double salary;

    void print()
    {
        std::cout << name << " " << salary << std::endl;
    }
};

void swap(Player& p1, Player& p2)
{
    double swp_salary = p1.salary;
    p1.salary = p2.salary;
    p2.salary = swp_salary;

    char swp_name[64];
    strcpy(swp_name, p1.name);
    strcpy(p1.name, p2.name);
    strcpy(p2.name, swp_name);
}

class FootballTeam
{
private:    
    Player* players;
    int size;

public:
    FootballTeam()
    {
        this->players = nullptr;
        this->size = 0;
    }

    ~FootballTeam()
    {
        delete[] this->players;
    }

    void add_player(const Player& newPlayer)
    {   
        Player* tmp = new Player[size + 1];
        for(int i = 0; i < size; i++)
        {
            strcpy(tmp[i].name, this->players[i].name);
            tmp[i].salary = this->players[i].salary;
        }
        strcpy(tmp[size].name, newPlayer.name);
        tmp[size].salary = newPlayer.salary;

        if(this->players != nullptr)
        {
            delete[] this->players;
        }
        this->players = tmp;
        ++size;
    }

    Player& get_most_expensive_player() const
    {
        int max_salary = players[0].salary;
        int wantedPlayer = 0;
        
        for(int i = 1; i < size; i++)
        {
            if(players[i].salary > max_salary)
            {
                max_salary = players[i].salary;
                wantedPlayer = i;
            }
        }
        
        return players[wantedPlayer];
    }
    
    Player get_cheapest_player() const
    {
        int min_salary = players[0].salary;
        int wantedPlayer = 0;
        
        for(int i = 1; i < this->size; i++)
        {
            if(players[i].salary < min_salary)
            {
                min_salary = players[i].salary;
                wantedPlayer = i;
            }
        }
        
        return players[wantedPlayer];
    }   

    double avg_salary() const
    {
        double result = 0;

        for(int i = 0; i < this->size; i++)
        {
            result += players[i].salary;
        }

        return result / this->size;
    }

    Player* sorted_array_of_players()
    {
        Player* tmp = new Player[size];
        for(int i = 0; i < size; i++)
        {
            strcpy(tmp[i].name, this->players[i].name);
            tmp[i].salary = this->players[i].salary;
        }       
        for(int i = 0; i < this->size; i++)
        {
            for(int j = i + 1; j < this->size; j++)
            {
                if(tmp[i].salary > tmp[j].salary)
                {
                    swap(tmp[i], tmp[j]);
                }
            }
        }
        return tmp;
    }
};


int main()
{
    Player p1{"Ivan", 3500};
    Player p2{"Petur", 4500};
    Player p3{"Traicho", 2500};
    Player p4{"Mitko", 3700};

   FootballTeam FMI;

    FMI.add_player(p1);
    FMI.add_player(p2);
    FMI.add_player(p3);
    FMI.add_player(p4);

 
    FMI.get_most_expensive_player().print();
    FMI.get_cheapest_player().print();
    
    std::cout << FMI.avg_salary() << std::endl;

  
    Player* sorted_players = FMI.sorted_array_of_players();

    for(int i = 0; i < 4; i++)
    {
        sorted_players[i].print();
    }
    
    delete[] sorted_players;
    
   
}
