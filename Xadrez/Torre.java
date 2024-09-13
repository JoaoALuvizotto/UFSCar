package xadrez;

public class Torre extends Peca {
    
    public Torre(String cor){
        super(cor);
    }

    @Override
    public String desenho(){
        if (this.cor.equals("Preto")) {
            return "Tp";
        }
        else{
            return "Tb";
        }
    }
    
    @Override
    public boolean movimentoValido(int linhaO, int linhaD, int colunaO, int colunaD) {
        int alteracaoLinha = linhaD - linhaO;
        int alteracaoColuna = colunaD - colunaO;

        if (alteracaoLinha == 0 && alteracaoColuna != 0) {
            return true;
        }
        else if (alteracaoLinha != 0 && alteracaoColuna == 0) {
            return true;
        }
        else{
            return false;
        }
    }

    @Override
    public String caminho(int linhaO, int linhaD, int colunaO, int colunaD) {
        if (!this.movimentoValido(linhaO, linhaD, colunaO, colunaD)) {
            return "";
        }

        int alteracaoLinha = linhaD - linhaO;
        int alteracaoColuna = colunaD - colunaO;

        boolean colunaMudou = alteracaoColuna != 0 ? true : false;
        boolean linhaMudou = alteracaoLinha != 0 ? true : false;

        int numeroMovimentos = alteracaoLinha != 0 ? alteracaoLinha : alteracaoColuna;

        String casasMovimento = "";

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
    }

}
