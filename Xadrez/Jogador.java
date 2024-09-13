package xadrez;

import java.util.Scanner;

public class Jogador {
    private Peca pecas[];
    private Peca pecasCapturadas[];
    private final String nome;
    private final String cor;
    private int ultimo;

    public Jogador(String nome, String color, Peca pecas[])
    {
        this.nome = nome;
        this.cor = color;
        this.pecasCapturadas = new Peca[16];
        this.pecas = pecas;
        this.ultimo = 0;
        /*0-7 - peoes
            8/9 - torres
            10/11 - cavalos
            12/13 - bispos
            14 - dama
            15 - rei
        */

    }

    //Cada jogada tem a linha e coluna da casa inicial da jogada e a linha e coluna da casa final, sem qualquer separação. Por exemplo:
    //1a3b
    //4c2h
    //3g7g

    public String informaJogada() {
        try (Scanner scanner = new Scanner(System.in)) {
            System.out.println("Informe a jogada desejada: (linhaInicial,colunaInicial,linhaFinal,colunaFinal)");
            String jogada = scanner.nextLine();
            return jogada;
        }
    }

    public String pecasCapturadas() {
        //Peças que o jogador capturou

        String p = "";
        for(int i = 0; i < 16; i++)
        {
            if(pecasCapturadas[i] == null){
                break;
            }

            p += pecasCapturadas[i].desenho();
            p += " ";

            


        }
        return p;
    }

    public void adicionaPecasCapturadas(Peca p){
        pecasCapturadas[ultimo++] = p;
    }

    public char getCor(){
        return cor.charAt(0);
    }

    public String getNome(){
        return nome;
    }


}
