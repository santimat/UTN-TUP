package practica1;

public class BankAccount {
    private String owner;
    private String accNumber;
    private double balance;
    private boolean active;
    
    public BankAccount(String owner, String accNumber, double balance, boolean active){
        this.owner = owner;
        this.accNumber = accNumber;
        this.balance = balance;
        this.active = active;
    }

    public BankAccount(String owner,String accNumber){
        this(owner, accNumber, 0,true);
    }
    public BankAccount(String owner){
        this(owner,"not assigned", 0,true);
    }

    public String getOwner() {
        return owner;
    }

    public void setOwner(String owner) {
        this.owner = owner;
    }

    public String getAccountNumber() {
        return accNumber;
    }

    public void setAccountNumber(String accNumber) {
        this.accNumber = accNumber;
    }

    public double getBalance() {
        return balance;
    }

    public void setBalance(double balance) {
        this.balance = balance;
    }

    public boolean isActive() {
        return active;
    }

    public void setActive(boolean active) {
        this.active = active;
    }

    public void deposit(double amount){
        if (this.active && amount > 0) {
            this.balance += amount;
        }
    }

    public void withdraw(double amount){
        if (this.balance >= amount && this.active) {
            this.balance -= amount;
        }
    }

    public void activateAcc(){
        this.active = true;
    }

    public void desactivateAcc(){
        this.active = false;
    }

    public boolean isVipAcc(){
        return this.balance > 10000 ? true : false;
    }

    public String getStatusAcc(){
        String resume = "The " + this.owner + " account is";
        if (this.active) {
            resume += "activated";
        }else{
            resume += "disactivated";
        }

        if (this.isVipAcc()) {
            resume += "and is a premium account";
        }else{
            resume += "and is not a premium account";
        }
        return resume;
    }

    @Override
    public String toString() {
        return "BankAccount{\n  owner: " + this.owner + "\n  account number: " + this.accNumber + "\n  balance: " + this.balance + "\n  active: " + this.active +"\n}\n";  
    }
}
