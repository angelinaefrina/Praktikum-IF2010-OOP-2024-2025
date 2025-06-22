abstract class Unit {
    protected String name;
    protected int health;

    public Unit (String name, int health) {
        this.name = name;
        this.health = health;
    }

    public String getName() {
        return this.name;
    }
    public void setName(String newName) {
        this.name = newName;
    }

    public int getHealth() {
        return this.health;
    }
    public void setHealth(int newHealth) {
        this.health = newHealth;
    }

    abstract public String toString();
}