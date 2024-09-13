package xadrez;

import java.lang.Math;

public class Bispo extends Peca{

    public Bispo(String cor)
    {
        super(cor);
    }
    
    public String desenho(){
        if (this.cor.equals("Preto")) {
            return "Bp";
        }
        else
            return "Bb";
    }

    public boolean movimentoValido(int linhaO, int linhaD, int colunaO, int colunaD)
    {
        if(Math.abs(colunaD - colunaO) == Math.abs(linhaD - linhaO))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    @Override
    public String caminho(int linhaO, int linhaD, int colunaO, int colunaD)
    {
        if(!this.movimentoValido(linhaO, linhaD, colunaO, colunaD))
            return "";

        int tamanhoMovimento = colunaD - colunaO;
        String casasMovimento = "";
        int i = 0;

        while (tamanhoMovimento != 0) {
            casasMovimento += "" + (linhaO + i) + (char) ((colunaO + i) + 96);

            if(tamanhoMovimento < 0)
            {
                tamanhoMovimento++;
                i--;
            }
            else
            {
                tamanhoMovimento--;
                i++;
            }
        }

        casasMovimento += "" + (linhaO + i) + (char) ((colunaO + i) + 96);

        return casasMovimento;
    }

}
