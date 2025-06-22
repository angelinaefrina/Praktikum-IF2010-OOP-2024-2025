import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.util.ArrayList;
import java.util.List;

public class Reflection{
    //TIDAK BOLEH MENGUBAH NAMA METHOD YANG SUDAH ADA DAN PARAMS SERTA INPUT TYPENYA
    //BOLEH MENAMBAHKAN PRIVATE / PROTECTED METHOD SESUAI DENGAN KEBUTUHAN
    //DI LUAR SANA ADA KELAS YANG NAMANYA Ghost DAN Secret.

    public ArrayList<String> ghostMethods(){
        ArrayList<String> methods = new ArrayList<>();
        try {
            Class<?> ghostClass = Class.forName("Ghost");
            Method[] declaredMethods = ghostClass.getDeclaredMethods();
            for (Method method : declaredMethods) {
                methods.add(method.getName());
            }
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }
        return methods;
    }   

    public Integer sumGhost() throws Exception{
        Integer sum = 0;
        Class<?> ghostClass = Class.forName("Ghost");
        Object ghostInstance = ghostClass.getDeclaredConstructor().newInstance();

        Method[] methods = ghostClass.getDeclaredMethods();
        for (Method method : methods) {
            method.setAccessible(true);
            if (method.getReturnType() == Integer.class) {
                Object result = method.invoke(ghostInstance);
                if (result instanceof Integer) {
                    sum += (Integer) result;
                }
            }
        }

        return sum;
    }

    public String letterGhost() throws Exception{
        StringBuilder sb = new StringBuilder();
        Class<?> ghostClass = Class.forName("Ghost");
        Object ghostInstance = ghostClass.getDeclaredConstructor().newInstance();

        Method[] methods = ghostClass.getDeclaredMethods();
        for (Method method : methods) {
            method.setAccessible(true);
            if (method.getReturnType() == String.class) {
                Object result = method.invoke(ghostInstance);
                if (result instanceof String) {
                    sb.append((String) result);
                }
            }
        }        
        return sb.toString();
    }

    public String findSecretId(List<Secret> sl, String email) throws Exception{
        if (sl == null || email == null) {
            return "NaN";
        }
        for (Secret secret : sl) {
            if (secret.isThis(email)) {
                try {
                    Field uniqueIdField = Secret.class.getDeclaredField("uniqueId");
                    uniqueIdField.setAccessible(true);
                    return (String) uniqueIdField.get(secret);
                } catch (Exception e) {
                    return "NaN";
                }
            }
        }
        return "NaN";
    }

    // public static void main(String[] args) {
    //     Reflection reflection = new Reflection();

    //     // Uji ghostMethods()
    //     System.out.println("Metode di kelas Ghost: " + reflection.ghostMethods());

    //     // Uji sumGhost()
    //     try {
    //         System.out.println("Jumlah nilai Integer dari Ghost: " + reflection.sumGhost());
    //     } catch (Exception e) {
    //         System.err.println("Error saat sumGhost: " + e.getMessage());
    //         e.printStackTrace();
    //     }

    //     // Uji letterGhost()
    //     try {
    //         System.out.println("Gabungan String dari Ghost: " + reflection.letterGhost());
    //     } catch (Exception e) {
    //         System.err.println("Error saat letterGhost: " + e.getMessage());
    //         e.printStackTrace();
    //     }

    //     // Uji findSecretId()
    //     Secret.counter = 0; // Reset counter untuk konsistensi pengujian ID
    //     List<Secret> secretList = new ArrayList<>();
    //     secretList.add(new Secret("alice@example.com", "Alice Wonderland"));
    //     secretList.add(new Secret("bob@example.com", "Bob The Builder"));
    //     secretList.add(new Secret("charlie@example.com", "Charlie Brown"));
    //     secretList.add(new Secret("alice@example.com", "Alice Duplicate Email")); // ID akan beda

    //     try {
    //         System.out.println("Mencari ID untuk alice@example.com: " + reflection.findSecretId(secretList, "alice@example.com"));
    //         System.out.println("Mencari ID untuk bob@example.com: " + reflection.findSecretId(secretList, "bob@example.com"));
    //         System.out.println("Mencari ID untuk david@example.com (tidak ada): " + reflection.findSecretId(secretList, "david@example.com"));
    //         System.out.println("Mencari ID untuk null email: " + reflection.findSecretId(secretList, null));
    //         System.out.println("Mencari ID dalam null list: " + reflection.findSecretId(null, "alice@example.com"));

    //         // Test case untuk email yang ada tapi dengan case berbeda
    //         System.out.println("Mencari ID untuk ALICE@EXAMPLE.COM: " + reflection.findSecretId(secretList, "ALICE@EXAMPLE.COM"));

    //     } catch (Exception e) {
    //         System.err.println("Error saat findSecretId: " + e.getMessage());
    //         e.printStackTrace();
    //     }
    //     System.out.println("Total Secret objek dibuat: " + Secret.counter);
    // }
}

