package xadrez;

import java.util.ArrayList;
import java.util.List;

public class Jogada {
    
    private Tabuleiro tab;
    private String codigoJogada;
    private Caminho caminho;
    private Jogador player;

    
    public Jogada(Tabuleiro tabuleiro, String jogada, Jogador p){
        tab = tabuleiro;
        codigoJogada = jogada;
        caminho = new Caminho(codigoJogada, tab);
        player = p;   
    }
    
    // para checar xeque mate
    public Jogada(Tabuleiro tabuleiro, String jogada){
        tab = tabuleiro;
        codigoJogada = jogada;
        caminho = new Caminho(codigoJogada, tab);
        player = null;   
    }
    
    public boolean ehValida(){

        int linhaInicial = codigoJogada.charAt(0)- 48;
        int colunaInicial = codigoJogada.charAt(1)-96;
        int linhaFinal = codigoJogada.charAt(2) - 48;
        int colunaFinal = codigoJogada.charAt(3) - 96;
        
        
        // CHECA SE É PECA DO PLAYER
        boolean corCorreta = false;
  
        if(tab.getPeca(linhaInicial, colunaInicial) != null && ( player == null || tab.getPeca(linhaInicial, colunaInicial).charAt(1) == player.getCor())){
            corCorreta = true;
        }
        
        // SE ESTA LIVRE OU PECA OPONENTE NA POS FINAL
        boolean finalPossivel = true;
        
        if(tab.getPeca(linhaFinal, colunaFinal) != null){
            if(player == null || tab.getPeca(linhaFinal, colunaFinal).charAt(1) == player.getCor()){
                finalPossivel = false;
            }
        }
       
        
        //boas praticas
        Peca pecaPosInicial = tab.getCasa(linhaInicial, colunaInicial).getPecaCasa();
        boolean ehPeao;
        if (pecaPosInicial != null && pecaPosInicial.desenho().charAt(0) == 'P') {
            ehPeao = true;
        }
        else
            ehPeao = false;

        Peca pecaPosFinal = tab.getCasa(linhaFinal, colunaFinal).getPecaCasa();
        boolean vaiComer;
        if (pecaPosFinal != null) {
            vaiComer = true;
            
        }
        else
            vaiComer = false;

        boolean peaoLadinho;
        if (ehPeao && !vaiComer && colunaInicial != colunaFinal) {
            peaoLadinho = false;
        }
        else
            peaoLadinho = true;

        if(codigoJogada.equals("8e8d")){
            System.out.println(tab.noLimite(linhaInicial, colunaInicial));
            System.out.println(tab.noLimite(linhaFinal, colunaFinal));
            System.out.println(corCorreta);
            System.out.println(finalPossivel);
            System.out.println(caminho.estaLivre());
            System.out.println(tab.getCasa(linhaInicial, colunaInicial).getPecaCasa().movimentoValido(linhaInicial, linhaFinal, colunaInicial, colunaFinal));
            System.out.println(peaoLadinho);
        }

        boolean resultado = tab.noLimite(linhaInicial, colunaInicial) && tab.noLimite(linhaFinal, colunaFinal) &&
                corCorreta && finalPossivel && caminho.estaLivre() && tab.getCasa(linhaInicial, colunaInicial).getPecaCasa().movimentoValido(linhaInicial, linhaFinal, colunaInicial, colunaFinal) && peaoLadinho;

        return resultado;
        
    }

    public boolean ehXeque(){

        char corAdversaria;

        if (player.getCor() == 'b')
            corAdversaria = 'p';
        else
            corAdversaria = 'b';

        int linhaRei = 0, colunaRei = 0;



        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (tab.getPeca(i+1, j+1) != null && tab.getPeca(i+1, j+1).equals("R" + corAdversaria)) {
                    linhaRei = i;
                    colunaRei = j;
                }
            }
        }


        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (tab.getPeca(i+1, j+1) != null && tab.getPeca(i+1, j+1).charAt(1) == player.getCor()) {

                    String jogadaString = "" + (char) (i + 49) + (char) (j + 97) +
                            (char) (linhaRei + 49) + (char) (colunaRei + 97);

                    Jogada possivelXeque = new Jogada(tab, jogadaString, player);
                    if (possivelXeque.ehValida()) {
                        System.out.println(jogadaString + " gerou xeque");
                        return true;
                    }
                }
            }
        }
        return false;
    }

    public boolean ehXeque(int linhaRei, int colunaRei){

        char corAdversaria;

        if (player.getCor() == 'b')
            corAdversaria = 'p';
        else
            corAdversaria = 'b';


        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (tab.getPeca(i+1, j+1) != null && tab.getPeca(i+1, j+1).charAt(1) == player.getCor()) {

                    String jogadaString = "" + (char) (i + 49) + (char) (j + 97) +
                            (char) (linhaRei + 48) + (char) (colunaRei + 96);


                    Jogada possivelXeque = new Jogada(tab, jogadaString, player);
                    if (possivelXeque.ehValida()) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    
    public boolean ehXequeMate(){

        // eh xeque?
        if(!ehXeque()){
            return false;
        }

        // ACHA O REI
        char corAdversaria;

        if (player.getCor() == 'b')
            corAdversaria = 'p';
        else
            corAdversaria = 'b';

        int linhaRei = 0, colunaRei = 0;

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (tab.getPeca(i+1, j+1) != null && tab.getPeca(i+1, j+1).equals("R" + corAdversaria)) {
                    linhaRei = i+1;
                    colunaRei = j+1;
                }
            }
        }


        String jogadaString;

        //analisa movimentaçoes do rei


        jogadaString = "" + (char) (linhaRei + 48) + (char) (colunaRei + 96) +
                (char) (linhaRei + 1 + 48) + (char) (colunaRei + 96);


        Jogada escapatoria1 = new Jogada(tab, jogadaString);
        if (linhaRei + 1 < 8 && escapatoria1.ehValida() && !ehXeque(linhaRei + 1, colunaRei)) {
            return false;
        }

        jogadaString = "" + (char) (linhaRei + 48) + (char) (colunaRei + 96) +
                (char) (linhaRei + 1 + 48) + (char) (colunaRei + 1 + 96);
        Jogada escapatoria2 = new Jogada(tab, jogadaString);
        if (linhaRei + 1 < 8 && colunaRei + 1 < 8 && escapatoria2.ehValida() && !ehXeque(linhaRei + 1, colunaRei + 1)) {
            return false;
        }

        jogadaString = "" + (char) (linhaRei + 48) + (char) (colunaRei + 96) +
                (char) (linhaRei + 48) + (char) (colunaRei + 1 + 96);
        Jogada escapatoria3 = new Jogada(tab, jogadaString);
        if (colunaRei + 1 < 8 && escapatoria3.ehValida() && !ehXeque(linhaRei, colunaRei + 1)) {
            return false;
        }

        jogadaString = "" + (char) (linhaRei + 48) + (char) (colunaRei + 96) +
                (char) (linhaRei - 1 + 48) + (char) (colunaRei + 1 + 96);
        Jogada escapatoria4 = new Jogada(tab, jogadaString);


        if (linhaRei - 1 > 0 && colunaRei + 1 < 8 && escapatoria4.ehValida() && !ehXeque(linhaRei - 1, colunaRei + 1)) {
            System.out.println(jogadaString);
            return false;
        }

        jogadaString = "" + (char) (linhaRei + 48) + (char) (colunaRei + 96) +
                (char) (linhaRei - 1 + 48) + (char) (colunaRei + 96);
        Jogada escapatoria5 = new Jogada(tab, jogadaString);
        if (linhaRei - 1 > 0 && escapatoria5.ehValida() && !ehXeque(linhaRei - 1, colunaRei)) {
            return false;
        }
        jogadaString = "" + (char) (linhaRei + 48) + (char) (colunaRei + 96) +
                (char) (linhaRei - 1 + 48) + (char) (colunaRei - 1 + 96);
        Jogada escapatoria6 = new Jogada(tab, jogadaString);
        if (linhaRei - 1 > 0 && colunaRei - 1 > 0 && escapatoria6.ehValida() && !ehXeque(linhaRei - 1, colunaRei - 1)) {
            return false;
        }
        jogadaString = "" + (char) (linhaRei + 48) + (char) (colunaRei + 96) +
                (char) (linhaRei + 48) + (char) (colunaRei - 1 + 96);
        Jogada escapatoria7 = new Jogada(tab, jogadaString);
        if (colunaRei - 1 > 0 && escapatoria7.ehValida() && !ehXeque(linhaRei, colunaRei - 1)) {
            return false;
        }
        jogadaString = "" + (char) (linhaRei + 48) + (char) (colunaRei + 96) +
                (char) (linhaRei + 1 + 48) + (char) (colunaRei - 1 + 96);
        Jogada escapatoria8 = new Jogada(tab, jogadaString);
        if (linhaRei + 1 < 8 && colunaRei - 1 > 0 && escapatoria8.ehValida() && !ehXeque(linhaRei + 1, colunaRei - 1)) {
            return false;
        }
        
        // peca heroi?
        
        int [][] pecasAtacandoRei = new int[16][2];
        int numPecasAtacando = 0;
        
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (tab.getPeca(i+1, j+1) != null && tab.getPeca(i+1, j+1).charAt(1) == player.getCor()){
                    //ver se peça ta atacando o rei inimigo
                    String jogadaAtaqueRei = "" + (char) (i + 49) + (char) (j + 97) +
                            (char) (linhaRei -1 + 49) + (char) (colunaRei-1 + 97);
                    
                    Jogada ataque = new Jogada(tab, jogadaAtaqueRei, player);

                    if(ataque.ehValida()){
                        pecasAtacandoRei[numPecasAtacando][0] = i+1;
                        pecasAtacandoRei[numPecasAtacando][1] = j+1;
                        numPecasAtacando++;
                    }
                }
            }
        }

        //String dos caminhos das peças que estão atacando o Rei
        String caminhosPecasAtacando = "";
        System.out.println(pecasAtacandoRei[0][0] + " " + pecasAtacandoRei[0][1]);
        for (int i = 0; i < numPecasAtacando; i++) {
            caminhosPecasAtacando += tab.getCaminhoPeca(pecasAtacandoRei[i][0], linhaRei, pecasAtacandoRei[i][1], colunaRei);
        }

        //System.out.println("oi" + caminhosPecasAtacando);

        ArrayList<String> casasEmComum = new ArrayList<>();
        if(numPecasAtacando > 1){
            casasEmComum = getCasaComumCaminhos(caminhosPecasAtacando);
        }
        else{
            casasEmComum.add(caminhosPecasAtacando);
        }

        if (casasEmComum.size() == 0) {
            return true;
        }


        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (tab.getPeca(i+1, j+1) != null && tab.getPeca(i+1, j+1).charAt(1) == corAdversaria){
                    
                    for(String casa : casasEmComum){
                        String codigoJogadaPecaHeroi = "" + (char) (i + 49) + (char) (j + 97) +
                            casa.charAt(0) + casa.charAt(1);

                        Jogador adversario = new Jogador("Bob", new String(String.valueOf(corAdversaria)), null);
                        Jogada jogadaPecaHeroi = new Jogada(tab, codigoJogadaPecaHeroi, adversario);
                        System.out.println(codigoJogadaPecaHeroi + " - " + jogadaPecaHeroi.ehValida());

                        if (jogadaPecaHeroi.ehValida()) {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
        
    }

    public static String[] splitString(String str, int chunkSize) {
        int length = str.length();
        int numChunks = (int) Math.ceil((double) length / chunkSize); // Número de pedaços
        String[] result = new String[numChunks];

        for (int i = 0; i < numChunks; i++) {
            int start = i * chunkSize;
            int end = Math.min(length, start + chunkSize);
            result[i] = str.substring(start, end);
        }

        return result;
    }

    private ArrayList<String> getCasaComumCaminhos(String caminhosPecasAtacando) {
        String[] caminhosSplit = splitString(caminhosPecasAtacando, 2);
        ArrayList<String> casasEmComum = new ArrayList<>();

        for (int i = 0; i < caminhosSplit.length; i++) {
            for (int j = i + 1; j < caminhosSplit.length; j++) {
                if (caminhosSplit[i].equals(caminhosSplit[j]) && !casasEmComum.contains(caminhosSplit[i])) {
                    casasEmComum.add(caminhosSplit[i]);
                }
            }
        }

        return casasEmComum;
    }

}
