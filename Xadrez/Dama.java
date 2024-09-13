package xadrez;

import java.lang.Math;

public class Dama extends Peca{
    
    public Dama(String color){
        super(color);
    }


    public String desenho(){
        if (this.cor.equals("Preto"))
            return "Dp";
        else
            return "Db";
    }
    
    @Override
    public boolean movimentoValido(int linhaO, int linhaD, int colunaO, int colunaD){
        boolean res = false;
        
        int alteracaoLinha = linhaD - linhaO;
        int alteracaoColuna = colunaD - colunaO;

        if ((alteracaoLinha == 0 && alteracaoColuna != 0) || 
            (alteracaoLinha != 0 && alteracaoColuna == 0) || 
            (Math.abs(colunaD - colunaO) == Math.abs(linhaD - linhaO))){
                res = true;
            }


        return res;
    }

    @Override
    public String caminho(int linhaO, int linhaD, int colunaO, int colunaD){
        //clean code em pratica(nao toque, aqui jaz a perfeição)
        if(!movimentoValido(linhaO, linhaD, colunaO, colunaD)) return "";

        int alteracaoLinha = linhaD - linhaO;
        int alteracaoColuna = colunaD - colunaO;
        if((alteracaoLinha == 0 && alteracaoColuna != 0) || (alteracaoLinha != 0 && alteracaoColuna == 0)){
            // cola caminho da torre

            boolean colunaMudou = alteracaoColuna != 0 ? true : false;
            boolean linhaMudou = alteracaoLinha != 0 ? true : false;

            int numeroMovimentos = alteracaoLinha != 0 ? alteracaoLinha : alteracaoColuna;

            String casasMovimento = "";  //+ (char) (linhaO + 96) + (char) (colunaO + 96);

            int i = 0;
            while (numeroMovimentos != 0) {
                if (linhaMudou) {
                    casasMovimento += "" + (linhaO + i) + (char) (colunaO + 96);
                }
                else if(colunaMudou){
                    casasMovimento += "" + (linhaO) + (char) (colunaO + i + 96);
                }

                if (numeroMovimentos < 0) {
                    numeroMovimentos++;
                    i--;
                }
                else{
                    numeroMovimentos--;
                    i++;
                }
            }

            if (linhaMudou) {
                casasMovimento += "" + (linhaO + i) + (char) (colunaO + 96);
            }
            else if(colunaMudou){
                casasMovimento += "" + (linhaO) + (char) (colunaO + i + 96);
            }

            return casasMovimento;
        } else{
            // cola caminho do bispo
            String casasMovimento = "";
            int i = 0;
            
            while (alteracaoColuna != 0) {
                casasMovimento += "" + (linhaO + i) + (char) ((colunaO + i) + 96);

                if(alteracaoColuna < 0)
                {
                    alteracaoColuna++;
                    i--;
                }
                else
                {
                    alteracaoColuna--;
                    i++;
                }
            }

            casasMovimento += "" + (linhaO + i) + (char) ((colunaO + i) + 96);

            return casasMovimento;
        }
    }
}
