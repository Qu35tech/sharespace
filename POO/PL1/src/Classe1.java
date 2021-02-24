import java.time.LocalTime;
import java.util.Scanner;

public class Classe1 {
    public double celsiusParaFarenheit(double graus) {
        return 1.8*graus + 32;
    }

    public int maximoNumeros(int a, int b) {
        if (a>=b) return a;
        else return b;
    }

    public void criaDescricaoConta(String nome, int saldo) {
        System.out.println("------------------------------");
        System.out.println("Extrato da conta nº 1234567890");
        System.out.println("Nome: " + nome);
        System.out.println("Saldo: " + saldo + "$");
        System.out.println("------------------------------");
    }

    public double eurosParaLibras(double valor, double taxaConversao) {
        return valor*taxaConversao;
    }

    public void minimoeMedia(int a, int b){
        System.out.println("Ordem decrescente dos numeros dados:");
        if (a>=b) {System.out.println(a);System.out.println(b);}
        else {System.out.println(a);System.out.println(b);}
        System.out.println("Média dos numeros dados: " + (a+b)/2);
    }

    public long factorial(int num) {
        long res = num;
        while (num>1) {
            num--;
            res *= num;
        }
        return res;
    }

    public long tempoGasto() {
        long start = System.nanoTime();
        long trash = factorial(5000);
        return System.nanoTime() - start;
    }
}
