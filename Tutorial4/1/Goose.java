

public class Goose{

    String name;
    int honk;

    public Goose(){
        this.name = "Horrible";
        this.honk = 1;
    }

    public Goose(String name, int honk){
        this.name = name;
        this.honk = honk;
    }

    // method
    public void steal(String thing){
        System.out.println(this.name + " steals " + thing);
    }

    public String toString(){
        String out = this.name + " goose says ";
        for (int i = 0; i < this.honk; i++){
            if (i == this.honk - 1){
                out += ("honk");

            } else {
                out += ("honk ");

            }
        }
        return out;
    }

    // public static void main(String[] args){
    //      Goose g = new Goose();
    //     Goose h = new Goose("Sung Jin-woo", 3);
    //     System.out.println(g);
    //     System.out.println(h);
    //     h.steal("dagger");
    // }
}