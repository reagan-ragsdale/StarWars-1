#include <iostream>
#include <string>

using namespace std;
class ForceBeing {
  private:
   int power_level;
   string name;
   bool evil;

  protected:
    ForceBeing(int level) {
      power_level = level;
    }

    void setPowerLevel(int level) {
    power_level = level;
    }

    void setName(string characterName) {
    name = characterName;
    }
   
  

   public:
   virtual string getName() {
    return name;
    }

    void setEvil() {
    evil = true;
    }

    void setGood() {
    evil = false;
    }
    virtual int getPowerLevel() {
    return power_level;
  }
};
  



class Jedi: public ForceBeing {
  
  public:
    Jedi(string jediName, int level):ForceBeing(level) {
    
      setName(jediName);
      setGood();
    }

    int getPowerLevel() {
    return ForceBeing::getPowerLevel() + 1;
  }
};

class Sith: public ForceBeing {
  public: 
    Sith(string sithName, int level):ForceBeing(level) {
      setName(sithName);
      setEvil();
    }

    int getPowerLevel() {
    return ForceBeing::getPowerLevel() - 1;
    }

    string getName() {
    return "Sith Lord: " + ForceBeing::getName();
  }
};



    string getWinner(ForceBeing player1, ForceBeing player2) {
        return player1.getPowerLevel() > player2.getPowerLevel() ? player1.getName() : player2.getName();
    }

    void printWinner(string winner) {
        cout << "The winner is: " << winner << endl;
    }

    int main() {
        Sith darthVader("JarJar",100);
        Jedi lukeSkyWalker("Anyone",1);
        printWinner(getWinner(darthVader, lukeSkyWalker));
        return 0;
    }
