public class NPC extends Unit implements Interactable {
    private String dialogue;

    public NPC() {
        super("NPC1", 100);
        this.dialogue = "Hello there!";
    }
    public NPC(String name, int health, String dialogue) {
        super(name, health);
        this.dialogue = dialogue;
    }

    public String getDialogue() {
        return this.dialogue;
    }
    public void setDialogue(String newDialogue) {
        this.dialogue = newDialogue;
    }

    public void interact() {
        System.out.println(this.dialogue);
    }

    public String toString() {
        String output = this.name + " [Health: " + String.valueOf(this.health) + ", Dialogue: " + this.dialogue + "]"; 
        return output;
    }
}