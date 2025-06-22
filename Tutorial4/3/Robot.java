

public class Robot implements CanTalk, CanWalk  {
    public Robot(){}

    public void walk(){
        System.out.println("Robot is walking");
    }
    
    public void talk(){
        System.out.println("Robot is talking");
    }
}