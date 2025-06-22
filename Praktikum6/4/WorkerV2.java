import java.util.List;
import java.util.ArrayList;

public class WorkerV2 implements Runnable {

    private List<Task> tasks;

    public WorkerV2(){
        //TODO: Fill with the default constructor of this class.
        tasks = new ArrayList<Task>();
    };

    public void addTask(Task newTask){
        //TODO: Fill with the operation that will add new task to tasks.
        this.tasks.add(newTask);
    }

    @Override
    public void run() {
        try {
            //TODO: Fill with the operation that will process the tasks. Hint: the operation is exactly
            // the same with the operation that exist on Worker.java with a little improvement;)
            for (Task t : tasks) {
                Thread.sleep(t.getTime());
                synchronized (t) {
                    t.setStatus("done");
                    t.notifyAll();
                }
            }
        } catch (InterruptedException e) {
            //TODO: Fill with the same error message on the Worker.java
            System.out.println("Worker Error!");
        }

    }
    
}
