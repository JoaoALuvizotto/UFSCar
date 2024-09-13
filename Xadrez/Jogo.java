package xadrez;

import java.util.Scanner;
import java.util.ArrayList;

public class Jogo {
    
    private Tabuleiro tab;
    private Jogador player1;
    private Jogador player2;
    private Peca pecas1[];
    private Peca pecas2[];
    private int vezJogador;
    private int situacao; // 1 - inicio, 2 - xeque, 3 - xequeMate, 4 - comeu rei
    private ArrayList<String> listaJogadas;

    public Jogo(String nome1, String nome2){
        listaJogadas = new ArrayList<>();
        // tabuleiro
        this.tab = new Tabuleiro();
        
        // pecas
        this.pecas1 = new Peca[16];
        this.pecas2 = new Peca[16];
        
        /*0-7 - peoes
            8/9 - torres
            10/11 - cavalos
            12/13 - bispos
            14 - dama
            15 - rei
        */
        // brancas
        inicializarVetorPecas("b", pecas1);

        // pretas
        inicializarVetorPecas("p", pecas2);
        
        //jogadores
        this.player1 = new Jogador(nome1, "b", pecas1);
        this.player2 = new Jogador(nome2, "p", pecas2);

        vezJogador = 1;
        situacao = 1;
    }
    
    public boolean jogadaValida(String jogadaAtual){

        Jogada jogada = new Jogada(tab, jogadaAtual, vezJogador == 1 ? player1 : player2);
        
        return jogada.ehValida();
    }

    public void realizarJogada(String jogadaAtual){ // 1a3a
        
        if (!jogadaValida(jogadaAtual)) {
            System.out.println("Jogada invalida!");
        }

        int linhaInicial = jogadaAtual.charAt(0)- 48;
        int colunaInicial = jogadaAtual.charAt(1)-96;
        int linhaFinal = jogadaAtual.charAt(2) - 48;
        int colunaFinal = jogadaAtual.charAt(3) - 96;

        // VER SE COMEU PECA
        Peca pecaPosFinal = tab.getCasa(linhaFinal, colunaFinal).getPecaCasa();
        boolean vaiComer;
        if (pecaPosFinal != null) {
            vaiComer = true;
            
        }
        else
            vaiComer = false;

        if( vaiComer && jogadaValida(jogadaAtual) ){
        
            if(vezJogador == 1)
                player1.adicionaPecasCapturadas(pecaPosFinal);
            else
                player2.adicionaPecasCapturadas(pecaPosFinal);
        }

        if (tab.getPeca(linhaFinal, colunaFinal) != null && tab.getPeca(linhaFinal, colunaFinal).charAt(0) == 'R') {
            situacao = 4;
        }

        tab.setPecaCasa(linhaFinal, colunaFinal, tab.getPecaCasa(linhaInicial, colunaInicial));
        tab.setPecaCasa(linhaInicial, colunaInicial, null);

        listaJogadas.add(jogadaAtual);
    }

    String registroJogo(){ 
        return "";
    }
    
    private void inicializarVetorPecas(String cor, Peca[] pecas){
        for(int i = 0; i < 8; i++)
            pecas[i] = new Peao(cor);
            
        pecas[8] = new Torre(cor);
        pecas[9] = new Torre(cor);
        pecas[10] = new Cavalo(cor);
        pecas[11] = new Cavalo(cor);
        pecas[12] = new Bispo(cor);
        pecas[13] = new Bispo(cor);
        pecas[14] = new Dama(cor);
        pecas[15] = new Rei(cor);
    }

    private boolean noIntervalo(String jogada){
        if(jogada.length() < 4)
            return false;

        int linhaInicial = jogada.charAt(0)-48;
        int colunaInicial = jogada.charAt(1)-96;
        int linhaFinal = jogada.charAt(2) - 48;
        int colunaFinal = jogada.charAt(3) - 96;
        
        if(linhaInicial < 1 || linhaInicial > 8){
            return false;
        }
        if(colunaInicial < 1 || colunaInicial > 8){
            return false;
        }
        if(linhaFinal < 1 || linhaFinal > 8){
            return false;
        }
        if(colunaFinal < 1 || colunaFinal > 8){
            return false;
        }

        return true;
    }

    public void jogar(Scanner sc){
        int ganhador = 1;
        boolean saiu = false;

        while (situacao != 3 && situacao != 4) {
            
            System.out.println("\n");
            System.out.println("Peças brancas capturadas: " + player2.pecasCapturadas() + "\n");
            System.out.println(tab.desenho());
            System.out.println("Peças pretas capturadas: " + player1.pecasCapturadas() + "\n");

            String jogadaInformada;
            do {
                System.out.println((vezJogador == 1 ? player1.getNome() : player2.getNome()) + ": informe uma jogada no formato linhaInicial, colunaInicial, linhaFinal, colunaFinal");
                jogadaInformada = sc.nextLine();

                // break do jogo
                if(jogadaInformada.equals("0000")){
                    saiu = true;
                    break;
                }

                if (!noIntervalo(jogadaInformada)) {
                    System.out.println("Formato de jogada inválido!");
                }
            } while (!noIntervalo(jogadaInformada));

            if (saiu) {
                break;
            }

            Jogada jogada = new Jogada(tab, jogadaInformada, vezJogador == 1 ? player1 : player2);

            if (jogada.ehValida()) {
                
                realizarJogada(jogadaInformada);
                
                if (jogada.ehXeque()) {
                    System.out.println("Xeque detectado");
                    situacao = 2;
                }
                if (jogada.ehXequeMate()) {
                    ganhador = vezJogador;
                    situacao = 3;
                }
                if(situacao == 4){
                    ganhador = vezJogador;
                }

                if (vezJogador == 1)
                    vezJogador = 2;
                else
                    vezJogador = 1;

            }
            else
                System.out.println("Movimento proibido!");
        }


        if (situacao == 3 || situacao == 4) {
            String nomeGanhador = ganhador == 1 ? player1.getNome() : player2.getNome();
            System.out.println("Jogador " + nomeGanhador + " venceu!!");
        }
        else{
            System.out.println("Salvando jogo...");
        }
        
    }

    public String getJogadas(){
        String jogadas = "";

        for(String jogada : listaJogadas){
            jogadas += jogada;
            jogadas += "\n";
        }

        return jogadas;
    }

    public void carregar(String linha){
        
        realizarJogada(linha);
        if (vezJogador == 1)
            vezJogador = 2;
        else
            vezJogador = 1;

        listaJogadas.add(linha);
    }

    public String getNomePlayer1(){
        return player1.getNome();
    }

    public String getNomePlayer2(){
        return player2.getNome();
    }
}




