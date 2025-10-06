import java.time.LocalDate;

public class Person {
  private String name;
  private String lastname;
  private LocalDate bornDate;

  public Person() {
  }

  public Person(String name, String lastname, LocalDate bornDate) {
    this.name = name;
    this.lastname = lastname;
    this.bornDate = bornDate;
  }

  public String getName() {
    return name;
  }

  public void setName(String name) {
    this.name = name;
  }

  public String getLastname() {
    return lastname;
  }

  public void setLastname(String lastname) {
    this.lastname = lastname;
  }

  public LocalDate getBornDate() {
    return bornDate;
  }

  public void setBornDate(LocalDate bornDate) {
    this.bornDate = bornDate;
  }

  public boolean yaCumplio() {
    LocalDate hoy = LocalDate.now();
    LocalDate fechaCumple = LocalDate.of(hoy.getYear(), this.bornDate.getMonth(), this.bornDate.getDayOfMonth());

    return hoy.isAfter(fechaCumple);
  }

  public boolean cumpleHoy() {
    LocalDate hoy = LocalDate.now();
    LocalDate fechaCumple = LocalDate.of(hoy.getYear(), this.bornDate.getMonth(), this.bornDate.getDayOfMonth());
    return fechaCumple.equals(hoy);
  }

  public int calcularEdad() {
    LocalDate hoy = LocalDate.now();
    int edad = hoy.getYear() - bornDate.getYear();
    return (yaCumplio() || cumpleHoy()) ? edad : edad - 1;
  }

  public String retornarPersonaConEdad() {
    StringBuilder sb = new StringBuilder();
    sb.append("Nombre: ");
    sb.append(this.name + " " + this.lastname);
    sb.append("\n");
    sb.append("Edad: ");
    sb.append(this.calcularEdad());
    sb.append("\n");

    if (cumpleHoy()) {
      sb.append("FELIZ CUM AL CRACK DE " + this.name + " ");
    } else if (yaCumplio()) {
      sb.append("Ya cumplió el día ");
    } else {
      sb.append("Todavía no cumplió, cumple el ");
    }
    sb.append(this.bornDate.getDayOfMonth() + "/" + bornDate.getMonthValue());
    return sb.toString();
  }

  public String toStringCSV() {
    StringBuilder sb = new StringBuilder();
    sb.append(this.name).append(",").append(this.lastname).append(",").append(this.bornDate);

    return sb.toString();
  }

}
