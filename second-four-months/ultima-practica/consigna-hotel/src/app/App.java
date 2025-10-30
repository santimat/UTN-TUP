package app;

import java.util.Scanner;

public class App {

	private static Scanner scanner = new Scanner(System.in);

	public static void main(String[] args) throws Exception {
	}

	public void crearMenu() {

		int option = 0;
		do {
			System.out.println("==== SISTEMA DE RESERVAS HOTEL ====");
			System.out.println("1. Agregar una reserva");
			System.out.println("2. Confirmar reserva");
			System.out.println("3. Hacer check in");
			System.out.println("4. Hacer check out");
			System.out.println("5. Cancelar reserva");
			System.out.println("6. Buscar reserva por codigo");
			System.out.println("7. Obtener reservas por estado");
			System.out.println("8. Ver reporte de ocupación");
			System.out.println("9. Finalizar programa");
		} while (option != 9);
	}
}
