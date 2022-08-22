public class Director {
    String  Nombre;
    String  Apellido;
    int premiosGanados;
    int peliculasDirigidas;


    public Director(String nombre, String apellido, int peliculasDirigidas, int premiosGanados) {
        Nombre = nombre;
        Apellido = apellido;
        this.peliculasDirigidas = peliculasDirigidas;
        this.premiosGanados = premiosGanados;
    }

    public int getPeliculasDirigidas() {
        return peliculasDirigidas;
    }

    public void setPeliculasDirigidas(int peliculasDirigidas) {
        this.peliculasDirigidas = peliculasDirigidas;
    }

    public int getPremiosGanados() {
        return premiosGanados;
    }

    public void setPremiosGanados(int premiosGanados) {
        this.premiosGanados = premiosGanados;
    }

    public String getNombre() {
        return Nombre;
    }

    public void setNombre(String nombre) {
        Nombre = nombre;
    }

    public String getApellido() {
        return Apellido;
    }

    public void setApellido(String apellido) {
        Apellido = apellido;
    }
}


