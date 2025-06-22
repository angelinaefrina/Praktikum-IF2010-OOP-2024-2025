public class Couple<K, V> {
    private K key;
    private V value;

    public Couple(K key, V value) {
        this.key = key;
        this.value = value;
    }

    // getter
    public K getKey() {
        return key;
    }
    public V getVal() {
        return value;
    }

    // setter
    public void setKey(K newKey) {
        this.key = newKey;
    }
    public void setVal(V newValue) {
        this.value = newValue;
    }

    public boolean isEqual (Couple c) {
        if (this.key == c.key && this.value == c.value) {
            return true;
        } else {
            return false;
        }
    }

    public int nearEQ(Couple couple) {
        if (isEqual(couple)) {
            return 3;
        } else if (this.key == couple.key) {
            return 1;
        } else if (this.value == couple.value) {
            return 2;
        } else {
            return 0;
        }
    }

    // public static void main(String[] args) {
    //     Couple<String, Integer> a = new Couple<>("A", 1);
    //     Couple<String, Integer> b = new Couple<>("A", 1);
    //     Couple<Integer, Integer> c = new Couple<>(100, 3);
        
    //     // a.setKey("Ini A");
    //     // b.setKey("Ini B");
    //     // a.setValue(1);
    //     // b.setValue(1);

    //     System.out.println("Key A: " + a.getKey());
    //     System.out.println("Key B: " + b.getKey());
    //     System.out.println("Key C: " + c.getKey());

    //     boolean sama = a.isEqual(b);
    //     int near = a.nearEQ(b);

    //     if (sama) {
    //         System.out.println("sama");
    //     } else {
    //         System.out.println("beda");
    //     }

    //     System.out.println("Dekat: " + near);
    // }
}