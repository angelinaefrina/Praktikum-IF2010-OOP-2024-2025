import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws InterruptedException {
        Scanner sc = new Scanner(System.in);

        // 1. Baca N dan data array
        int N = sc.nextInt();
        int[] data = new int[N];
        for (int i = 0; i < N; i++) {
            data[i] = sc.nextInt();
        }

        // 2. Baca T = jumlah thread yang diinginkan
        int T = sc.nextInt();
        if (T <= 0) {
            System.out.println("Jumlah thread harus >= 1");
            sc.close();
            return;
        }

        // 3. Siapkan array untuk hasil dan thread pool
        int[] sums    = new int[T];
        Thread[] threads = new Thread[T];

        // 4. BAGIAN PENGERJAAN (TODO):
        //    - Bagi array `data` ke dalam T segmen sedemikian rupa sehingga selisih jumlah elemen antar segmen <= 1.
        //      Jika N tidak habis dibagi T, maka thread dengan indeks lebih kecil akan mendapatkan 1 elemen ekstra.
        //      Contoh: N=8, T=3 segmen ukuran [3, 3, 2].
        //    - Untuk setiap segmen ke-i (0 <= i < T):
        //       Buat satu SumThread yang menghitung jumlah elemen pada segmen tersebut.
        //       SumThread menulis hasilnya ke sums[i].
        //    - Jalankan semua SumThread, kemudian tunggu
        //      hingga semua perhitungan selesai sebelum mencetak hasil.
        if (N > 0 && T > 0) {
            int base_segment_size = N / T;
            int remainder_segments = N % T;
            int curr_data_idx = 0;

            for (int i = 0; i < T; i++) {
                int segment_size = base_segment_size + (i < remainder_segments ? 1 : 0);
                int data_start_idx = curr_data_idx;
                int data_end_idx = curr_data_idx + segment_size;

                threads[i] = new SumThread(data, sums, data_start_idx, data_end_idx, i);
                curr_data_idx = data_end_idx;
            }

            // jalanin semua thread
            for (int i = 0; i < T; i++) {
                threads[i].start();
            }

            for (int i = 0; i < T; i++) {
                threads[i].join(); // tunggu sampai semua thread selesai
            }
        }


        // 7. Cetak hasil per-segmen dan total
        int total = 0;
        for (int i = 0; i < T; i++) {
            System.out.println("Sum" + i + " = " + sums[i]);
            total += sums[i];
        }
        System.out.println("Total = " + total);

        sc.close();
    }

    /**
     * Thread yang menghitung jumlah elemen pada sebagian array integer.
     * Setiap SumThread bertugas menjumlahkan elemen pada rentang
     * data[dataStartIndex..dataEndIndex-1] dan menyimpan hasilnya di result[threadIndex].
     */
    private static class SumThread extends Thread {
        private final int[] data;
        private final int[] result;
        private final int dataStartIndex;
        private final int dataEndIndex;
        private final int threadIndex;

        /**
         * @param data             Array lengkap bilangan bulat yang akan dijumlahkan.
         * @param result           Array bersama untuk menyimpan hasil setiap thread.
         * @param dataStartIndex   Indeks awal (inklusif) segmen data yang dihitung.
         * @param dataEndIndex     Indeks akhir (eksklusif) segmen data yang dihitung.
         * @param threadIndex      Posisi di array result tempat menyimpan hasil.
         */
        public SumThread(int[] data, int[] result,
                        int dataStartIndex, int dataEndIndex,
                        int threadIndex) {
            this.data             = data;
            this.result           = result;
            this.dataStartIndex   = dataStartIndex;
            this.dataEndIndex     = dataEndIndex;
            this.threadIndex      = threadIndex;
        }

        /**
         * Menjalankan perhitungan jumlah elemen pada segmen yang ditentukan
         * dan menyimpan nilai sum ke result[threadIndex].
         */
        @Override
        public void run() {
            // TODO
            int sum = 0;
            for (int i = dataStartIndex; i < dataEndIndex; i++) {
                sum += data[i];
            }
            result[threadIndex] = sum; // simpan hasil ke result
        }
    }
}
