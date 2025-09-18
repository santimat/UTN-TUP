package biblio2;

// Esta execpcion es Checked
public class LibroNoEncontradoException extends Exception {
    public LibroNoEncontradoException(String message) {
        super(message);
    }
}
