/*
*   Classe Para testar a função celsiusParaFarenheit da classe Classe1.
*
*   Autor: Qu35tech
*/

import java.util.Scanner;

public class Exercicio1 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Classe1 c = new Classe1();

        System.out.println("Conversão de temperatura em Celsius para Farenheit");
        System.out.print("Insira a temperatura pretendida >> ");
        double tempC = input.nextDouble();
        double tempF = c.celsiusParaFarenheit(tempC);
        System.out.println("Temperatura em Farenheit: " + tempF + "Fº");
    }
}
