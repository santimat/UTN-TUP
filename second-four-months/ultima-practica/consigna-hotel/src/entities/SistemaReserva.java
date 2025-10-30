package entities;

import java.util.ArrayList;
import java.util.HashMap;

import enums.EstadoReserva;
import exceptions.ReservaNoEncotradaException;

public class SistemaReserva {

  private final static int TOTAL_HABITACIONES = 50;
  // toma como key el codigo de reserva
  private HashMap<String, Reserva> reservas;
  // clave numero de habitacion, valor codigo de reserva
  private HashMap<Integer, String> habitacionesOcupadas;

  public SistemaReserva() {
    this.reservas = new HashMap<>();
    this.habitacionesOcupadas = new HashMap<>();
  }

  private void noExisteReserva(String codigoReserva) throws ReservaNoEncotradaException {
    if (!reservas.containsKey(codigoReserva)) {
      throw new ReservaNoEncotradaException("No se encontró la reserva con el codigo: " + codigoReserva);
    }
  }

  public void agregarReserva(Reserva reserva) throws IllegalStateException {
    if (habitacionesOcupadas.containsKey(reserva.getNumeroHabitacion())) {
      throw new IllegalStateException("La habitación " + reserva.getNumeroHabitacion() + " ya está ocupada");
    }

    reservas.put(reserva.getCodigoReserva(), reserva);
    habitacionesOcupadas.put(reserva.getNumeroHabitacion(), reserva.getCodigoReserva());
  }

  public void confirmarReserva(String codigoReserva) throws ReservaNoEncotradaException {
    noExisteReserva(codigoReserva);
    reservas.get(codigoReserva).setEstado(EstadoReserva.CONFIRMADA);
  }

  public void hacerCheckIn(String codigoReserva) throws ReservaNoEncotradaException {
    noExisteReserva(codigoReserva);
    reservas.get(codigoReserva).setEstado(EstadoReserva.CHECK_IN);
  }

  public void hacerCheckOut(String codigoReserva) throws ReservaNoEncotradaException {
    noExisteReserva(codigoReserva);
    reservas.get(codigoReserva).setEstado(EstadoReserva.CHECK_OUT);
    habitacionesOcupadas.remove(reservas.get(codigoReserva).getNumeroHabitacion());
  }

  public void cancelarReserva(String codigoReserva) throws ReservaNoEncotradaException {
    noExisteReserva(codigoReserva);
    reservas.get(codigoReserva).setEstado(EstadoReserva.CANCELADA);
    habitacionesOcupadas.remove(reservas.get(codigoReserva).getNumeroHabitacion());
  }

  public Reserva buscarPorCodigo(String codigo) throws ReservaNoEncotradaException {
    noExisteReserva(codigo);
    return reservas.get(codigo);
  }
}
