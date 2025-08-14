package practica1;

public class Movie {
    private String title;
    private String director;
    private int duration;
    private boolean watched;

    public Movie(String title, String director, int duration, boolean watched){
        this.title = title;
        this.director = director;
        this.duration = duration;
        this.watched = watched || false;
    }

    public Movie(String title, String director, int duration){
        this(title, director,duration, false);  
    }

    public Movie(String title, String director){
        this(title, director, 0, false);
    }

    public void markAsWatched(){
        this.watched = true;
    }

    @Override
    public String toString(){
        return "Movie {\n   title: "+ this.title + "\n   director: " + this.director +"\n   duration: "+this.duration + "\n   watched: "+this.watched+"\n}\n";
    }

    public String getTitle(){
        return this.title;
    }

    public String getDirector(){
        return this.director;
    }

    public int getDuration(){
        return this.duration;
    }

    public boolean getWatched(){
        return this.watched;
    }

    public void setTitle(String title){
        if (title.isEmpty() || title == null) {
            this.title = "I'm empty";
            return;
        }
        this.title = title;
    }

    public void setDirector(String director){
        this.director = director;
    }

    public void setDuration(int duration){
        if (duration < 0) {
            this.duration = 1;
            return;
        }
        this.duration = duration;
    }

    public void setWatched(boolean watched){
        this.watched = watched;
    }
}