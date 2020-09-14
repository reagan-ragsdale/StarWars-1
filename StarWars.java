abstract class ForceBeing {
  private int power_level;
  private String name;
  private boolean evil;

  protected ForceBeing(int level) {
      power_level = level;
  }

  protected void setPowerLevel(int level) {
    power_level = level;
  }

  public int getPowerLevel() {
    return power_level;
  }
  
  protected void setName(String characterName) {
    name = characterName;
  }

  public String getName() {
    return name;
  }

  public void setEvil() {
    evil = true;
  }

  public void setGood() {
    evil = false;
  }

}

class Jedi extends ForceBeing {
  
  public Jedi(String jediName, int level) {
      super(level);
      setName(jediName);
      setGood();
  }

  public int getPowerLevel() {
    return super.getPowerLevel() + 1;
  }
}

class Sith extends ForceBeing {
  public Sith(String sithName, int level) {
      super(level);
      setName(sithName);
      setEvil();
  }

  public int getPowerLevel() {
    return super.getPowerLevel() - 1;
  }

  public String getName() {
    return "Sith Lord: " + super.getName();
  }
}

public class StarWars {

    public static String getWinner(ForceBeing player1, ForceBeing player2) {
        return player1.getPowerLevel() > player2.getPowerLevel() ? player1.getName() : player2.getName();
    }

    public static void printWinner(String winner) {
        System.out.println("The winner is: " + winner);
    }

    public static void main(String[] args) {
        Sith darthVader = new Sith("Darth Vader",100);
        Jedi lukeSkyWalker = new Jedi("Luke Skywalker",99);
        printWinner(getWinner(darthVader, lukeSkyWalker));
    }
}