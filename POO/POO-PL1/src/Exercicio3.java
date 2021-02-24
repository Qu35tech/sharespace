/*
*   Classe Para testar a função criaDescricaoConta da classe Classe1.
*
*   Autor: Qu35tech
*/

import java.util.Scanner;

public class Exercicio3 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Classe1 c = new Classe1();

        System.out.println("Criação de descrição da conta");
        System.out.print("Insira o nome >> ");
        String nome = input.nextLine();
        System.out.print("Insira o saldo >> ");
        int saldo = input.nextInt();
        c.criaDescricaoConta(nome, saldo);
    }
}
