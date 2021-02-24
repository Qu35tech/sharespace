/*
*   Classe Para testar a função maximoNumeros da classe Classe1.
*
*   Autor: Qu35tech
*/

import java.util.Scanner;

public class Exercicio2 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Classe1 c = new Classe1();

        System.out.println("Determinar o máximo entre dois números");
        System.out.print("Insira o primeiro número >> ");
        int primN = input.nextInt();
        System.out.print("Insira o segundo número >> ");
        int segN = input.nextInt();
        int res = c.maximoNumeros(primN, segN);
        System.out.println("Maximo entre os dois números: " + res);
    }
}
