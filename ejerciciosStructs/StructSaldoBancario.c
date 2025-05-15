// Define una estructura llamada CuentaBancaria con los miembros: titular (nombre del
// cliente), numeroCuenta y saldo. Escribe una función que reciba una variable de tipo
// CuentaBancaria por referencia y le permita depositar una cantidad de dinero,
// modificando su saldo. Luego, muestra la información actualizada de la cuenta.
// Pista: Declara la función como void depositar(struct CuentaBancaria *cuenta, float
// cantidad);

#include <stdio.h>

typedef struct
{
    char titular[40];
    int accId;
    float salary;
} BankAcc;

void depositar(BankAcc *acc, float amount)
{
    acc->salary += amount;
}
int main()
{
    BankAcc acc = {"santino", 12, 200};
    float amount = 0;
    printf("Ingrese un monto a depositar\n");
    scanf("%f", &amount);
    depositar(&acc, amount);

    printf("Saldo actual %.2f", acc.salary);
    return 0;
}