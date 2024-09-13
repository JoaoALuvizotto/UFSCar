package xadrez;

public class Rei extends Peca{
    
    public Rei(String color){
        super(color);
    }


    public String desenho(){
        if (this.cor.equals("Preto"))
            return "Rp";
        else
            return "Rb";
    }
    
    @Override
    public boolean movimentoValido(int linhaO, int linhaD, int colunaO, int colunaD){
        boolean res = false;
        if(linhaD == linhaO && colunaD == colunaO){
            res = false;
        }
        else if((colunaD == colunaO + 1 || colunaD == colunaO - 1 || colunaD == colunaO) && (linhaD == linhaO + 1 || linhaD == linhaO - 1 || linhaD == linhaO)){
            res = true;
        }
        return res;
    }

    @Override
    public String caminho(int linhaO, int linhaD, int colunaO, int colunaD){
        if(!movimentoValido(linhaO, linhaD, colunaO, colunaD)) return "";
        
        char colO = (char)(96 + colunaO);
        char colD = (char)(96 + colunaD);
        return ""+linhaO+colO+linhaD+colD;
    }
}
