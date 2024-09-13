package xadrez;

public class Peao extends Peca {
    
    public Peao(String cor) {
        super(cor);
    }

    @Override
    public String desenho() {
        if (this.cor.equals("Preto"))
            return "Pp";
        else
            return "Pb";
    }
    
    @Override
    public boolean movimentoValido(int linhaO, int linhaD, int colunaO, int colunaD) {
        boolean res = false;
        if(this.cor.equals("Preto"))
        {
            //primeiro movimento de 2 casas
            if (linhaO == 7 && linhaD == linhaO - 2)
                res = true;
        
            //movimento comum
            if(linhaD == linhaO - 1 && colunaD == colunaO)
                res = true;

            //capturar peca
            if(linhaD == linhaO - 1 && (colunaD == colunaO + 1 || colunaD == colunaO - 1))
                res = true; // MUDAR PARA TRUE DEPOIS
        }

        else
        {
            //primeiro movimento de 2 casas
            if (linhaO == 2 && linhaD == linhaO + 2)
                res = true;
        
            //movimento comum
            if(linhaD == linhaO + 1 && colunaD == colunaO)
                res = true;

            //capturar peca
            if(linhaD == linhaO + 1 && (colunaD == colunaO + 1 || colunaD == colunaO - 1))
                res = true; // MUDAR PARA TRUE DEPOIS
        }

        
        return res;
    }

    @Override
    public String caminho(int linhaO, int linhaD, int colunaO, int colunaD) {
        if(!this.movimentoValido(linhaO, linhaD, colunaO, colunaD))
            return "";

        char colO = (char)(96 + colunaO);
        char colD = (char)(96 + colunaD);

        if(linhaD == linhaO + 2)
        {
            int linhaI =+ 1;
            char colI = (char)(97 + colunaO);
            return "" + linhaO + colO + linhaI + colI + linhaD + colD;
        }

        else
            return "" + linhaO + colO + linhaD + colD;
    }
}
