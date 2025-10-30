package entities;

import java.time.LocalDate;

import enums.EstadoReserva;

public class Reserva {
  private String codigoReserva;
  private String nombreHuesped;
  private int numeroHabitacion;
  private int cantidadNoches;
  private EstadoReserva estado;
  private LocalDate fechaIngreso;

  public Reserva(String codigo, String nombreHuesped, int numeroHabitacion, int cantidadNoches) {
    this.codigoReserva = codigo;
    this.nombreHuesped = nombreHuesped;
    this.numeroHabitacion = numeroHabitacion;
    this.cantidadNoches = cantidadNoches;
    this.estado = EstadoReserva.PENDIENTE;
    this.fechaIngreso = LocalDate.now();
  }

  public String getCodigoReserva() {
    return codigoReserva;
  }

  public void setCodigoReserva(String codigoReserva) {
    this.codigoReserva = codigoReserva;
  }

  public String getNombreHuesped() {
    return nombreHuesped;
  }

  public void setNombreHuesped(String nombreHuesped) {
    this.nombreHuesped = nombreHuesped;
  }

  public int getNumeroHabitacion() {
    return numeroHabitacion;
  }

  public void setNumeroHabitacion(int numeroHabitacion) {
    this.numeroHabitacion = numeroHabitacion;
  }

  public int getCantidadNoches() {
    return cantidadNoches;
  }

  public void setCantidadNoches(int cantidadNoches) {
    this.cantidadNoches = cantidadNoches;
  }

  public EstadoReserva getEstado() {
    return estado;
  }

  public void setEstado(EstadoReserva estado) {
    this.estado = estado;
  }

  public LocalDate getFechaIngreso() {
    return fechaIngreso;
  }

  public void setFechaIngreso(LocalDate fechaIngreso) {
    this.fechaIngreso = fechaIngreso;
  }

  @Override
  public String toString() {
    return "Codigo: [" + this.codigoReserva + "] | Huesped: [" + this.nombreHuesped + "] | Habitacion: ["
        + this.numeroHabitacion + "] | Noches: [" + this.cantidadNoches + "] | Estado: [" + this.estado.toString()
        + "]";
  }
}
