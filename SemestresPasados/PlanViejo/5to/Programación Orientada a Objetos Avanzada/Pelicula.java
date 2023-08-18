public class Pelicula {
    private String title;
    private int relYear;
    private Director director;
    private String img_url;
    private Genero clasificacion;

    public Pelicula(String title, int relYear, Director director, String img_url, Genero clasificacion) {
        this.title = title;
        this.relYear = relYear;
        this.director = director;
        this.img_url = img_url;
        this.clasificacion = clasificacion;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getImg_url() {
        return img_url;
    }

    public void setImg_url(String str){ this.img_url = str; }

    public int getRelYear() {
        return relYear;
    }

    public void setRelYear(int relYear) {
        this.relYear = relYear;
    }

    public Director getDirector() {
        return director;
    }

    public void setDirector(Director director) {
        this.director = director;
    }

    public Genero getClasificacion() {
        return clasificacion;
    }

    public void setClasificacion(Genero clasificacion) {
        this.clasificacion = clasificacion;
    }
}