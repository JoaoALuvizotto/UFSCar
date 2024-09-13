package xadrez;

public class Cavalo extends Peca{

    public Cavalo(String color){
        super(color);
    }

    public String desenho(){
        if(this.cor.equals("Preto"))
            return "Cp";
        else
            return "Cb";

    }
    
    @Override
    public boolean movimentoValido(int linhaO, int linhaD, int colunaO, int colunaD){
        int col = Math.abs(colunaD - colunaO);
        int lin = Math.abs(linhaD - linhaO);

        if((col == 1 && lin == 2) || (col == 2 && lin == 1))
            return true;

        return false;
    }

    @Override
    public String caminho(int linhaO, int linhaD, int colunaO, int colunaD){
        if(!movimentoValido(linhaO, linhaD, colunaO, colunaD)) return "";

        String casasMovimento = "" + linhaO + (char)(colunaO + 96);

        int col = colunaD - colunaO;
        int lin = linhaD - linhaO;

        if(col == 1 && lin == 2){
            casasMovimento += linhaO + (char)(colunaO + 1 ) + (linhaO + 1) + (char)(colunaO + 1);
        }

        else if(col == 1 && lin == -2){
            casasMovimento += linhaO + (char)(colunaO + 97) + (linhaO - 1) + (char)(colunaO + 97);
        }

        else if(col == -1 && lin == 2){
            casasMovimento += linhaO + (char)(colunaO + 95) + (linhaO + 1) + (char)(colunaO + 95);
        }

        else if(col == -1 && lin == -2){
            casasMovimento += linhaO + (char)(colunaO + 95) + (linhaO - 1) + (char)(colunaO + 95);
        }

        else if(col == 2 && lin == 1){
            casasMovimento += (linhaO + 1) + (char)(colunaO + 96) + (linhaO + 1) + (char)(colunaO + 97);
        }

        else if(col == -2 && lin == 1){
            casasMovimento += (linhaO + 1) + (char)(colunaO + 96) + (linhaO + 1) + (char)(colunaO + 95);
        }

        else if(col == 2 && lin == -1){
            casasMovimento += (linhaO - 1) + (char)(colunaO + 96) + (linhaO - 1) + (char)(colunaO + 97);
        }

        else if(col == -2 && lin == -1){
            casasMovimento += (linhaO - 1) + (char)(colunaO + 96) + (linhaO - 1) + (char)(colunaO + 95);
        }

        casasMovimento += linhaD + (char)(colunaD + 96);

        return casasMovimento;
    }
    
}

