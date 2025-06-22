public class Email {
    private String email;

    public Email(String email) {
        this.email = email;
    }

    public boolean validateEmail() throws InvalidEmailException, InvalidDomainException {
        /**
         * Implementasi dengan aturan:
         * Aturan email
         * - Email harus mengandung tepat 1 karakter @ ditengah email
         * - Bagian sebelum @ tidak boleh kosong
         * - Bagian email setelah @ harus memiliki tepat 1 buah titik (.)
         * - Email hanya akan mengandung huruf, angka, (@), dan (.). Karakter lain tidak
         * perlu diperiksa
         *
         * "john@example.com" => Email Valid
         * "jane.doe@gmail.com" => Email Valid
         * "" => mengembalikan pesan "Email tidak boleh kosong"
         * "example.com" => mengembalikan pesan "Email harus mengandung tepat satu buah @"
         * "@example.com" => mengembalikan pesan "@ tidak boleh di awal email"
         * "john@com" => mengembalikan pesan "Email harus memiliki domain yang valid"
         */

        // Memeriksa apakah email kosong atau null
        if (this.email == null || this.email.isEmpty()) {
            throw new InvalidEmailException("Email tidak boleh kosong");
        }

        int atIndex = this.email.indexOf('@');

        // Memeriksa apakah '@' tidak ada atau berada di awal
        if (atIndex == -1) {
            throw new InvalidEmailException("Email harus mengandung tepat satu buah @");
        }
        if (atIndex == 0) {
            throw new InvalidEmailException("@ tidak boleh di awal email");
        }

        // Memeriksa apakah terdapat lebih dari satu '@'
        if (this.email.lastIndexOf('@') != atIndex) {
            throw new InvalidEmailException("Email harus mengandung tepat satu buah @");
        }

        // Memisahkan bagian domain dari email
        String domainPart = this.email.substring(atIndex + 1);

        int dotIndex = domainPart.indexOf('.');

        // Memvalidasi domain:
        // 1. Harus memiliki tepat satu titik (indexOf dan lastIndexOf harus sama dan tidak -1)
        // 2. Titik tidak boleh berada persis setelah '@' (misal: john@.com)
        // 3. Titik tidak boleh berada di akhir domain (misal: john@com.)
        if (dotIndex == -1 || dotIndex == 0 || dotIndex == domainPart.length() - 1 || domainPart.lastIndexOf('.') != dotIndex) {
            throw new InvalidDomainException();
        }

        return true;
    }

    /*
    // Contoh penggunaan (main method)
    public static void main(String[] args) {
        String[] testEmails = {
            "john@example.com",     // Valid
            "jane.doe@gmail.com",   // Valid
            "",                     // Invalid: Kosong
            "example.com",          // Invalid: Tanpa @
            "@example.com",         // Invalid: @ di awal
            "john@com",             // Invalid: Domain tanpa .
            "john@.com",            // Invalid: . setelah @
            "john@com.",            // Invalid: . di akhir domain
            "john@a.b.com",         // Invalid: Lebih dari 1 . di domain
            "john@doe@com.id"       // Invalid: Lebih dari 1 @
        };

        for (String emailStr : testEmails) {
            Email email = new Email(emailStr);
            try {
                if (email.validateEmail()) {
                    System.out.println("\"" + emailStr + "\" => Email Valid");
                }
            } catch (InvalidEmailException | InvalidDomainException e) {
                System.out.println("\"" + emailStr + "\" => " + e.getMessage());
            }
        }
    }
    */
}

class InvalidEmailException extends Exception {
    public InvalidEmailException(String message) {
        // Implementasi InvalidEmailException
        super(message);
    }
}

class InvalidDomainException extends Exception {
    @Override
    public String getMessage() {
        // Implementasi custom message InvalidDomainException
        // Return pesan mutlak berisi: "Email harus memiliki domain yang valid"
        return "Email harus memiliki domain yang valid";
    }
}