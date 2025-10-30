package services;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

import entities.Reserva;
import enums.EstadoReserva;
import exceptions.ReservaNoEncotradaException;

public class SistemaReserva {

  private final static int TOTAL_HABITACIONES = 50;

  // codigo de reserva -> reserva
  private HashMap<String, Reserva> reservas;
  // numero de habitacion -> codigo de reserva
  private HashMap<Integer, String> habitacionesOcupadas;

  public SistemaReserva() {
    this.reservas = new HashMap<>();
    this.habitacionesOcupadas = new HashMap<>();
  }

  public Reserva getReservaByCodigo(String codigo) throws ReservaNoEncotradaException {
    Reserva reserva = this.reservas.get(codigo);
    if (reserva == null) {
      throw new ReservaNoEncotradaException("No hay una habitación con el codigo: " + codigo);
    }
    return reserva;
  }

  private void cambiarEstado(String codigo, EstadoReserva estado) throws ReservaNoEncotradaException {
    Reserva reserva = getReservaByCodigo(codigo);
    reserva.setEstado(estado);
  }

  public void agregarReserva(Reserva reserva) throws IllegalStateException {
    if (habitacionesOcupadas.containsKey(reserva.getNumeroHabitacion())
        && habitacionesOcupadas.size() < SistemaReserva.TOTAL_HABITACIONES) {
      throw new IllegalStateException("La habitación " + reserva.getNumeroHabitacion() + " ya está ocupada");
    }

    reservas.put(reserva.getCodigoReserva(), reserva);
    habitacionesOcupadas.put(reserva.getNumeroHabitacion(), reserva.getCodigoReserva());
  }

  public void confirmarReserva(String codigoReserva) throws ReservaNoEncotradaException {
    this.cambiarEstado(codigoReserva, EstadoReserva.CONFIRMADA);
  }

  public void hacerCheckIn(String codigoReserva) throws ReservaNoEncotradaException {
    this.cambiarEstado(codigoReserva, EstadoReserva.CHECK_IN);
  }

  public void hacerCheckOut(String codigoReserva) throws ReservaNoEncotradaException {
    Reserva reservaCheckout = getReservaByCodigo(codigoReserva);
    reservaCheckout.setEstado(EstadoReserva.CHECK_OUT);
    habitacionesOcupadas.remove(reservaCheckout.getNumeroHabitacion());
  }

  public void cancelarReserva(String codigoReserva) throws ReservaNoEncotradaException {
    Reserva reservaACancelar = getReservaByCodigo(codigoReserva);
    reservaACancelar.setEstado(EstadoReserva.CANCELADA);
    habitacionesOcupadas.remove(reservaACancelar.getNumeroHabitacion());
  }

  public List<Reserva> getReservasByEstado(EstadoReserva estado) {
    ArrayList<Reserva> reservasPorEstado = new ArrayList<>();

    for (Reserva reserva : this.reservas.values()) {
      if (reserva.getEstado().equals(estado)) {
        reservasPorEstado.add(reserva);
      }
    }

    return reservasPorEstado;
  }

  public String getReporteOcupación() {
    int totalReservas = this.reservas.size();
    int totalOcupaciones = this.habitacionesOcupadas.size();
    float ocupacion = (totalOcupaciones / SistemaReserva.TOTAL_HABITACIONES) * 100;

    return "Total reservas: " + totalReservas + "\nHabitaciones Ocupadas: " + totalOcupaciones + "\nOcupación: "
        + ocupacion + "%";

  }

}
