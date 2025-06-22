public class Character extends Unit implements Damageable {
    private int score;

    public Character() {
        super("Player1", 100);
        this.score = 0;
    }
    public Character(String name, int health, int score) {
        super(name, health);
        this.score = score;
    }

    public int getScore() {
        return this.score;
    }
    public void setScore(int newScore) {
        this.score = newScore;
    }

    public void takeDamage(int damage) {
        this.health -= damage;
        if (this.health <= 0) {
            System.out.println(this.name + " has been defeated");
        }
    }
    public void increaseScore(int points) {
        this.score += points;
    }

    public String toString() {
        String output = this.name + " [Health: " + String.valueOf(this.health) + ", Score: " + String.valueOf(this.score) + "]"; 
        return output;
    }
}