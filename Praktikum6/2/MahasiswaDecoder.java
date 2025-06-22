import java.lang.reflect.*;

public class MahasiswaDecoder {
    private Mahasiswa mahasiswa;

    MahasiswaDecoder(Mahasiswa mahasiswa) {
        this.mahasiswa = mahasiswa;
    }

    public void addMatkul(String name) throws Exception {
        Class<?> mahasiswaClass = this.mahasiswa.getClass();
        Method addMatkulMethod = mahasiswaClass.getDeclaredMethod("addMatkul", String.class);
        addMatkulMethod.setAccessible(true);
        addMatkulMethod.invoke(this.mahasiswa, name);
    }

    public int getNIM() throws Exception {
        Class<?> mahasiswaClass = this.mahasiswa.getClass();
        Field nimMahasiswa = mahasiswaClass.getDeclaredField("NIM");
        nimMahasiswa.setAccessible(true);
        return (int) nimMahasiswa.get(this.mahasiswa);
    }

    public double getIPK() throws Exception {
        Class<?> mahasiswaClass = this.mahasiswa.getClass();
        Field ipkMahasiswa = mahasiswaClass.getDeclaredField("IPK");
        ipkMahasiswa.setAccessible(true);
        return (double) ipkMahasiswa.get(this.mahasiswa);
    }
    
}
